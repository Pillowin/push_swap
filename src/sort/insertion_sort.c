/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 16:12:14 by agautier          #+#    #+#             */
/*   Updated: 2021/09/21 18:59:05 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Returns fastest rotation to sort list.
*/
static t_op	get_fastest_op(t_list *list, t_node *elem)
{
	uint16_t	pos;
	t_node		*curr;

	curr = list->begin;
	pos = 0;
	while (elem && curr && elem && is_great(elem, curr))
	{
		pos += 1;
		curr = curr->next;
	}
	if (list->begin == curr && pos > list->size >> 1)
		pos = list->size - pos;
	if (pos > list->size >> 1)
		return (rrb);
	return (rb);
}


/*
**	
*/
static t_bool	insertion_sort(t_ps *ps, uint8_t pivot_intervall)
{
	t_list		*stack_a;
	t_list		*stack_b;
	static uint32_t	interesting_value = 0;
	t_op		op;

	fprintf(stderr, "insertion_sort\n");
	stack_a = ps->a;
	stack_b = ps->b;

	fprintf(stderr, "stack_a\n");
	list_print(stack_a);
	fprintf(stderr, "\nstack_b\n");
	list_print(stack_b);

//	interesting_value = *(uint32_t *)stack_a->end->data + 1;
//	if (pivot_intervall <= 2 && *(uint32_t *)stack_a->end->data != 1)	// TODO: sur ?
//	{
//		fprintf(stderr, "\t\t\t\t=====HERE\n");
//		interesting_value = 1;
//	}
	(void)pivot_intervall;
	interesting_value += 1;
	fprintf(stderr, "interesting_value = %d\n", interesting_value);

	if (is_in_a(ps, interesting_value))
	{
		while (*(uint32_t *)stack_a->begin->data != interesting_value)
		{
			if (!pb(ps))
				return (FALSE);
		}

		if (!ra(ps))
			return (FALSE);
	}
	else
	{
		op = get_fastest_op(stack_b, node_find(stack_b, interesting_value));
		while (*(uint32_t *)stack_b->begin->data != interesting_value)
		{
			if (!op(ps))
				return (FALSE);
		}
		if (!pa(ps))
			return (FALSE);
		if (!ra(ps))
			return (FALSE);
	}
	while (*(uint32_t *)stack_a->begin->data == *(uint32_t *)stack_a->end->data + 1
		|| (stack_b->size && *(uint32_t *)stack_b->begin->data == *(uint32_t *)stack_a->end->data + 1))
	{
		if (stack_b->size && *(uint32_t *)stack_b->begin->data == *(uint32_t *)stack_a->end->data + 1)
			if (!pa(ps))
				return (FALSE);
		if (!ra(ps))
			return (FALSE);
		interesting_value += 1;
	}
	fprintf(stderr, "stack_a\n");
	list_print(stack_a);
	fprintf(stderr, "\nstack_b\n");
	list_print(stack_b);
	return (TRUE);
}

/*
**	On `a`, rotate values greater than median or pb values lesser.
**	Median becomes a pivot.
*/
static t_bool	pb_small(t_ps *ps, uint8_t pivot_intervall)
{
	t_list		*stack_a;
	t_list		*stack_b;
	t_node		*curr;
	t_node		*end;
	uint32_t	median;
	uint8_t		i;

	stack_a = ps->a;
	stack_b = ps->b;
	end = stack_a->end;

	fprintf(stderr, "BEGIN ADD_PIVOT->PB_SMALL\n");
	fprintf(stderr, "pivot_intervall = %d\n\n", pivot_intervall);

	fprintf(stderr, "stack_a\n");
	list_print(stack_a);
	fprintf(stderr, "\nstack_b\n");
	list_print(stack_b);

//	median = (stack_a->size >> 1) + ((stack_a->size - pivot_intervall + 1) >> 1);
//	median = ((stack_a->size + stack_b->size) >> 1) + ((pivot_intervall + 1) >> 1);
	median = *(uint32_t *)stack_a->end->data + ((pivot_intervall + 1) >> 1);
	fprintf(stderr, "median in a = %u\n", median);

	curr = stack_a->begin;
	i = pivot_intervall;
	while (curr && i)
	{
		if (*(uint32_t *)curr->data <= median)
			if (!pb(ps))
				return (FALSE);
		if (stack_b->size > 1 && *(uint32_t *)stack_b->begin->data == median)
			if (!rb(ps))
				return (FALSE);
		if (*(uint32_t *)curr->data > median)
			if (!ra(ps))
				return (FALSE);
		curr = stack_a->begin;
		i -= 1;
	}
	
	//TODO: push end of A at the begining of A
	while (stack_a->end != end)
	{
		if (!rra(ps))
			return (FALSE);
	}

	//TODO: push pivot (end of B) at begining of A
	if (!rrb(ps))
		return (FALSE);
	if (!pa(ps))
		return (FALSE);

	//TODO: - new pivots in B
	fprintf(stderr, "stack_a\n");
	list_print(stack_a);
	fprintf(stderr, "\nstack_b\n");
	list_print(stack_b);
	fprintf(stderr, "pivot_intervall = %d\n", pivot_intervall);
	if (stack_b->size < MAGIC)
	{
		if (!insertion_sort(ps, pivot_intervall))
			return (FALSE);
	}
	else
	{
		while (stack_b->size > MAGIC)
		{
	//		median = pivot_intervall + ((stack_b->size + 1) >> 1);
			// func find_min_in_intervall
			//median += ((stack_b->size + 1) >> 1);
			median = *(uint32_t *)find_min(stack_b)->data + ((stack_b->size + 1) >> 1);
			fprintf(stderr, "median in b = %u\n", median);

			curr = stack_b->begin;
			i = stack_b->size;
			while (curr && i)
			{
				if (*(uint32_t *)curr->data < median)
					if (!rb(ps))
						return (FALSE);
				if (*(uint32_t *)curr->data >= median)
					if (!pa(ps))
						return (FALSE);
				if (*(uint32_t *)curr->data == median)
					if (!ra(ps))
						return (FALSE);
				curr = stack_b->begin;
				i -= 1;
			}
			if (!rra(ps))
				return (FALSE);
			fprintf(stderr, "median became a pivot : %u\n", median);
			fprintf(stderr, "stack_a\n");
			list_print(stack_a);
			fprintf(stderr, "\nstack_b\n");
			list_print(stack_b);
//			exit(EXIT_FAILURE);
		}
	}
//	exit(EXIT_FAILURE);

	return (TRUE);
}

/*
**	TODO: add_pivot
**	TODO: register newly created pivot in find_intervall etc
*/
static t_bool	add_pivot(t_ps *ps, uint8_t pivot_intervall)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = ps->a;
	stack_b = ps->b;
	if (!pb_small(ps, pivot_intervall))
		return (FALSE);
	return (TRUE);
}

/*
**	Create a new pivot if intervall is big, else apply insertion sort.
*/
t_bool	prep_insertion_sort(t_ps *ps)
{
	t_list	*stack_a;
	t_list	*stack_b;
	uint8_t	pivot_intervall;
	uint8_t	deepness;

	stack_a = ps->a;
	stack_b = ps->b;
	deepness = 1;
	fprintf(stderr, "------------------------PREP INSERTION----------------------\n");
	while (!is_sorted(stack_a) || stack_b->size != 0)
	{
		pivot_intervall = find_intervall(ps, stack_a->begin, deepness);
		fprintf(stderr, "pivot intervall = %d\n\n", pivot_intervall);
		// Si je suis pas sur un pivot => tri insertion
		if (pivot_intervall < MAGIC)	// TODO: find magic value
		{
			if (!insertion_sort(ps, pivot_intervall))
				return (FALSE);
			deepness = 1;
		}
		else
		{
			// TODO: make new pivot (in is_pivot too)
			fprintf(stderr, "new pivot\n");
			deepness += 1;
//			if (!insertion_sort(ps, pivot_intervall))
//				return (FALSE);
			if (!add_pivot(ps, pivot_intervall))
				return (FALSE);
//			break ;
		}
	}
	return (TRUE);
}

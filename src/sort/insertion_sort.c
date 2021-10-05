/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 16:12:14 by agautier          #+#    #+#             */
/*   Updated: 2021/10/05 18:56:24 by agautier         ###   ########.fr       */
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
	while (elem && curr && curr != elem)
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
static t_bool	insertion_sort(t_ps *ps)
{
	static uint32_t	interesting_value = 0;
	t_list			*stack_a;
	t_list			*stack_b;
	t_op			op;

	//fprintf(stderr, "\n----------\tINSERTION\t--------\n\n");
	stack_a = ps->a;
	stack_b = ps->b;
	interesting_value += 1;
	if (is_in_a(ps, interesting_value))
	{
		while (*(uint32_t *)stack_a->begin->data != interesting_value)
			if (!pb(ps))
				return (FALSE);
		if (!ra(ps))
			return (FALSE);
	}
	else
	{
		op = get_fastest_op(stack_b, node_find(stack_b, interesting_value));
		while (*(uint32_t *)stack_b->begin->data != interesting_value)
			if (!op(ps))
				return (FALSE);
		if (!pa(ps))
			return (FALSE);
		if (!ra(ps))
			return (FALSE);
	}
	while (*(uint32_t *)stack_a->begin->data
				== *(uint32_t *)stack_a->end->data + 1
		||
			(stack_b->size && *(uint32_t *)stack_b->begin->data
				== *(uint32_t *)stack_a->end->data + 1))
	{
		if (stack_b->size && *(uint32_t *)stack_b->begin->data
				== *(uint32_t *)stack_a->end->data + 1)
			if (!pa(ps))
				return (FALSE);
		if (!ra(ps))
			return (FALSE);
		interesting_value += 1;
	}
		//fprintf(stderr, "\nafter insertion_sort\n");
		//fprintf(stderr, "\nstack_a\n\n");
		//list_print(stack_a);
		//fprintf(stderr, "\nstack_b\n\n");
		//list_print(stack_b);
	return (TRUE);
}

/*
**	On `a`, rotate values greater than median or pb values lesser.
**	Median becomes a pivot.
*/
static t_bool	add_pivot(t_ps *ps)
{
	t_list		*stack_a;
	t_list		*stack_b;
	t_node		*curr;
	t_node		*end;
	uint32_t	median;
	uint16_t	i;
	uint32_t	*ptr;

	stack_a = ps->a;
	stack_b = ps->b;
	end = stack_a->end;
	median = *(uint32_t *)stack_a->end->data + ((get_greater_pivot(ps, stack_a->begin) - *(uint32_t *)stack_a->end->data + 1 + 1) >> 1);
	ptr = gc_calloc(ps->gc, 1, sizeof(median));
	if (!ptr)
		return (FALSE);
	*ptr = median;
	list_push_back(ps->gc, &ps->pivot, ptr);

	//fprintf(stderr, "median in a = %d\n", median);
	//fprintf(stderr, "\nstack_a\n\n");
	//list_print(stack_a);
	//fprintf(stderr, "\nstack_b\n\n");
	//list_print(stack_b);

	curr = stack_a->begin;
	while (curr && *(uint32_t *)curr->data != 1)
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
	}
	//fprintf(stderr, "pushed smaller in B and pivot at end of B\n");
	//fprintf(stderr, "\nstack_a\n\n");
	//list_print(stack_a);
	//fprintf(stderr, "\nstack_b\n\n");
	//list_print(stack_b);

	//TODO: push end of A at the begining of A
	while (stack_a->end != end)
	{
		if (!rra(ps))
			return (FALSE);
	}
	//fprintf(stderr, "pushed end of A at the begining of A\n");
	//fprintf(stderr, "\nstack_a\n\n");
	//list_print(stack_a);
	//fprintf(stderr, "\nstack_b\n\n");
	//list_print(stack_b);

	//TODO: push pivot (end of B) at begining of A
	if (!rrb(ps))
		return (FALSE);
	if (!pa(ps))
		return (FALSE);

	//fprintf(stderr, "pushed pivot (end of B) at begining of A\n");
	//fprintf(stderr, "\nstack_a\n\n");
	//list_print(stack_a);
	//fprintf(stderr, "\nstack_b\n\n");
	//list_print(stack_b);

	//TODO: - new pivots in B
	while (stack_b->size >= MAGIC)
	{
		median = *(uint32_t *)find_min(stack_b)->data + ((stack_b->size + 1) >> 1);
		ptr = gc_calloc(ps->gc, 1, sizeof(median));
		if (!ptr)
			return (FALSE);
		*ptr = median;
		list_push_back(ps->gc, &ps->pivot, ptr);

		//fprintf(stderr, "median in b = %d\n", median);
		//fprintf(stderr, "\nstack_a\n\n");
		//list_print(stack_a);
		//fprintf(stderr, "\nstack_b\n\n");
		//list_print(stack_b);

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
	}

	//fprintf(stderr, "\nafter sorted B\n");
	//fprintf(stderr, "\nstack_a\n\n");
	//list_print(stack_a);
	//fprintf(stderr, "\nstack_b\n\n");
	//list_print(stack_b);

	while (stack_b->size > 0)
		if (!insertion_sort(ps))
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
	uint16_t	pivot_intervall;
	uint8_t	deepness;

	stack_a = ps->a;
	stack_b = ps->b;
	deepness = 1;
	while (!is_sorted(stack_a) || stack_b->size != 0)
	{
		// evryting in A
		// find_intervall does not know created by median in B
		pivot_intervall = find_intervall(ps, stack_a->begin);

		//fprintf(stderr, "intervall = %d\n", pivot_intervall);
		//fprintf(stderr, "node = %d\n", *(uint32_t *)stack_a->begin->data);
		//fprintf(stderr, "\nstack_a\n\n");
		//list_print(stack_a);
		//fprintf(stderr, "\nstack_b\n\n");
		//list_print(stack_b);

		if (pivot_intervall < MAGIC)	// TODO: find magic value
		{
			if (!insertion_sort(ps))
				return (FALSE);
			deepness = 1;
		}
		else
		{
			//fprintf(stderr, "\n***********\tQUICK\t************\n\n");
			deepness += 1;
			if (!add_pivot(ps))
				return (FALSE);
		}
	}
	return (TRUE);
}

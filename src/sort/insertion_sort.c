/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 16:12:14 by agautier          #+#    #+#             */
/*   Updated: 2021/10/06 21:41:15 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	
*/
static t_bool	insertion_sort_(t_ps *ps, uint32_t *interesting_value)
{
	t_list			*stack_a;
	t_list			*stack_b;

	stack_a = ps->a;
	stack_b = ps->b;
	while (*(uint32_t *)stack_a->begin->data
		== *(uint32_t *)stack_a->end->data + 1
		|| (stack_b->size && *(uint32_t *)stack_b->begin->data
			== *(uint32_t *)stack_a->end->data + 1))
	{
		if (stack_b->size && *(uint32_t *)stack_b->begin->data
			== *(uint32_t *)stack_a->end->data + 1)
			if (!pa(ps))
				return (FALSE);
		if (!ra(ps))
			return (FALSE);
		*interesting_value += 1;
	}
	return (TRUE);
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
		return (insertion_sort_(ps, &interesting_value));
	}
	op = get_fastest_op(ps, stack_b, node_find(stack_b, interesting_value));
	while (*(uint32_t *)stack_b->begin->data != interesting_value)
		if (!op(ps))
			return (FALSE);
	if (!pa(ps) || !ra(ps))
		return (FALSE);
	return (insertion_sort_(ps, &interesting_value));
}

/*
**
*/
static t_bool	empty_b(t_ps *ps)
{
	t_list		*stack_b;
	uint32_t	median;
	uint32_t	*ptr;

	stack_b = ps->b;
	while (stack_b->size >= MAGIC)
	{
		median = *(uint32_t *)find_min(stack_b)->data
			+ ((stack_b->size + 1) >> 1);
		ptr = gc_calloc(ps->gc, 1, sizeof(median));
		if (!ptr)
			return (FALSE);
		*ptr = median;
		list_push_back(ps->gc, &ps->pivot, ptr);
		if (!bigs_in_a(ps, median))
			return (FALSE);
	}
	while (stack_b->size > 0)
		if (!insertion_sort(ps))
			return (FALSE);
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
	t_node		*end;
	uint32_t	median;
	uint32_t	*ptr;

	stack_a = ps->a;
	stack_b = ps->b;
	end = stack_a->end;
	median = *(uint32_t *)stack_a->end->data
		+ ((get_greater_pivot(ps, stack_a->begin)
				- *(uint32_t *)stack_a->end->data + 1 + 1) >> 1);
	ptr = gc_calloc(ps->gc, 1, sizeof(median));
	if (!ptr)
		return (FALSE);
	*ptr = median;
	list_push_back(ps->gc, &ps->pivot, ptr);
	if (!smalls_in_b_is(ps, median))
		return (FALSE);
	while (stack_a->end != end)
		if (!rra(ps))
			return (FALSE);
	if (!rrb(ps) || !pa(ps))
		return (FALSE);
	return (empty_b(ps));
}

/*
**	Create a new pivot if intervall is big, else apply insertion sort.
*/
t_bool	prep_insertion_sort(t_ps *ps)
{
	t_list		*stack_a;
	t_list		*stack_b;
	uint16_t	pivot_intervall;
	uint8_t		deepness;

	stack_a = ps->a;
	stack_b = ps->b;
	deepness = 1;
	while (!is_sorted(stack_a) || stack_b->size != 0)
	{
		pivot_intervall = find_intervall(ps, stack_a->begin);
		if (pivot_intervall < MAGIC)
		{
			deepness = 1;
			if (!insertion_sort(ps))
				return (FALSE);
		}
		else
		{
			deepness += 1;
			if (!add_pivot(ps))
				return (FALSE);
		}
	}
	return (TRUE);
}

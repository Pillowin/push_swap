/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 12:06:35 by agautier          #+#    #+#             */
/*   Updated: 2021/07/09 15:57:32 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	On `a`, rotate values greater than median or pb values lesser.
**	Median becomes a pivot.
*/
static t_bool	pb_small(t_gc *gc, t_list **a, t_list **b, t_list **out)
{
	t_list		*stack_a;
	t_list		*stack_b;
	t_node		*curr;
	uint32_t	median;
	uint8_t		i;

	stack_a = *a;
	stack_b = *b;
	median = get_median(stack_a);
	fprintf(stderr, "median = %u\n", median);
	curr = stack_a->begin;
	i = stack_a->size;
	while (curr && i)
	{
		if (*(uint32_t *)curr->data <= median)
			if (!pb(gc, a, b, out))
				return (FALSE);
		if (*(uint32_t *)curr->data > median)
			if (!ra(gc, a, b, out))
				return (FALSE);
		curr = stack_a->begin;
		i -= 1;
	}
	fprintf(stderr, "stack_a\n");
	list_print(stack_a);
	fprintf(stderr, "stack_b\n");
	list_print(*b);
	return (TRUE);
}

/*
**	While ``b`` is not empty,
**	rotate value lesser than median or pa values greater.
*/
static t_bool	empty_b(t_gc *gc, t_list **a, t_list **b, t_list **out)
{
	t_list		*stack_a;
	t_list		*stack_b;
	t_node		*curr;
	uint32_t	median;
	uint8_t		i;

	stack_a = *a;
	stack_b = *b;
	while (stack_b->size)
	{
		fprintf(stderr, "===========\n\n");
		// pa for big in b
		median = get_median(stack_b);
		fprintf(stderr, "median = %u\n", median);
		curr = stack_b->begin;
		i = stack_b->size;
		while (curr && i)
		{
			if (*(uint32_t *)curr->data < median)
				if (!rb(gc, a, b, out))
					return (FALSE);
			if (*(uint32_t *)curr->data >= median)
				if (!pa(gc, a, b, out))
					return (FALSE);
			if (*(uint32_t *)curr->data == median)
				if (!ra(gc, a, b, out))
					return (FALSE);
			curr = stack_b->begin;
			i -= 1;
		}
		if (!rra(gc, a, b, out))
			return (FALSE);
		fprintf(stderr, "stack_a\n");
		list_print(stack_a);
		fprintf(stderr, "stack_b\n");
		list_print(*b);
	}
	return (TRUE);
}

/*
**	Apply quick sort for list longer than 5 elements.
*/
t_bool	quick_sort(t_gc *gc, t_list **a, t_list **b, t_list **out)
{
	if (!pb_small(gc, a, b, out))
		return (FALSE);
	if (!empty_b(gc, a, b, out))
		return (FALSE);
	return (TRUE);
}

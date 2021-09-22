/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 12:06:35 by agautier          #+#    #+#             */
/*   Updated: 2021/09/22 16:32:51 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	On `a`, rotate values greater than median or pb values lesser.
**	Median becomes a pivot.
*/
static t_bool	pb_small(t_ps *ps)
{
	t_list		*stack_a;
	t_list		*stack_b;
	t_node		*curr;
	uint32_t	median;
	uint16_t		i;

	stack_a = ps->a;
	stack_b = ps->b;

	////fprintf(stderr, "stack_a\n");
	////list_printf(stack_a);
	////fprintf(stderr, "\nstack_b\n");
	////list_printf(stack_b);
	median = get_median(stack_a);
	////fprintf(stderr, "median = %u\n", median);

	curr = stack_a->begin;
	i = stack_a->size;
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
	if (!rrb(ps))
		return (FALSE);
	if (!pa(ps))
		return (FALSE);
	//fprintf(stderr, "median became a pivot quick : %u\n", median);
	////fprintf(stderr, "stack_a\n");
	////list_printf(stack_a);
	////fprintf(stderr, "\nstack_b\n");
	////list_printf(stack_b);
	return (TRUE);
}

/*
**	While ``b`` is not empty,
**	rotate value lesser than median or pa values greater.
*/
static t_bool	empty_b(t_ps *ps)
{
//	t_list		*stack_a;
	t_list		*stack_b;
	t_node		*curr;
	uint32_t	median;
	uint16_t		i;

//	stack_a = ps->a;
	stack_b = ps->b;
	while (stack_b->size)
	{
		// pa for big in b
		////fprintf(stderr, "=b==========\n");
		////list_printf(stack_b);
		median = get_median(stack_b);
		////fprintf(stderr, "median = %u\n", median);

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
		//fprintf(stderr, "median became a pivot empty b : %u\n", median);
		//fprintf(stderr, "stack_a\n");
		//list_print(stack_a);
		//fprintf(stderr, "\nstack_b\n");
		//list_print(stack_b);
	}
	return (TRUE);
}

/*
**	Apply quick sort.
*/
t_bool	quick_sort(t_ps *ps)
{

	if (!pb_small(ps))
		return (FALSE);
	if (!empty_b(ps))
		return (FALSE);
	if (!prep_insertion_sort(ps))
		return (FALSE);
	return (TRUE);
}

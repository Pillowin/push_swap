/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 12:06:35 by agautier          #+#    #+#             */
/*   Updated: 2021/10/06 21:33:00 by agautier         ###   ########.fr       */
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
	uint32_t	median;
	uint32_t	*ptr;

	stack_a = ps->a;
	median = get_median(stack_a);
	ptr = gc_calloc(ps->gc, 1, sizeof(median));
	if (!ptr)
		return (FALSE);
	*ptr = median;
	list_push_back(ps->gc, &ps->pivot, ptr);
	if (!smalls_in_b_qs(ps, median))
		return (FALSE);
	return (TRUE);
}

/*
**	While ``b`` is not empty,
**	rotate value lesser than median or pa values greater.
*/
static t_bool	empty_b(t_ps *ps)
{
	t_list		*stack_b;
	uint32_t	median;
	uint32_t	*ptr;

	stack_b = ps->b;
	while (stack_b->size)
	{
		median = get_median(stack_b);
		ptr = gc_calloc(ps->gc, 1, sizeof(median));
		if (!ptr)
			return (FALSE);
		*ptr = median;
		list_push_back(ps->gc, &ps->pivot, ptr);
		if (!bigs_in_a(ps, median))
			return (FALSE);
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

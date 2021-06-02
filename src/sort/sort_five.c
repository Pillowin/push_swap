/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 11:58:17 by agautier          #+#    #+#             */
/*   Updated: 2021/06/02 17:27:59 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	is_sorted(t_list *list)
{
	t_node	*curr;

	curr = list->begin;
	while (curr && curr->next)
	{
		if (is_great(curr, curr->next))
			return (FALSE);
		curr = curr->next;
	}
	return (TRUE);
}

/*
**
*/
t_bool	is_ra_fastest(t_list *list, t_node *curr, t_node *elem)
{
	uint16_t	pos;

	pos = 0;
	while (curr && elem && is_great(curr, elem))
	{
		pos += 1;
		curr = curr->next;
	}
	if (pos < list->size / 2)
		return (TRUE);
	return (FALSE);
}

/*
**
*/
static t_bool	sort_a(t_gc *gc, t_list **a, t_list **b, t_list **out)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_bool	(*op)(t_gc *, t_list **, t_list **, t_list **);

	stack_a = *a;
	stack_b = *b;
	op = rra;
	if (is_ra_fastest(stack_a, stack_a->begin, stack_b->begin))
		op = ra;
	while (!(is_sorted(stack_a) && (is_great(stack_a->begin, stack_b->begin)
				|| is_great(stack_b->begin, stack_a->end)))
		&& ((op == rra && is_great(stack_a->end, stack_b->begin))
			|| (op == ra && is_great(stack_b->begin, stack_a->begin))))
		if (!op(gc, a, b, out))
			return (FALSE);
	if (!pa(gc, a, b, out))
		return (FALSE);
	op = rra;
	if (is_ra_fastest(stack_a, stack_a->begin->next, stack_a->begin))
		op = ra;
	while (!is_sorted(stack_a))
		if (!op(gc, a, b, out))
			return (FALSE);
	return (TRUE);
}

/*
**	Push both first elements of `a` in `b`.
**	Apply sort_three.
**	Push `b` back in `a`.
*/
t_bool	sort_five(t_gc *gc, t_list **a, t_list **b, t_list **out)
{
	uint8_t	size;

	size = (*a)->size == 5;
	if (size && !pb(gc, a, b, out))
		return (FALSE);
	if (!pb(gc, a, b, out))
		return (FALSE);
	if (!sort_three(gc, a, b, out))
		return (FALSE);
	if (!sort_a(gc, a, b, out))
		return (FALSE);
	if (size && !sort_a(gc, a, b, out))
		return (FALSE);
	return (TRUE);
}

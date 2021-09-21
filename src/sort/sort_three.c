/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 18:29:43 by agautier          #+#    #+#             */
/*   Updated: 2021/08/21 20:15:10 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	2 1 3 => sa
**	3 2 1 => sa
**	1 3 2 => sa
*/
static t_bool	apply_sa(t_ps *ps)
{
	t_list	*stack_a;
	t_node	*one;
	t_node	*two;
	t_node	*three;

	stack_a = ps->a;
	one = stack_a->begin;
	two = stack_a->begin->next;
	three = stack_a->end;
	if ((is_great(three, one) && is_great(three, two) && is_great(one, two))
		|| (is_great(one, two) && is_great(one, three) && is_great(two, three))
		|| (is_great(two, one) && is_great(two, three) && is_great(three, one)))
	{
		if (!sa(ps))
			return (FALSE);
	}
	return (TRUE);
}

/*
**	3 1 2 => ra
*/
static t_bool	apply_ra(t_ps *ps)
{
	t_list	*stack_a;
	t_node	*one;
	t_node	*two;
	t_node	*three;

	stack_a = ps->a;
	one = stack_a->begin;
	two = stack_a->begin->next;
	three = stack_a->end;
	if (is_great(one, two) && is_great(one, three) && is_great(three, two))
	{
		if (!ra(ps))
			return (FALSE);
	}
	return (TRUE);
}

/*
**	2 3 1 => rra
*/
static t_bool	apply_rra(t_ps *ps)
{
	t_list	*stack_a;
	t_node	*one;
	t_node	*two;
	t_node	*three;

	stack_a = ps->a;
	one = stack_a->begin;
	two = stack_a->begin->next;
	three = stack_a->end;
	if (is_great(two, one) && is_great(two, three) && is_great(one, three))
	{
		if (!rra(ps))
			return (FALSE);
	}
	return (TRUE);
}

/*
**	Handle manually when there is only 3 numbers.
**
**	2 1 3 => sa
**	3 2 1 => sa rra
**	3 1 2 => ra
**	1 3 2 => sa ra
**	2 3 1 => rra
*/
t_bool	sort_three(t_ps *ps)
{
	if (!apply_sa(ps))
		return (FALSE);
	if (!apply_ra(ps))
		return (FALSE);
	if (!apply_rra(ps))
		return (FALSE);
	return (TRUE);
}

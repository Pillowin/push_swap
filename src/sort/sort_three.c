/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 18:29:43 by agautier          #+#    #+#             */
/*   Updated: 2021/05/30 22:52:29 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	2 1 3 => sa
**	3 2 1 => sa
**	1 3 2 => sa
*/
static t_bool	apply_sa(t_gc *gc, t_list **a, t_list **b, t_list **output)
{
	t_list	*stack_a;
	int		one;
	int		two;
	int		three;

	stack_a = *a;
	one = *(int *)(stack_a->begin->data);
	two = *(int *)(stack_a->begin->next->data);
	three = *(int *)(stack_a->end->data);
	if ((is_great(three, one) && is_great(three, two) && is_great(one, two))
		|| (is_great(one, two) && is_great(one, three) && is_great(two, three))
		|| (is_great(two, one) && is_great(two, three) && is_great(three, one)))
	{
		if (!sa(gc, a, b, output))
			return (FALSE);
	}
	return (TRUE);
}

/*
**	3 1 2 => ra
*/
static t_bool	apply_ra(t_gc *gc, t_list **a, t_list **b, t_list **output)
{
	t_list	*stack_a;
	int		one;
	int		two;
	int		three;

	stack_a = *a;
	one = *(int *)(stack_a->begin->data);
	two = *(int *)(stack_a->begin->next->data);
	three = *(int *)(stack_a->end->data);
	if (is_great(one, two) && is_great(one, three) && is_great(three, two))
	{
		if (!ra(gc, a, b, output))
			return (FALSE);
	}
	return (TRUE);
}

/*
**	2 3 1 => rra
*/
static t_bool	apply_rra(t_gc *gc, t_list **a, t_list **b, t_list **output)
{
	t_list	*stack_a;
	int		one;
	int		two;
	int		three;

	stack_a = *a;
	one = *(int *)(stack_a->begin->data);
	two = *(int *)(stack_a->begin->next->data);
	three = *(int *)(stack_a->end->data);
	if (is_great(two, one) && is_great(two, three) && is_great(one, three))
	{
		if (!rra(gc, a, b, output))
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
t_bool	sort_three(t_gc *gc, t_list **a, t_list **b, t_list **output)
{
	if (!apply_sa(gc, a, b, output))
		return (FALSE);
	if (!apply_ra(gc, a, b, output))
		return (FALSE);
	if (!apply_rra(gc, a, b, output))
		return (FALSE);
	return (TRUE);
}

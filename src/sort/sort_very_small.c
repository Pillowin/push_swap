/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_very_small.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 13:54:58 by agautier          #+#    #+#             */
/*   Updated: 2021/05/31 13:53:43 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	Optimized sort for stack under 5 elements.
*/
t_bool	sort_very_small(t_gc *gc, t_list **a, t_list **b, t_list **out)
{
	t_list	*stack_a;

	stack_a = *a;
	if (stack_a->size == 2)
	{
		if (!sort_two(gc, a, b, out))
			return (FALSE);
	}
	else if (stack_a->size == 3)
	{
		if (!sort_three(gc, a, b, out))
			return (FALSE);
	}
	else if (stack_a->size == 5)
	{
		if (!sort_five(gc, a, b, out))
			return (FALSE);
	}
	return (TRUE);
}

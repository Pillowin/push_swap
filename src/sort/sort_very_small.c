/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_very_small.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 13:54:58 by agautier          #+#    #+#             */
/*   Updated: 2021/05/30 22:25:04 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	Optimized sort for stack with 2 or 3 elements.
*/
t_bool	sort_very_small(t_gc *gc, t_list **a, t_list **b, t_list **output)
{
	t_list	*stack_a;

	stack_a = *a;
	if (stack_a->size == 2)
	{
		if (!sort_two(gc, a, b, output))
			return (FALSE);
	}
	else if (stack_a->size == 3)
	{
		if (!sort_three(gc, a, b, output))
			return (FALSE);
	}
	return (TRUE);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_very_small.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 13:54:58 by agautier          #+#    #+#             */
/*   Updated: 2021/05/30 17:06:06 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	Optimized sort for stack with 2 or 3 elements.
*/
void	sort_very_small(t_list **a, t_list **b)
{
	t_list	*stack_a;

	stack_a = *a;
	if (stack_a->size == 2)
		sort_two(a, b);
	else
		sort_three(a, b);
}

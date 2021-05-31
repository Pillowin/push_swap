/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 17:05:36 by agautier          #+#    #+#             */
/*   Updated: 2021/05/31 13:43:41 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	
*/
t_bool	sort_two(t_gc *gc, t_list **a, t_list **b, t_list **out)
{
	t_list	*stack_a;

	stack_a = *a;
	if (is_great(stack_a->begin, stack_a->end))
		if (!sa(gc, a, b, out))
			return (FALSE);
	return (TRUE);
}

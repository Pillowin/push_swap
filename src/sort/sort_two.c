/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 17:05:36 by agautier          #+#    #+#             */
/*   Updated: 2021/05/30 21:34:39 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	
*/
t_bool	sort_two(t_gc *gc, t_list **a, t_list **b, t_list **output)
{
	t_list	*stack_a;

	stack_a = *a;
	if (is_great(*(int *)stack_a->begin->data, *(int *)stack_a->end->data))
		if (!sa(gc, a, b, output))
			return (FALSE);
	return (TRUE);
}

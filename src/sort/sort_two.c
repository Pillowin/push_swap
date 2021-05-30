/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 17:05:36 by agautier          #+#    #+#             */
/*   Updated: 2021/05/30 17:08:27 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	
*/
void	sort_two(t_list **a, t_list **b)
{
	t_list	*stack_a;

	stack_a = *a;
	if (is_great(*(int *)stack_a->begin->data, *(int *)stack_a->end->data))
		sa(a, b);
}

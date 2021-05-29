/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 18:44:27 by agautier          #+#    #+#             */
/*   Updated: 2021/05/29 18:09:27 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	push a
**	Take the first element at the top of b and put it at the top of a.
**	Do nothing if b is empty.
*/
void	pa(t_list **a, t_list **b)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_node	*tmp;
	t_node	*tmp2;

	stack_a = *a;
	stack_b = *b;
	if (stack_b->size == 0)
		return ;
	tmp = stack_b->begin;
	stack_b->begin = stack_b->begin->next;
	tmp2 = stack_a->begin;
	stack_a->begin = tmp;
	stack_a->begin->next = tmp2;
	if (!stack_a->end)
		stack_a->end = stack_a->begin;
	stack_b->size -= 1;
	stack_a->size += 1;
}

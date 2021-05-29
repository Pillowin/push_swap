/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 18:48:44 by agautier          #+#    #+#             */
/*   Updated: 2021/05/29 18:09:40 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	push b
**	Take the first element at the top of a and put it at the top of b.
**	Do nothing if a is empty.
*/
void	pb(t_list **a, t_list **b)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_node	*tmp;
	t_node	*tmp2;

	stack_a = *a;
	stack_b = *b;
	if (stack_a->size == 0)
		return ;
	tmp = stack_a->begin;
	stack_a->begin = stack_a->begin->next;
	tmp2 = stack_b->begin;
	stack_b->begin = tmp;
	stack_b->begin->next = tmp2;
	if (!stack_b->end)
		stack_b->end = stack_b->begin;
	stack_a->size -= 1;
	stack_b->size += 1;
}

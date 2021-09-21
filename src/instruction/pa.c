/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 18:44:27 by agautier          #+#    #+#             */
/*   Updated: 2021/09/15 16:15:22 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	push a
**	Take the first element at the top of b and put it at the top of a.
**	Do nothing if b is empty.
*/
t_bool	pa(t_ps *ps)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_node	*tmp;
	t_node	*tmp2;

	stack_a = ps->a;
	stack_b = ps->b;
	if (stack_b->size == 0)
		return (TRUE);
	tmp = stack_b->begin;
	stack_b->begin = stack_b->begin->next;
	tmp2 = stack_a->begin;
	stack_a->begin = tmp;
	stack_a->begin->next = tmp2;
	if (stack_a->size == 0)
		stack_a->end = stack_a->begin;
	stack_b->size -= 1;
	stack_a->size += 1;
	if (!list_push_back(ps->gc, &ps->out, "pa"))
		return (FALSE);
	return (TRUE);
}

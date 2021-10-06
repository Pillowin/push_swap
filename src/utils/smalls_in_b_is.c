/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smalls_in_b_is.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 20:51:14 by agautier          #+#    #+#             */
/*   Updated: 2021/10/06 21:31:14 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	Puts number smaller than median in B and median at the begining of A.
*/
t_bool	smalls_in_b_is(t_ps *ps, uint32_t median)
{
	t_list		*stack_a;
	t_list		*stack_b;
	t_node		*curr;

	stack_a = ps->a;
	stack_b = ps->b;
	curr = stack_a->begin;
	while (curr && *(uint32_t *)curr->data != 1)
	{
		if (*(uint32_t *)curr->data <= median)
			if (!pb(ps))
				return (FALSE);
		if (stack_b->size > 1 && *(uint32_t *)stack_b->begin->data == median)
			if (!rb(ps))
				return (FALSE);
		if (*(uint32_t *)curr->data > median)
			if (!ra(ps))
				return (FALSE);
		curr = stack_a->begin;
	}
	return (TRUE);
}

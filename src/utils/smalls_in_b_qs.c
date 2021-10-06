/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smalls_in_b_qs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 20:51:14 by agautier          #+#    #+#             */
/*   Updated: 2021/10/06 21:30:34 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	Puts number smaller than median in B and median at the begining of A.
*/
t_bool	smalls_in_b_qs(t_ps *ps, uint32_t median)
{
	t_list		*stack_a;
	t_node		*curr;
	uint16_t	i;

	stack_a = ps->a;
	curr = stack_a->begin;
	i = stack_a->size;
	while (curr && i)
	{
		if (*(uint32_t *)curr->data <= median)
			if (!pb(ps))
				return (FALSE);
		if (ps->b->size > 1 && *(uint32_t *)ps->b->begin->data == median)
			if (!rb(ps))
				return (FALSE);
		if (*(uint32_t *)curr->data > median)
			if (!ra(ps))
				return (FALSE);
		curr = stack_a->begin;
		i -= 1;
	}
	if (!rrb(ps) || !pa(ps))
		return (FALSE);
	return (TRUE);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigs_in_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 20:48:19 by agautier          #+#    #+#             */
/*   Updated: 2021/10/06 20:48:29 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	Puts bigger number than median in A and median at the begining of A.
*/
t_bool	bigs_in_a(t_ps *ps, uint32_t median)
{
	t_list		*stack_b;
	t_node		*curr;
	uint16_t	i;

	stack_b = ps->b;
	curr = stack_b->begin;
	i = stack_b->size;
	while (curr && i)
	{
		if (*(uint32_t *)curr->data < median)
			if (!rb(ps))
				return (FALSE);
		if (*(uint32_t *)curr->data >= median)
			if (!pa(ps))
				return (FALSE);
		if (*(uint32_t *)curr->data == median)
			if (!ra(ps))
				return (FALSE);
		curr = stack_b->begin;
		i -= 1;
	}
	if (!rra(ps))
		return (FALSE);
	return (TRUE);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_greater_pivot.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 20:46:11 by agautier          #+#    #+#             */
/*   Updated: 2021/10/05 18:55:30 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	Return pivot intervall depending on current position on list.
*/
uint32_t	get_greater_pivot(t_ps *ps, t_node *node)
{
	uint32_t	ret;
	t_node		*curr;

	ret = ps->a->size + ps->b->size;
	curr = ps->pivot->begin;
	while (curr)
	{
		if (*(uint32_t *)curr->data > *(uint32_t *)node->data
			&& *(uint32_t *)curr->data < ret)
			ret = *(uint32_t *)curr->data;
		curr = curr->next;
	}
	return (ret);
}

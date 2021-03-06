/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_intervall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 15:00:59 by agautier          #+#    #+#             */
/*   Updated: 2021/10/06 15:01:14 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_bigger(uint32_t *a, uint32_t *b)
{
	return (*a > *b);
}

/*
**	Return pivot intervall depending on current position on list.
*/
uint16_t	find_intervall(t_ps *ps, t_node *node)
{
	uint32_t	ret;
	t_node		*curr;

	list_sort(ps->pivot, is_bigger);
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

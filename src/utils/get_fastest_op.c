/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fastest_op.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 16:35:22 by agautier          #+#    #+#             */
/*   Updated: 2021/10/06 22:18:19 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Returns fastest rotation to sort list.
*/
t_op	get_fastest_op(t_ps *ps, t_list *list, t_node *elem)
{
	uint16_t	pos;
	t_node		*curr;

	curr = list->begin;
	pos = 0;
	while (elem && curr && ((list == ps->b && curr != elem)
			|| (list == ps->a && is_great(elem, curr))))
	{
		pos += 1;
		curr = curr->next;
	}
	if (list->begin == curr && pos > list->size >> 1)
		pos = list->size - pos;
	if (pos > list->size >> 1)
	{
		if (list == ps->b)
			return (rrb);
		return (rra);
	}
	if (list == ps->b)
		return (rb);
	return (ra);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_push_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 21:07:14 by agautier          #+#    #+#             */
/*   Updated: 2021/05/25 21:20:00 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Add a new node at the begining of the list.
*/

t_node	*list_push_front(t_gc *gc, t_list **alist, void *data)
{
	t_list	*list;
	t_node	*node;

	list = *alist;
	node = node_new(gc, data);
	if (!node)
		return (NULL);
	node->next = list->begin;
	list->begin = node;
	if (list->size == 0)
		list->end = list->begin;
	list->size += 1;
	return (node);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_push_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 12:03:19 by agautier          #+#    #+#             */
/*   Updated: 2021/05/22 12:09:47 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Add a new list node at the end of the list.
*/

t_node	*list_push_back(t_list **alist, void *data)
{
	t_list	*list;
	t_node	*node

	list = *alist;
	node = node_new(data);
	if (!node)
		return (NULL);
	if (list->end)
		list->end->next = node;
	else
		list->begin = node;
	list->size += 1;
	return (node);
}

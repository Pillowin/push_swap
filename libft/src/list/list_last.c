/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_last.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 12:03:19 by agautier          #+#    #+#             */
/*   Updated: 2021/06/24 17:06:21 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Return last node of a list.
*/
t_node	*list_last(t_list *list)
{
	t_node	*curr;

	list = *alist;
	node = node_new(gc, data);
	if (!node)
		return (NULL);
	if (list->end)
		list->end->next = node;
	else
		list->begin = node;
	list->end = node;
	list->size += 1;
	return (node);
}

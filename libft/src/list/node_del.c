/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_del.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 21:23:09 by agautier          #+#    #+#             */
/*   Updated: 2021/06/03 15:03:27 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Free a t_node but keeps list linked.
*/
t_node	*node_del(t_gc *gc, t_list **alist, t_node *prev)
{
	t_list	*list;
	t_node	*curr;
	t_node	*next;

	list = *alist;
	if (prev)
		curr = prev->next;
	else
		curr = list->begin;
	next = curr->next;
	if (list->end == curr)
	{
		if (prev)
			list->end = prev;
		else
			list->end = list->begin;
	}
	gc_free(gc, (void **)&curr);
	if (prev)
		prev->next = next;
	else
		list->begin = next;
	list->size -= 1;
	return (prev);
}

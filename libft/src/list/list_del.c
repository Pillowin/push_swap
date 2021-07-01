/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_del.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 17:05:02 by agautier          #+#    #+#             */
/*   Updated: 2021/07/01 17:59:05 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Free whole list.
*/
void	list_del(t_gc *gc, t_list **alist)
{
	t_list	*list;
	t_node	*curr;
	void	*tmp;

	if (!alist || !*alist)
		return ;
	list = *alist;
	curr = list->begin;
	while (curr)
	{
		gc_free(gc, (void **)&(curr->data));
		tmp = curr;
		curr = curr->next;
		gc_free(gc, (void **)&(tmp));
	}
	gc_free(gc, (void **)&alist);
}

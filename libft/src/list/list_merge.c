/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_merge.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 16:13:21 by agautier          #+#    #+#             */
/*   Updated: 2021/06/25 16:39:51 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Add a list2 at the end of the list1.
*/
void	list_merge(t_list **alist1, t_list *list2)
{
	t_list	*list1;

	if (!list2 || !list2->begin)
		return ;
	list1 = *alist1;
	if (list1->size == 0)
	{
		list1 = list2;
		return ;
	}
	list1->size += list2->size;
	list1->end->next = list2->begin;
	list1->end = list2->end;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 19:01:04 by agautier          #+#    #+#             */
/*   Updated: 2021/08/23 19:16:58 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	reverse rotate b
**	Shift down all elements of stack b by 1.
**	The last element becomes the first one.
*/
t_bool	rrb(t_ps *ps)
{
	t_list	*list;
	t_node	*tmp;

	list = ps->b;
	if (!list || list->size <= 1)
		return (TRUE);
	tmp = list->begin;
	list->begin = list->end;
	list->begin->next = tmp;
	while (tmp->next != list->begin)
		tmp = tmp->next;
	list->end = tmp;
	list->end->next = NULL;
	if (!list_push_back(ps->gc, &ps->out, "rrb"))
		return (FALSE);
	return (TRUE);
}

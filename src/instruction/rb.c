/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 18:58:04 by agautier          #+#    #+#             */
/*   Updated: 2021/09/22 16:13:26 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	rotate b
**	Shift up all elements of stack b by 1.
**	The first element becomes the last one.
*/
t_bool	rb(t_ps *ps)
{
	t_list	*list;
	t_node	*tmp;

	list = ps->b;
	if (list->size <= 1)
		return (TRUE);
	tmp = list->begin;
	list->begin = list->begin->next;
	tmp->next = NULL;
	list->end->next = tmp;
	list->end = tmp;
	if (!list_push_back(ps->gc, &ps->out, "rb"))
		return (FALSE);
	return (TRUE);
}

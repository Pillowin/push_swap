/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 18:58:04 by agautier          #+#    #+#             */
/*   Updated: 2021/05/31 12:30:54 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	rotate b
**	Shift up all elements of stack b by 1.
**	The first element becomes the last one.
*/
t_bool	rb(t_gc *gc, t_list **a, t_list **b, t_list **out)
{
	t_list	*list;
	t_node	*tmp;

	(void)a;
	list = *b;
	if (!list->begin)
		return (TRUE);
	tmp = list->begin;
	list->begin = list->begin->next;
	tmp->next = NULL;
	list->end->next = tmp;
	list->end = tmp;
	if (!list_push_back(gc, out, "rb"))
		return (FALSE);
	return (TRUE);
}

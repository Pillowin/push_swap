/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 18:58:04 by agautier          #+#    #+#             */
/*   Updated: 2021/05/31 12:28:24 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	rotate a
**	Shift up all elements of stack b by 1.
**	The first element becomes the last one.
*/
t_bool	ra(t_gc *gc, t_list **a, t_list **b, t_list **out)
{
	t_list	*list;
	t_node	*tmp;

	(void)b;
	list = *a;
	tmp = list->begin;
	if (!list->begin)
		return (TRUE);
	list->begin = list->begin->next;
	tmp->next = NULL;
	list->end->next = tmp;
	list->end = tmp;
	if (!list_push_back(gc, out, "ra"))
		return (FALSE);
	return (TRUE);
}

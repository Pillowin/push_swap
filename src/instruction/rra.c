/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 18:59:07 by agautier          #+#    #+#             */
/*   Updated: 2021/07/09 15:44:29 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	reverse rotate a
**	Shift down all elements of stack a by 1.
**	The last element becomes the first one.
*/
t_bool	rra(t_gc *gc, t_list **a, t_list **b, t_list **out)
{
	t_list	*list;
	t_node	*tmp;

	(void)b;
	list = *a;
	if (!list)
		return (TRUE);
	tmp = list->begin;
	list->begin = list->end;
	list->begin->next = tmp;
	while (tmp->next != list->begin)
		tmp = tmp->next;
	list->end = tmp;
	list->end->next = NULL;
	if (!list_push_back(gc, out, "rra"))
		return (FALSE);
	return (TRUE);
}

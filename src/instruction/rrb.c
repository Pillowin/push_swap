/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 19:01:04 by agautier          #+#    #+#             */
/*   Updated: 2021/05/29 18:11:25 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	reverse rotate b
**	Shift down all elements of stack b by 1.
**	The last element becomes the first one.
*/
void	rrb(t_list **a, t_list **b)
{
	t_list	*list;
	t_node	*tmp;

	(void)a;
	list = *b;
	if (!list)
		return ;
	tmp = list->begin;
	list->begin = list->end;
	list->begin->next = tmp;
	while (tmp->next != list->begin)
		tmp = tmp->next;
	list->end = tmp;
	list->end->next = NULL;
}

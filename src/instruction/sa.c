/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 18:39:50 by agautier          #+#    #+#             */
/*   Updated: 2021/08/21 20:15:00 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	swap a
**	Swap the first 2 elements at the top of stack a.
**	Do nothing if there is only one or no elements.
*/
t_bool	sa(t_ps *ps)
{
	t_list	*list;
	void	*tmp;

	list = ps->a;
	if (list->size <= 1)
		return (TRUE);
	tmp = list->begin->data;
	list->begin->data = list->begin->next->data;
	list->begin->next->data = tmp;
	if (!list_push_back(ps->gc, &ps->out, "sa"))
		return (FALSE);
	return (TRUE);
}

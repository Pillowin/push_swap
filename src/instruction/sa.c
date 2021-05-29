/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 18:39:50 by agautier          #+#    #+#             */
/*   Updated: 2021/05/29 18:08:37 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	swap a
**	Swap the first 2 elements at the top of stack a.
**	Do nothing if there is only one or no elements.
*/
void	sa(t_list **a, t_list **b)
{
	t_list	*list;
	void	*tmp;

	(void)b;
	list = *a;
	if (list->size <= 1)
		return ;
	tmp = list->begin->data;
	list->begin->data = list->begin->next->data;
	list->begin->next->data = tmp;
}

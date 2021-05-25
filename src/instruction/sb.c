/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 18:42:30 by agautier          #+#    #+#             */
/*   Updated: 2021/05/25 22:44:36 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	swap b
**	Swap the first 2 elements at the top of stack b.
**	Do nothing if thereis only one or no elements.
*/

t_bool	sb(t_gc *gc, t_list **a, t_list **b)
{
	t_list	*list;
	void	*tmp;

	(void)gc;
	(void)a;
	list = *b;
	tmp = list->begin->data;
	list->begin->data = list->begin->next->data;
	list->begin->next->data = tmp;
	return (TRUE);
}

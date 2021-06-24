/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 12:04:31 by agautier          #+#    #+#             */
/*   Updated: 2021/06/23 18:02:10 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	Return lowest element of stack.
*/
t_node	*find_min(t_list *list)
{
	t_node	*min;
	t_node	*curr;

	min = NULL;
	curr = list->begin;
	while (curr)
	{
		if (!min || is_great(min, curr))
			min = curr;
		curr = curr->next;
	}
	return (min);
}

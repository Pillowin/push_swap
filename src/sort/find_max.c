/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_max.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 12:04:31 by agautier          #+#    #+#             */
/*   Updated: 2021/06/24 14:32:02 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	Return lowest element of stack.
*/
t_node	*find_max(t_list *list)
{
	t_node	*max;
	t_node	*curr;

	max = NULL;
	curr = list->begin;
	while (curr)
	{
		if (!max || is_great(curr, max))
			max = curr;
		curr = curr->next;
	}
	return (max);
}

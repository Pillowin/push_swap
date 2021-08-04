/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_node_index.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 14:23:41 by agautier          #+#    #+#             */
/*   Updated: 2021/08/04 14:25:58 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Return index of node in list.
*/
uint8_t	get_node_index(t_list *list, t_node *node)
{
	t_node	*curr;
	uint8_t	index;

	curr = list->begin;
	index = 0;
	while (curr && curr != node)
	{
		index += 1;
		curr = curr->next;
	}
	return (index);
}

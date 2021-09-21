/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_find.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 17:20:41 by agautier          #+#    #+#             */
/*   Updated: 2021/08/11 17:22:24 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Find a node from his data.
*/
t_node	*node_find(t_list *list, uint32_t data)
{
	t_node	*curr;

	curr = list->begin;
	while (curr)
	{
		if (*(uint32_t *)curr->data == data)
			break ;
		curr = curr->next;
	}
	return (curr);
}

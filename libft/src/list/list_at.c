/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_at.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 20:04:35 by agautier          #+#    #+#             */
/*   Updated: 2021/07/26 20:07:43 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Return node at index position.
*/
t_node	*list_at(t_list *list, uint8_t index)
{
	t_node	*curr;
	uint8_t	i;

	curr = list->begin;
	i = 0;
	while (curr && i < index)
	{
		curr = curr->next;
		i += 1;
	}
	return (curr);
}

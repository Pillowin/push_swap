/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sequence.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 18:13:57 by agautier          #+#    #+#             */
/*   Updated: 2021/07/01 18:14:04 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	Returns the number of identical following op.
*/
uint8_t	get_sequence(t_node *node)
{
	char	*data;
	uint8_t	i;

	if (!node)
		return (0);
	data = (char *)node->data;
	i = 0;
	while (node && !ft_strcmp(node->data, data))
	{
		i += 1;
		node = node->next;
	}
	return (i);
}

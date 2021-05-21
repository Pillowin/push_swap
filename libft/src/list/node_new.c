/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 20:22:06 by agautier          #+#    #+#             */
/*   Updated: 2021/05/21 21:06:20 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Create a new list node.
*/

t_node	*node_new(void *data)
{
	t_node	*node;

	node = (t_node *)ft_calloc(1, sizeof(*node));
	if (!node)
		return (NULL);
	node->data = data;
	node->next = NULL;
	return (node);
}

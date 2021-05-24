/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 20:22:06 by agautier          #+#    #+#             */
/*   Updated: 2021/05/23 13:44:24 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Create a new list node.
*/

t_node	*node_new(t_list **agc, void *data)
{
	t_node	*node;

	node = (t_node *)gc_calloc(agc, 1, sizeof(*node));
	if (!node)
		return (NULL);
	node->data = data;
	node->next = NULL;
	return (node);
}

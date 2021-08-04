/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_intervall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 00:05:08 by agautier          #+#    #+#             */
/*   Updated: 2021/08/04 17:00:36 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	Return pivot intervall depending on current position on list.
*/
uint8_t	find_intervall(t_list *list, t_node *node)
{
	uint8_t	node_index;
//	uint8_t	pivot_index;


	// find node index
	node_index = get_node_index(list, node);
	fprintf(stderr, "node data = %d\n", *(uint32_t *)(node->data));
	fprintf(stderr, "node index = %d\n", node_index);
	// find pivots index
	// magic maths to find intervall between indexes
	return (node_index);
}

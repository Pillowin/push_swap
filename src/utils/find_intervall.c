/* ************************************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_intervall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 00:05:08 by agautier          #+#    #+#             */
/*   Updated: 2021/09/10 13:40:11 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	Return pivot intervall depending on current position on list.
*/
uint8_t	find_intervall(t_list *list, t_node *node, uint8_t deepness)
{
	uint32_t	pivot;
	uint32_t	prev_pivot;

	pivot = list->size + 1;
	while (pivot > 1 && deepness)
	{
		prev_pivot = pivot;
		if (prev_pivot == list->size + 1)
			prev_pivot = list->size;
		pivot = pivot >> 1;
//		fprintf(stderr, "pivot = %d\n", pivot);
//		fprintf(stderr, "prev pivot = %d\n\n", prev_pivot);
		if (*(uint32_t *)node->data < prev_pivot
				&& *(uint32_t *)node->data >= pivot)
			break ;
	}
	return (prev_pivot - pivot);
}

// determine si les nouveaux pivots ont ete crees
// savoir si find intervall a ete update
//
// compteur de profondeur => a passer en parametre
// determine comment l'incrementer => necessite de connaitre les pivots et pas uniquement l'interval
//

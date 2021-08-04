/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_greater_pivot.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 15:49:32 by agautier          #+#    #+#             */
/*   Updated: 2021/07/26 20:12:29 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	Return next pivot greater than node.
*/
uint32_t	get_greater_pivot(t_list *list, t_node *node)
{
	uint32_t	pivot;
	uint32_t	prev_pivot;

//	list_print(list);
	pivot = (list->size + 1) / 2;
	prev_pivot = list->size;
//	fprintf(stderr, "node data = %d\n", *(uint32_t *)node->data);
//	fprintf(stderr, "prev pivot = %d\n", prev_pivot);
//	fprintf(stderr, "pivot = %d\n", pivot);
	while (pivot > 1)
	{
		if (prev_pivot > *(uint32_t *)node->data && pivot < *(uint32_t *)node->data)
			break ;
		prev_pivot = pivot;
		pivot = (pivot + 1) / 2;
//		fprintf(stderr, "prev pivot = %d\n", prev_pivot);
//		fprintf(stderr, "pivot = %d\n", pivot);
	}
	return (*(uint32_t *)(list_at(list, prev_pivot)->data));
}

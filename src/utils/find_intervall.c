/* ************************************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_intervall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 00:05:08 by agautier          #+#    #+#             */
/*   Updated: 2021/09/21 17:43:40 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	Return pivot intervall depending on current position on list.
*/
uint8_t	find_intervall(t_ps *ps, t_node *node, uint8_t deepness)
{
	uint32_t	pivot;
	uint32_t	prev_pivot;
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = ps->a;
	stack_b = ps->b;
//	fprintf(stderr, "node = %d\n", *(uint32_t *)node->data);
	pivot = stack_a->size + stack_b->size + 1;
	while (pivot > 1 && deepness)
	{
		prev_pivot = pivot;
		if (prev_pivot == stack_a->size + stack_b->size + 1)
			prev_pivot = stack_a->size + stack_b->size;
		pivot = pivot >> 1;
//		fprintf(stderr, "pivot = %d\n", pivot);
//		fprintf(stderr, "prev pivot = %d\n\n", prev_pivot);
		if (*(uint32_t *)node->data < prev_pivot
				&& *(uint32_t *)node->data >= pivot)
			break ;
	}
	if (*(uint32_t *)stack_a->end->data > pivot && *(uint32_t *)stack_a->end->data < prev_pivot)
		return (prev_pivot - *(uint32_t *)stack_a->end->data);
	return (prev_pivot - pivot);
}

/* ************************************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_intervall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 00:05:08 by agautier          #+#    #+#             */
/*   Updated: 2021/10/01 19:06:24 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

///*
//**	Return pivot intervall depending on current position on list.
//*/
//uint16_t	find_intervall(t_ps *ps, t_node *node, uint8_t deepness)
//{
//	uint32_t	pivot;
//	uint32_t	prev_pivot;
//	t_list	*stack_a;
//	t_list	*stack_b;
//
//	stack_a = ps->a;
//	stack_b = ps->b;
////	fprintf(stderr, "node = %d\n", *(uint32_t *)node->data);
//	pivot = stack_a->size + stack_b->size + 1;
//	while (pivot > 1 || deepness)
//	{
//		prev_pivot = pivot;
//		if (prev_pivot == stack_a->size + stack_b->size + 1)
//			prev_pivot = stack_a->size + stack_b->size;
//		pivot = pivot >> 1;
////		fprintf(stderr, "pivot = %d\n", pivot);
////		fprintf(stderr, "prev pivot = %d\n\n", prev_pivot);
//		if (*(uint32_t *)node->data < prev_pivot
//				&& *(uint32_t *)node->data >= pivot && !deepness)
//			break ;
//		deepness -= 1;
//	}
//	if (*(uint32_t *)stack_a->end->data > pivot && *(uint32_t *)stack_a->end->data < prev_pivot)
//		pivot = *(uint32_t *)stack_a->end->data;
//	return (prev_pivot - pivot);
//}

/*
**	Return pivot intervall depending on current position on list.
*/
uint16_t	find_intervall(t_ps *ps, t_node *node, uint8_t deepness)
{
	uint32_t	pivot;
	uint32_t	prev_pivot;
	uint32_t	data;
	t_list		*stack_a;
	t_list		*stack_b;

	stack_a = ps->a;
	stack_b = ps->b;
	data = *(uint32_t *)node->data;

	fprintf(stderr, "deepness = %d\n", deepness);

	if (deepness > 1) // TODO: un pivot sur A et les autres sur B
	{
		while (deepness > 1)
		{
			pivot = ((stack_a->size + stack_b->size + 1) >> 1) + (stack_a->size >> 1);
			prev_pivot = stack_a->size + stack_b->size;
			while (deepness && prev_pivot - pivot > 1 && data >= prev_pivot && data < pivot)
			{
				prev_pivot = pivot;
				pivot = pivot >> 1;
			}
			deepness -= 1;
		}
	}
	if (deepness == 1) // TODO: les pivots sont juste bases sur la taille de la liste globale
	{
		pivot = (stack_a->size + stack_b->size + 1) >> 1;
		prev_pivot = stack_a->size + stack_b->size;
		while (prev_pivot - pivot > 1 && (data >= prev_pivot || data < pivot))
		{
			prev_pivot = pivot;
			pivot = pivot >> 1;
		}
	}
	return (prev_pivot - pivot);
}

//pivot plus grand sur A => petites valeures sur B
//pivot plus petit deja trie

//pour chaque deepness 1 pivot sur A pivot sur B until intervall 1

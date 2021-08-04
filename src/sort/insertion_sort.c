/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 16:12:14 by agautier          #+#    #+#             */
/*   Updated: 2021/08/04 14:48:32 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	TODO: add_pivot
*/
static t_bool	add_pivot(t_gc *gc, t_list **a, t_list **b, t_list **out)
{
	(void)gc;
	(void)a;
	(void)b;
	(void)out;
	return (TRUE);
}

/*
**	TODO: a little naive.. need optimization
**	pb while != last value + 1
**	rra
**	put back all b in a
*/
static t_bool	insertion_sort(t_gc *gc, t_list **a, t_list **b, t_list **out)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = *a;
	stack_b = *b;
	// tant que pas pivot sup
	// si pas la valeur attendue (*(uint32_t *)stack_a->end->data + 1) pb
	// si valeur attendue rra
	// si prochaine valeur attendue
	fprintf(stderr, "greater pivot = %d\n", get_greater_pivot(stack_a, stack_a->begin));
	while (*(uint32_t *)stack_a->begin->data >
			*(uint32_t *)stack_a->end->data + 1)
	{
		if (!pb(gc, a, b, out))
			return (FALSE);
	}
	if (!rra(gc, a, b, out))
		return (FALSE);
//	while (stack_b->size)	// TODO: remove juste for test
//	{
//		if (!pa(gc, a, b, out))
//			return (FALSE);
//	}
	return (TRUE);
}

/*
**	Create a new pivot if intervall is big, else apply insertion sort.
*/
t_bool	prep_insertion_sort(t_gc *gc, t_list **a, t_list **b, t_list **out)
{
	t_list	*stack_a;
	uint8_t	pivot_intervall;

	stack_a = *a;
	list_print(stack_a);
//	while (!is_sorted(stack_a))
//	{
//		TODO: put in insertion_sort
//		if (*(uint32_t *)stack_a->begin->data == 1 ||
//				*(uint32_t *)stack_a->begin->data ==
//				*(uint32_t *)stack_a->end->data + 1)	// is needed value
//		{
//			if (!rra(gc, a, b, out))
//				return (FALSE);
//			continue ;
//		}
		pivot_intervall = find_intervall(stack_a, stack_a->begin);
		fprintf(stderr, "pivot intervall = %d\n", pivot_intervall);
		if (pivot_intervall < stack_a->size / 2)	// TODO: find magic value
		{
			fprintf(stderr, "insertion_sort\n");
			if (!insertion_sort(gc, a, b, out))
				return (FALSE);
		}
		else
		{
			// TODO: make new pivot (in is_pivot too)
			fprintf(stderr, "new pivot\n");
			if (!add_pivot(gc, a, b, out))
				return (FALSE);
//			break ;
		}
		list_print(stack_a);
//	}
	return (TRUE);
}

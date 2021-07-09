/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 12:06:35 by agautier          #+#    #+#             */
/*   Updated: 2021/07/09 13:11:24 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	Apply quick sort for list longer than 5 elements.
*/
t_bool	quick_sort(t_gc *gc, t_list **a, t_list **b, t_list **out)
{
	t_list		*stack_a;
	t_node		*curr;
	uint32_t	median;
	uint8_t		i;

	stack_a = *a;
	median = get_median(stack_a);
	fprintf(stderr, "median = %u\n", median);
	curr = stack_a->begin;
	i = stack_a->size;
	while (curr && i)
	{
		fprintf(stderr, "curr = %u\n", *(uint32_t *)curr->data);
		if (*(uint32_t *)curr->data < median)
			if (!pb(gc, a, b, out))
				return (FALSE);
		if (*(uint32_t *)curr->data >= median)
			if (!ra(gc, a, b, out))
				return (FALSE);
		curr = stack_a->begin;
		i -= 1;
	}

	fprintf(stderr, "stack_a\n");
	list_print(stack_a);
	fprintf(stderr, "stack_b\n");
	list_print(*b);
	return (TRUE);
}

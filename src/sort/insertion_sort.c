/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 16:12:14 by agautier          #+#    #+#             */
/*   Updated: 2021/07/09 17:21:56 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	
*/
static t_bool	is_sorted(t_list *list)
{
	t_node	*curr;

	curr = list->begin;
	while (curr)
	{
		if (curr->next &&
				*(uint32_t *)curr->data > *(uint32_t *)curr->next->data)
			return (FALSE);
		curr = curr->next;
	}
	return (TRUE);
}

/*
**	
*/
static t_bool	insertion_sort(t_gc *gc, t_list **a, t_list **b, t_list **out)
{
	t_list	*stack_a;
	t_list	*stack_b;

	fprintf(stderr, "insertion_sort\n");

	stack_a = *a;
	stack_b = *b;
	while (*(uint32_t *)stack_a->begin->data >
			*(uint32_t *)stack_a->end->data + 1)
	{
		if (!pb(gc, a, b, out))
			return (FALSE);
	}
	if (!rra(gc, a, b, out))
		return (FALSE);
	while (stack_b->size)	// TODO: remove juste for test
	{
		if (!pa(gc, a, b, out))
			return (FALSE);
	}
	return (TRUE);
}

/*
**	
*/
t_bool	prep_insertion_sort(t_gc *gc, t_list **a, t_list **b, t_list **out)
{
	t_list	*stack_a;
	uint8_t	pivot_intervall;

	stack_a = *a;
	while (!is_sorted(stack_a))
	{
		if (*(uint32_t *)stack_a->begin->data == 1 ||
				*(uint32_t *)stack_a->begin->data ==
				*(uint32_t *)stack_a->end->data + 1)
		{
			if (!rra(gc, a, b, out))
				return (FALSE);
			continue ;
		}
		pivot_intervall = -1;	// TODO: find magic value
		if (pivot_intervall > stack_a->size / 4)	// TODO: find magic value
		{
			if (!insertion_sort(gc, a, b, out))
				return (FALSE);
		}
		else
		{
			// TODO: make new pivot
			fprintf(stderr, "new pivot\n");
		}
	}
	return (TRUE);
}

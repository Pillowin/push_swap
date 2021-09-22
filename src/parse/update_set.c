/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 12:57:10 by agautier          #+#    #+#             */
/*   Updated: 2021/09/22 16:41:32 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	Count number bigger than nbr in list.
*/
static uint16_t	count_bigger(t_list *list, int nbr)
{
	t_node	*curr;
	uint16_t	count;

	count = 0;
	curr = list->begin;
	while (curr)
	{
		if (*(int *)curr->data > nbr)
			count += 1;
		curr = curr->next;
	}
	return (count);
}

/*
**	Create a new stack with updated set of number.
**	Numbers are transform to only postive with an interval of 1.
*/
t_bool	update_set(t_gc *gc, t_list **a)
{
	uint32_t	*nbr;
	t_list		*new;
	t_list		*stack_a;
	t_node		*curr;

	stack_a = *a;
	new = list_new(gc);
	if (!new)
		return (FALSE);
	curr = stack_a->begin;
	while (curr)
	{
		nbr = (uint32_t *)gc_calloc(gc, 1, sizeof(*nbr));
		if (!nbr)
			return (FALSE);
		*nbr = stack_a->size - count_bigger(stack_a, *(int *)curr->data);
		if (!list_push_back(gc, &new, nbr))
			return (FALSE);
		curr = curr->next;
	}
	list_del(gc, a);
	*a = new;
	return (TRUE);
}

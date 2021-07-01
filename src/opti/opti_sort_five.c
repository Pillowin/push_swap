/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti_sort_five.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 18:11:23 by agautier          #+#    #+#             */
/*   Updated: 2021/07/01 18:32:36 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	Delete next nb op.
*/
static t_node	*del_nexts_op(t_gc *gc, t_list **out, t_node *prev, uint8_t nb)
{
	uint8_t	i;

	i = 0;
	while (i < nb)
	{
		prev = node_del(gc, out, prev);
		i += 1;
	}
	return (prev);
}

/*
**	Update size for each push op.
*/
static int8_t	get_size(char *data)
{
	if (ft_strcmp(data, "pa"))
		return (-1);
	if (ft_strcmp(data, "pb"))
		return (1);
	return (0);
}

/*
**	Opti output of five list sort.
*/
void	opti_sort_five(t_gc *gc, t_list *a, t_list **out)
{
	t_node		*prev;
	t_node		*curr;
	uint8_t		seq;
	uint16_t	size;

	size = a->size;
	prev = NULL;
	curr = (*out)->begin;
	while (curr)
	{
		size += get_size(curr->data);
		seq = get_sequence(curr);
		if (seq == size)
			curr = del_nexts_op(gc, out, prev, seq);
		else if (seq > (size + size % 2) / 2 || (size == 3 && seq == 2))
		{
			curr = del_nexts_op(gc, out, curr, seq - 1);
			if (!ft_strcmp(curr->data, "ra"))
				curr->data = "rra";
			else if (!ft_strcmp(curr->data, "rra"))
				curr->data = "ra";
		}
		prev = curr;
		curr = curr->next;
	}
}

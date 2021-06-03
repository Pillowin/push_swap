/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 19:13:25 by agautier          #+#    #+#             */
/*   Updated: 2021/06/03 15:12:03 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	
*/
void	opti_out(t_gc *gc, t_list **out)
{
	t_list	*list;
	t_node	*prev;
	t_node	*curr;
	t_bool	updated;

	list = *out;
	updated = 1;
	prev = NULL;
	curr = list->begin;
	while (updated)
	{
		updated = 0;
		while (curr)
		{
			if (del_swap(gc, out, prev, curr) || del_rotate(gc, out, prev, curr)
					|| del_push(gc, out, prev, curr))
			{
				updated = 1;
				prev = NULL;
				curr = list->begin;
				continue ;
			}
			prev = curr;
			curr = curr->next;
		}
		if (updated)
			continue ;
		prev = NULL;
		curr = list->begin;
		while (curr)
		{
			if (conv_swap(gc, out, prev, curr)
					|| conv_rotate(gc, out, prev, curr))
			{
				updated = 1;
				prev = NULL;
				curr = list->begin;
				continue ;
			}
			prev = curr;
			curr = curr->next;
		}
		if (updated)
			continue ;
		prev = NULL;
		curr = list->begin;
		while (curr)
		{
			updated = 0;
			if (del_duplicates(gc, out, prev, curr))
			{
				updated = 1;
				prev = NULL;
				curr = list->begin;
				continue ;
			}
			prev = curr;
			curr = curr->next;
		}
	}
}

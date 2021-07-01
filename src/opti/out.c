/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 19:13:25 by agautier          #+#    #+#             */
/*   Updated: 2021/07/01 12:26:05 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	Delete unneeded operations.
*/
static t_bool	opti_del(t_gc *gc, t_list **out)
{
	t_node	*prev;
	t_node	*curr;
	t_bool	updated;
	t_list	*list;

	list = *out;
	updated = FALSE;
	prev = NULL;
	curr = list->begin;
	while (curr)
	{
		if (del_swap(gc, out, prev, curr) || del_rotate(gc, out, prev, curr)
			|| del_push(gc, out, prev, curr))
		{
			updated = TRUE;
			prev = NULL;
			curr = list->begin;
			continue ;
		}
		prev = curr;
		curr = curr->next;
	}
	return (updated);
}

/*
**	Convert multiple operations to a single one.
*/
static t_bool	opti_conv(t_gc *gc, t_list **out)
{
	t_node	*prev;
	t_node	*curr;
	t_bool	updated;
	t_list	*list;

	list = *out;
	updated = FALSE;
	prev = NULL;
	curr = list->begin;
	while (curr)
	{
		if (conv_swap(gc, out, prev, curr)
			|| conv_rotate(gc, out, prev, curr))
		{
			updated = TRUE;
			prev = NULL;
			curr = list->begin;
			continue ;
		}
		prev = curr;
		curr = curr->next;
	}
	return (updated);
}

/*
**	Delete operations when the next one cancel the current one.
*/
static t_bool	opti_del_dup(t_gc *gc, t_list **out)
{
	t_node	*prev;
	t_node	*curr;
	t_bool	updated;
	t_list	*list;

	list = *out;
	updated = FALSE;
	prev = NULL;
	curr = list->begin;
	while (curr)
	{
		updated = FALSE;
		if (del_duplicates(gc, out, prev, curr))
		{
			updated = TRUE;
			prev = NULL;
			curr = list->begin;
			continue ;
		}
		prev = curr;
		curr = curr->next;
	}
	return (updated);
}

/*
**	Factor output list.
*/
void	opti_out(t_gc *gc, t_list **out)
{
	while (opti_del(gc, out) && opti_conv(gc, out) && opti_del_dup(gc, out))
		;
}

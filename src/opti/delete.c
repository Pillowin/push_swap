/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 12:33:52 by agautier          #+#    #+#             */
/*   Updated: 2021/06/27 21:19:00 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	Delete both when doing `sa` or `sb` twice.
*/
t_bool	del_swap(t_gc *gc, t_list **alist, t_node *prev, t_node *curr)
{
	t_node	*next;
	char	*curr_data;
	char	*next_data;

	next = curr->next;
	if (!next)
		return (FALSE);
	curr_data = (char *)curr->data;
	next_data = (char *)next->data;
	if ((!ft_strcmp(curr_data, "sa") && !ft_strcmp(next_data, "sa"))
		|| (!ft_strcmp(curr_data, "sb") && !ft_strcmp(next_data, "sb")))
	{
		prev = node_del(gc, alist, prev);
		prev = node_del(gc, alist, prev);
		return (TRUE);
	}
	return (FALSE);
}

/*
**	Delete both when `pa` is near `pb`.
*/
t_bool	del_push(t_gc *gc, t_list **alist, t_node *prev, t_node *curr)
{
	t_node	*next;
	char	*curr_data;
	char	*next_data;

	next = curr->next;
	if (!next)
		return (FALSE);
	curr_data = (char *)curr->data;
	next_data = (char *)next->data;
	if ((!ft_strcmp(curr_data, "pa") && !ft_strcmp(next_data, "pb"))
		|| (!ft_strcmp(curr_data, "pb") && !ft_strcmp(next_data, "pa")))
	{
		prev = node_del(gc, alist, prev);
		prev = node_del(gc, alist, prev);
		return (TRUE);
	}
	return (FALSE);
}

/*
**	Delete when `ra` is near `rra` or `rb` near `rrb`.
*/
t_bool	del_rotate(t_gc *gc, t_list **alist, t_node *prev, t_node *curr)
{
	t_node	*next;
	char	*curr_data;
	char	*next_data;

	next = curr->next;
	if (!next)
		return (FALSE);
	curr_data = (char *)curr->data;
	next_data = (char *)next->data;
	if (((!ft_strcmp(curr_data, "ra") && !ft_strcmp(next_data, "rra"))
			|| (!ft_strcmp(curr_data, "rra") && !ft_strcmp(next_data, "ra")))
		|| ((!ft_strcmp(curr_data, "rb") && !ft_strcmp(next_data, "rrb"))
			|| (!ft_strcmp(curr_data, "rrb") && !ft_strcmp(next_data, "rb"))))
	{
		prev = node_del(gc, alist, prev);
		prev = node_del(gc, alist, prev);
		return (TRUE);
	}
	return (FALSE);
}

/*
**	Delete when `ss` twice or `rr` is near `rrr`.
*/
t_bool	del_duplicates(t_gc *gc, t_list **alist, t_node *prev, t_node *curr)
{
	t_node	*next;
	char	*curr_data;
	char	*next_data;

	next = curr->next;
	if (!next)
		return (FALSE);
	curr_data = (char *)curr->data;
	next_data = (char *)next->data;
	if ((!ft_strcmp(curr_data, "ss") && !ft_strcmp(next_data, "ss"))
		|| (!ft_strcmp(curr_data, "rr") && !ft_strcmp(next_data, "rrr"))
		|| (!ft_strcmp(curr_data, "rrr") && !ft_strcmp(next_data, "rr")))
	{
		prev = node_del(gc, alist, prev);
		prev = node_del(gc, alist, prev);
		return (TRUE);
	}
	return (FALSE);
}

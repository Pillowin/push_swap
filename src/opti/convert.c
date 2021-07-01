/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 12:52:44 by agautier          #+#    #+#             */
/*   Updated: 2021/06/27 21:18:20 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	Convert `sa` near `sb` to `ss`.
*/
t_bool	conv_swap(t_gc *gc, t_list **alist, t_node *prev, t_node *curr)
{
	t_node	*next;
	char	*curr_data;
	char	*next_data;

	next = curr->next;
	if (!next)
		return (FALSE);
	curr_data = (char *)curr->data;
	next_data = (char *)next->data;
	if ((!ft_strcmp(curr_data, "sa") && !ft_strcmp(next_data, "sb"))
		|| (!ft_strcmp(curr_data, "sb") && !ft_strcmp(next_data, "sa")))
	{
		prev = node_del(gc, alist, curr);
		prev->data = "ss";
		return (TRUE);
	}
	return (FALSE);
}

/*
**	Convert when `ra` is near `rb` or `rra` near `rrb`.
*/
t_bool	conv_rotate(t_gc *gc, t_list **alist, t_node *prev, t_node *curr)
{
	t_node	*next;
	char	*curr_data;
	char	*next_data;

	next = curr->next;
	if (!next)
		return (FALSE);
	curr_data = (char *)curr->data;
	next_data = (char *)next->data;
	if ((!ft_strcmp(curr_data, "ra") && !ft_strcmp(next_data, "rb"))
		|| (!ft_strcmp(curr_data, "rb") && !ft_strcmp(next_data, "ra")))
	{
		prev = node_del(gc, alist, curr);
		prev->data = "rr";
		return (TRUE);
	}
	if ((!ft_strcmp(curr_data, "rra") && !ft_strcmp(next_data, "rrb"))
		|| (!ft_strcmp(curr_data, "rrb") && !ft_strcmp(next_data, "rra")))
	{
		prev = node_del(gc, alist, curr);
		prev->data = "rrr";
		return (TRUE);
	}
	return (FALSE);
}

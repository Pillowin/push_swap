/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 18:06:48 by agautier          #+#    #+#             */
/*   Updated: 2021/07/01 18:06:57 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	Return TRUE if list is sorted, else return FALSE.
*/
t_bool	is_sorted(t_list *list)
{
	t_node	*curr;

	curr = list->begin;
	while (curr && curr->next)
	{
		if (is_great(curr, curr->next))
			return (FALSE);
		curr = curr->next;
	}
	return (TRUE);
}

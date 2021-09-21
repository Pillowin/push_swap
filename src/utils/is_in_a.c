/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_in_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 12:19:10 by agautier          #+#    #+#             */
/*   Updated: 2021/09/14 12:36:47 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	Return TRUE if value is in stack A, FALSE otherwise.
*/
t_bool	is_in_a(t_ps *ps, uint32_t value)
{
	t_node	*curr;

	curr = ps->a->begin;
	while (curr)
	{
		if (*(uint32_t *)curr->data == value)
			return (TRUE);
		curr = curr->next;
	}
	return (FALSE);
}

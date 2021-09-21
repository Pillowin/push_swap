/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_pivot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 22:43:25 by agautier          #+#    #+#             */
/*   Updated: 2021/08/09 17:37:22 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	Return TRUE if nbr is a pivot else returns FALSE.
**	TODO: add rule to subdivision pivots.
*/
t_bool	is_pivot(t_list *list, uint32_t nbr)
{
	uint32_t	pivot;

	pivot = list->size >> 1;
	while (pivot)
	{
		if (nbr == pivot)
			return (TRUE);
		pivot = pivot >> 1;
	}
	return (FALSE);
}

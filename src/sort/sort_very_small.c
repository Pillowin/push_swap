/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_very_small.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 13:54:58 by agautier          #+#    #+#             */
/*   Updated: 2021/08/23 18:39:12 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	Optimized sort for stack under 5 elements.
*/
t_bool	sort_very_small(t_ps *ps)
{
	if (ps->a->size == 2)
	{
		if (!sort_two(ps))
			return (FALSE);
	}
	if (ps->a->size <= 3)
	{
		if (!sort_three(ps))
			return (FALSE);
	}
	else if (ps->a->size <= 5)
	{
		if (!sort_five(ps))
			return (FALSE);
	}
	return (TRUE);
}

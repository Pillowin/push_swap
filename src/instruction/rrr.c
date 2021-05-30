/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 19:01:46 by agautier          #+#    #+#             */
/*   Updated: 2021/05/30 21:08:21 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	rra and rrb at the same time.
*/
t_bool	rrr(t_gc *gc, t_list **a, t_list **b, t_list **output)
{
	if (!rra(gc, a, b, output))
		return (FALSE);
	if (!rrb(gc, a, b, output))
		return (FALSE);
	if (!list_push_back(gc, output, "rrr"))
		return (FALSE);
	return (TRUE);
}

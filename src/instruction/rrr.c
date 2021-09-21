/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 19:01:46 by agautier          #+#    #+#             */
/*   Updated: 2021/08/23 19:18:17 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	rra and rrb at the same time.
*/
t_bool	rrr(t_ps *ps)
{
	if (!rra(ps))
		return (FALSE);
	if (!rrb(ps))
		return (FALSE);
	if (!list_push_back(ps->gc, &ps->out, "rrr"))
		return (FALSE);
	return (TRUE);
}

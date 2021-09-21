/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 18:58:27 by agautier          #+#    #+#             */
/*   Updated: 2021/08/23 19:17:45 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	ra and rb at the same time.
*/
t_bool	rr(t_ps *ps)
{
	if (!ra(ps))
		return (FALSE);
	if (!rb(ps))
		return (FALSE);
	if (!list_push_back(ps->gc, &ps->out, "rr"))
		return (FALSE);
	return (TRUE);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 18:58:27 by agautier          #+#    #+#             */
/*   Updated: 2021/05/31 12:28:44 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	ra and rb at the same time.
*/
t_bool	rr(t_gc *gc, t_list **a, t_list **b, t_list **out)
{
	if (!ra(gc, a, b, out))
		return (FALSE);
	if (!rb(gc, a, b, out))
		return (FALSE);
	if (!list_push_back(gc, out, "rr"))
		return (FALSE);
	return (TRUE);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 18:58:27 by agautier          #+#    #+#             */
/*   Updated: 2021/05/30 21:01:16 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	ra and rb at the same time.
*/
t_bool	rr(t_gc *gc, t_list **a, t_list **b, t_list **output)
{
	if (!ra(gc, a, b, output))
		return (FALSE);
	if (!rb(gc, a, b, output))
		return (FALSE);
	if (!list_push_back(gc, output, "rr"))
		return (FALSE);
	return (TRUE);
}

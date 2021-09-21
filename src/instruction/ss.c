/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 18:43:34 by agautier          #+#    #+#             */
/*   Updated: 2021/08/23 20:22:03 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	sa and sb at the same time.
*/
t_bool	ss(t_ps *ps)
{
	if (!sa(ps))
		return (FALSE);
	if (!sb(ps))
		return (FALSE);
	if (!list_push_back(ps->gc, &ps->out, "ss"))
		return (FALSE);
	return (TRUE);
}

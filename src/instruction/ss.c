/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 18:43:34 by agautier          #+#    #+#             */
/*   Updated: 2021/05/31 12:29:37 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	sa and sb at the same time.
*/
t_bool	ss(t_gc *gc, t_list **a, t_list **b, t_list **out)
{
	if (!sa(gc, a, b, out))
		return (FALSE);
	if (!sb(gc, a, b, out))
		return (FALSE);
	if (!list_push_back(gc, out, "ss"))
		return (FALSE);
	return (TRUE);
}

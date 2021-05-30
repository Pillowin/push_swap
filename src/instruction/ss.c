/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 18:43:34 by agautier          #+#    #+#             */
/*   Updated: 2021/05/30 21:12:14 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	sa and sb at the same time.
*/
t_bool	ss(t_gc *gc, t_list **a, t_list **b, t_list **output)
{
	if (!sa(gc, a, b, output))
		return (FALSE);
	if (!sb(gc, a, b, output))
		return (FALSE);
	if (!list_push_back(gc, output, "ss"))
		return (FALSE);
	return (TRUE);
}

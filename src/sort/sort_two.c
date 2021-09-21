/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 17:05:36 by agautier          #+#    #+#             */
/*   Updated: 2021/08/21 20:04:30 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	
*/
t_bool	sort_two(t_ps *ps)
{
	if (is_great(ps->a->begin, ps->a->end))
		if (!sa(ps))
			return (FALSE);
	return (TRUE);
}

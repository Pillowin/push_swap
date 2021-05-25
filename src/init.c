/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 22:14:33 by agautier          #+#    #+#             */
/*   Updated: 2021/05/25 22:19:11 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	Init stack `a` from argv.
**	TODO: check for errors
*/

t_bool	init_a(t_gc *gc, t_list **a, int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if (!list_push_back(gc, a, argv[i]))
		{
			gc_clear(gc);
			return (FALSE);
		}
		i++;
	}
	return (TRUE);
}

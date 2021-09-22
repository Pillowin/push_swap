/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 12:02:01 by agautier          #+#    #+#             */
/*   Updated: 2021/09/22 16:32:27 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	Return TRUE if nbr is already in list, else return FALSE.
*/
static t_bool	is_duplicate(t_list *a, int nbr)
{
	t_node	*curr;

	curr = a->begin;
	while (curr)
	{
		if (*(int *)(curr->data) == nbr)
			return (TRUE);
		curr = curr->next;
	}
	return (FALSE);
}

/*
**	Fill stack `a` from arguments.
*/
t_bool	parse(t_gc *gc, t_list **a, int argc, char **argv)
{
	int			*nbr;
	uint16_t	i;

	i = 0;
	while (i < argc - 1)
	{
		if (!is_int(argv[i]))
			return (FALSE);
		nbr = (int *)gc_calloc(gc, 1, sizeof(*nbr));
		if (!nbr)
			return (FALSE);
		*nbr = ft_atoi(argv[i]);
		if (is_duplicate(*a, *nbr))
			return (FALSE);
		if (!list_push_back(gc, a, nbr))
			return (FALSE);
		i++;
	}
	if (!update_set(gc, a))
		return (FALSE);
	return (TRUE);
}

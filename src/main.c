/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 18:25:43 by agautier          #+#    #+#             */
/*   Updated: 2021/10/06 21:01:32 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	Init push_swap struct named ps by creating its lists.
*/
static t_bool	ps_init(t_ps **ps)
{
	(*ps)->a = list_new((*ps)->gc);
	if (!(*ps)->a)
		return (FALSE);
	(*ps)->b = list_new((*ps)->gc);
	if (!(*ps)->b)
		return (FALSE);
	(*ps)->pivot = list_new((*ps)->gc);
	if (!(*ps)->pivot)
		return (FALSE);
	(*ps)->out = list_new((*ps)->gc);
	if (!(*ps)->out)
		return (FALSE);
	return (TRUE);
}

/*
**	Init gc, both stacks then starts push_swap.
*/
int	main(int argc, char **argv)
{
	t_ps	*ps;

	if (argc < 2)
		return (EXIT_SUCCESS);
	ps = &((t_ps){NULL, NULL, NULL, NULL, NULL});
	ps->gc = gc_new(&((t_gc){NULL, 0, 0}));
	if (!ps->gc)
		return (EXIT_FAILURE);
	if (!ps_init(&ps))
		return (exit_failure(ps->gc));
	if (!parse(ps->gc, &(ps->a), argc, argv + 1))
		return (exit_failure(ps->gc));
	if (ps->a->size <= 1)
		return (exit_success(ps->gc));
	else if (ps->a->size <= 5)
		sort_very_small(ps);
	else
		quick_sort(ps);
	opti_out(ps->gc, &ps->out);
	print_out(ps->out);
	return (exit_success(ps->gc));
}

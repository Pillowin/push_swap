/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 18:25:43 by agautier          #+#    #+#             */
/*   Updated: 2021/10/01 19:06:45 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	Print out list which contains instructions.
*/
static void	print_out(t_list *out)
{
	t_node	*curr;

	curr = out->begin;
	while (curr)
	{
		printf("%s\n", (char *)curr->data);
		curr = curr->next;
	}
}

/*
**	Init gc, both stacks then starts push_swap.
*/
int	main(int argc, char **argv)
{
	t_ps	ps;

	if (argc < 2)
		return (EXIT_SUCCESS);

	ps = (t_ps){NULL, NULL, NULL, NULL};
	ps.gc = gc_new(&((t_gc){NULL, 0, 0}));
	if (!ps.gc)
		return (EXIT_FAILURE);
	ps.a = list_new(ps.gc);
	if (!ps.a)
		return (exit_failure(ps.gc));
	ps.b = list_new(ps.gc);
	if (!ps.b)
		return (exit_failure(ps.gc));
	ps.out = list_new(ps.gc);
	if (!ps.out)
		return (exit_failure(ps.gc));

	if (!parse(ps.gc, &(ps.a), argc, argv + 1))	// TODO: change params
		return (exit_failure(ps.gc));

	if (ps.a->size <= 1)
		return (exit_success(ps.gc));
	else if (ps.a->size <= 5)
		sort_very_small(&ps);
	else
		quick_sort(&ps);

	opti_out(ps.gc, &ps.out);
	print_out(ps.out);

	return (exit_success(ps.gc));
}

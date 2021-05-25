/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 18:25:43 by agautier          #+#    #+#             */
/*   Updated: 2021/05/25 22:47:42 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


/*
**	Init gc, both stacks then starts push_swap.
*/

int	main(int argc, char **argv)
{
	t_gc	*gc;
	t_list	*a;
	t_list	*b;

	if (argc <= 2)
		return (EXIT_SUCCESS);
	gc = gc_new(&((t_gc){NULL, 0, 0}));
	if (!gc)
		return (EXIT_FAILURE);
	a = list_new(gc);
	if (!a)
		return (exit_failure(gc));
	b = list_new(gc);
	if (!b)
		return (exit_failure(gc));
	if (!init_a(gc, &a, argc, argv + 1))
		return (exit_failure(gc));
	list_print(a);
	sa(gc, &a, &b);
	list_print(a);
	return (exit_success(gc));
}

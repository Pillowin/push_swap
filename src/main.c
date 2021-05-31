/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 18:25:43 by agautier          #+#    #+#             */
/*   Updated: 2021/05/31 13:54:44 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	Print out list which contains instructions.
*/
static	void	print_out(t_list *out)
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
	t_gc	*gc;
	t_list	*out;
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
	out = list_new(gc);
	if (!out)
		return (exit_failure(gc));

	if (!parse(gc, &a, argc, argv + 1))
		return (exit_failure(gc));

	printf("stack a\n");
	list_print(a);
//	printf("\nstack b\n");
//	list_print(b);

	if (a->size <= 5)
		sort_very_small(gc, &a, &b, &out);

	printf("\n--------------\n");
	printf("out\n");
	print_out(out);

	printf("\n--------------\n");
	printf("stack a\n");
	list_print(a);
//	printf("\nstack b\n");
//	list_print(b);

	return (exit_success(gc));
}

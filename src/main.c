/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 18:25:43 by agautier          #+#    #+#             */
/*   Updated: 2021/05/25 21:44:04 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_gc	*gc;
	t_list	*a;
	int		i;
	int		j;
	int		k;

	(void)argc;
	(void)argv;
	
	gc = gc_new(&((t_gc){NULL, 0, 0}));
	if (!gc)
		return (EXIT_FAILURE);
	a = list_new(gc);
	if (!a)
	{
		gc_clear(gc);
		return (EXIT_FAILURE);
	}
	i = 5;
	list_push_back(gc, &a, &i);
	j = 6;
	list_push_back(gc, &a, &j);
	k = 7;
	list_push_back(gc, &a, &k);
	list_print(a);
	gc_clear(gc);
	return (EXIT_SUCCESS);
}

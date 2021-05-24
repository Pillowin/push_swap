/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 18:25:43 by agautier          #+#    #+#             */
/*   Updated: 2021/05/24 16:20:53 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_gc	*gc;
	char	*ptr;

	(void)argc;
	(void)argv;
	
	gc = gc_new(&((t_gc){NULL, 0, 0}));
	if (!gc)
		return (EXIT_FAILURE);
	ptr = (char *)gc_calloc(gc, 10, sizeof(char));
	if (!ptr)
		return (EXIT_FAILURE);
	ptr = "antoine\n";
	printf("%s", ptr);
	gc_clear(gc);
	return (EXIT_SUCCESS);
}

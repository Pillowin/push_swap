/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_out.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 14:52:31 by agautier          #+#    #+#             */
/*   Updated: 2021/10/11 21:29:10 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static void	ft_putstr(char *str)
{
	write(STDOUT_FILENO, str, ft_strlen(str));
	write(STDOUT_FILENO, "\n", 1);
}

/*
**	Print out list which contains instructions.
*/
void	print_out(t_list *out)
{
	t_node	*curr;

	curr = out->begin;
	while (curr)
	{
		ft_putstr(curr->data);
		curr = curr->next;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 21:29:49 by agautier          #+#    #+#             */
/*   Updated: 2021/05/27 12:48:42 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	TODO:
**	Print each data in list as char *
*/
void	list_print(t_list *list)
{
	t_node	*curr;

	curr = list->begin;
	while (curr->next)
	{
		printf("%s\n", (char *)(curr->data));
		curr = curr->next;
	}
}

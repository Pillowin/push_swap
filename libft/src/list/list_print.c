/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 21:29:49 by agautier          #+#    #+#             */
/*   Updated: 2021/09/22 16:09:27 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Print each data in list as int *
*/
void	list_print(t_list *list)
{
	t_node	*curr;

	fprintf(stderr, "size = %lu\n", list->size);
	if (!list || !(list->begin))
		return ;
	curr = list->begin;
	fprintf(stderr, "begin = %d\n", *(int *)list->begin->data);
	fprintf(stderr, "end = %d\n", *(int *)list->end->data);
	while (curr)
	{
		fprintf(stderr, "%d\n", *(int *)(curr->data));
		curr = curr->next;
	}
}

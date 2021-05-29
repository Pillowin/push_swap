/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 21:29:49 by agautier          #+#    #+#             */
/*   Updated: 2021/05/28 12:24:46 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Print each data in list as int *
*/
void	list_print(t_list *list)
{
	t_node	*curr;

	if (!list || !(list->begin))
		return ;
	curr = list->begin;
	printf("begin = %d\n", *(int *)list->begin->data);
	printf("end = %d\n", *(int *)list->end->data);
	printf("size = %lu\n", list->size);
	while (curr)
	{
		printf("%d\n", *(int *)(curr->data));
		curr = curr->next;
	}
}

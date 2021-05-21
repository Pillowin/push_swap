/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 20:22:33 by agautier          #+#    #+#             */
/*   Updated: 2021/05/21 21:06:10 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Create a new list.
*/

t_list	*list_new(void)
{
	t_list	*list;

	list = (t_list *)ft_calloc(1, sizeof(*list));
	if (!list)
		return (NULL);
	list->begin = NULL;
	list->end = NULL;
	list->size = 0;
	return (list);
}

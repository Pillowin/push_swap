/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 12:38:58 by agautier          #+#    #+#             */
/*   Updated: 2021/05/28 12:53:57 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Free a ptr, NULL it in gc array.
*/
void	gc_free(t_gc *gc, void **ptr)
{
	size_t	i;

	if (!ptr || !*ptr)
		return ;
	i = 0;
	i = 0;
	while (i < gc->head)
	{
		if (gc->ptrs[i] == *ptr)
		{
			free(gc->ptrs[i]);
			gc->ptrs[i] = NULL;
		}
		i++;
	}
}

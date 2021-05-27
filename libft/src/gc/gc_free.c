/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 12:38:58 by agautier          #+#    #+#             */
/*   Updated: 2021/05/27 12:51:14 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Free a ptr, NULL it in gc array.
*/
void	gc_free(t_gc *gc, void **ptr)
{
	unsigned int	i;

	if (!ptr || !*ptr)
		return ;
	i = 0;
	while (i < gc->head)
	{
		if (gc->ptrs[i] == ptr)
		{
			free(gc->ptrs);
			gc->ptrs = NULL;
		}
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_clear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 15:49:53 by agautier          #+#    #+#             */
/*   Updated: 2021/05/24 15:53:13 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	gc_clear(t_gc *gc)
{
	unsigned int	i;

	i = 0;
	while (i < gc->head)
	{
		if (gc->ptrs[i])
			free(gc->ptrs[i]);
		gc->ptrs [i] = NULL;
		i++;
	}
	if (gc->ptrs)
	{
		free(gc->ptrs);
		gc->ptrs = NULL;
	}
	gc->head = 0;
	gc->size = 0;
}

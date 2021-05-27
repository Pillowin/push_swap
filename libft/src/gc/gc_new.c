/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_new.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 13:30:17 by agautier          #+#    #+#             */
/*   Updated: 2021/05/27 12:51:56 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Create a new gc array.
*/
t_gc	*gc_new(t_gc *gc)
{
	gc->ptrs = (void **)malloc(sizeof(*(gc->ptrs)) * GC_SIZE);
	if (!gc->ptrs)
		return (NULL);
	gc->size = GC_SIZE;
	gc->head = 0;
	return (gc);
}

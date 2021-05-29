/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 12:01:15 by agautier          #+#    #+#             */
/*   Updated: 2021/05/28 12:48:49 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Extend the size of the garbage array.
*/
static t_gc	*gc_realloc(t_gc *gc)
{
	void			**tmp;
	unsigned int	i;

	tmp = (void **)malloc((gc->size + GC_SIZE) * sizeof(*tmp));
	if (!tmp)
		return (NULL);
	i = 0;
	while (i < gc->head)
	{
		tmp[i] = gc->ptrs[i];
		i++;
	}
	while (i < gc->size + GC_SIZE)
	{
		tmp[i] = NULL;
		i++;
	}
	free(gc->ptrs);
	gc->ptrs = tmp;
	gc->size += GC_SIZE;
	return (gc);
}

/*
**	Assign a new ptr with ft_calloc and register it to list gc.
*/
void	*gc_calloc(t_gc *gc, size_t count, size_t size)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)malloc(size * count);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < size * count)
	{
		ptr[i] = '\0';
		i++;
	}
	if (gc->head >= gc->size - 1)
	{
		gc = gc_realloc(gc);
		if (!gc)
		{
			free(ptr);
			ptr = NULL;
			return (NULL);
		}
	}
	gc->ptrs[gc->head] = ptr;
	gc->head += 1;
	return (ptr);
}

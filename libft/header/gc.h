/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 13:24:37 by agautier          #+#    #+#             */
/*   Updated: 2021/05/24 15:38:15 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GC_H
# define GC_H

# include <stdlib.h>

# define GC_SIZE 128

typedef struct s_gc
{
	void	**ptrs;
	size_t	size;
	size_t	head;
}	t_gc;

t_gc	*gc_new(t_gc *gc);
void	*gc_calloc(t_gc *gc, size_t count, size_t size);
void	gc_free(t_gc *gc, void **ptr);
void	gc_clear(t_gc *gc);

#endif

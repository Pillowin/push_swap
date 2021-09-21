/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_list.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 20:01:36 by agautier          #+#    #+#             */
/*   Updated: 2021/08/11 17:22:42 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_LIST_H
# define LIBFT_LIST_H

# include <stdlib.h>
# include "libft_gc.h"

typedef struct s_list	t_list;
typedef struct s_node	t_node;

struct s_list
{
	t_node	*begin;
	t_node	*end;
	size_t	size;
};

struct s_node
{
	void	*data;
	t_node	*next;
};

t_list	*list_new(t_gc *gc);
t_node	*node_new(t_gc *gc, void *data);

t_node	*list_push_back(t_gc *gc, t_list **alist, void *data);
t_node	*list_push_front(t_gc *gc, t_list **alist, void *data);
void	list_merge(t_list **alist1, t_list *list2);
void	list_del(t_gc *gc, t_list **alist);
t_node	*list_at(t_list *list, uint8_t index);

t_node	*node_del(t_gc *gc, t_list **alist, t_node *prev);
uint8_t	get_node_index(t_list *list, t_node *node);
t_node	*node_find(t_list *list, uint32_t data);

void	list_print(t_list *list);

#endif

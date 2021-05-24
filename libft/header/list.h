/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 20:01:36 by agautier          #+#    #+#             */
/*   Updated: 2021/05/23 13:42:22 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

#include <stdlib.h>

typedef struct s_list	t_list;
typedef struct s_node	t_node;

struct s_list
{
	t_list	*begin;
	t_list	*end;
	size_t	size;
};

struct s_node
{
	void	*data;
	t_node	*next;
};

t_list	*list_new(t_list **agc);
t_node	*node_new(t_list **agc, void *data);

t_node	*list_push_back(t_list **agc, t_list **alist, void *data);
t_node	*list_push_front(t_list **agc, t_list **alist, void *data);

#endif

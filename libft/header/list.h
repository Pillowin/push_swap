/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 20:01:36 by agautier          #+#    #+#             */
/*   Updated: 2021/05/21 20:22:52 by agautier         ###   ########.fr       */
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

t_list	*list_new(void);
t_node	*node_new(void *data);

#endif

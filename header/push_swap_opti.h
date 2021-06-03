/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_opti.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 19:14:37 by agautier          #+#    #+#             */
/*   Updated: 2021/06/03 15:02:12 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_OPTI_H
# define PUSH_SWAP_OPTI_H

typedef struct s_list	t_list;
typedef struct s_node	t_node;
typedef struct s_gc		t_gc;
typedef enum e_bool		t_bool;

void	opti_out(t_gc *gc, t_list **out);

/*
**	Delete
*/
t_bool	del_swap(t_gc *gc, t_list **alist, t_node *prev, t_node *curr);
t_bool	del_push(t_gc *gc, t_list **alist, t_node *prev, t_node *curr);
t_bool	del_rotate(t_gc *gc, t_list **alist, t_node *prev, t_node *curr);
t_bool	del_duplicates(t_gc *gc, t_list **alist, t_node *prev, t_node *curr);

/*
**	Convert
*/
t_bool	conv_swap(t_gc *gc, t_list **alist, t_node *prev, t_node *curr);
t_bool	conv_rotate(t_gc *gc, t_list **alist, t_node *prev, t_node *curr);

#endif

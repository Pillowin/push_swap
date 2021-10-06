/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 12:12:47 by agautier          #+#    #+#             */
/*   Updated: 2021/10/06 22:23:22 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_UTILS_H
# define PUSH_SWAP_UTILS_H

# include "libft.h"

typedef struct s_ps	t_ps;
typedef t_bool		(*t_op)(t_ps *ps);

t_node		*find_min(t_list *list);
uint32_t	get_median(t_list *list);
t_bool		is_pivot(t_list *list, uint32_t nbr);
t_bool		is_sorted(t_list *list);
uint16_t	find_intervall(t_ps *ps, t_node *node);
uint32_t	get_greater_pivot(t_ps *ps, t_node *node);
t_bool		is_in_a(t_ps *ps, uint32_t value);
void		print_out(t_list *out);
uint16_t	adapt_size(char *data);
t_op		get_fastest_op(t_ps *ps, t_list *list, t_node *elem);
t_bool		bigs_in_a(t_ps *ps, uint32_t median);
t_bool		smalls_in_b_qs(t_ps *ps, uint32_t median);
t_bool		smalls_in_b_is(t_ps *ps, uint32_t median);
void		invert_op(t_node *curr);

#endif

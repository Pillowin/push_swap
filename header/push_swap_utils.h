/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 12:12:47 by agautier          #+#    #+#             */
/*   Updated: 2021/09/21 15:43:04 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_UTILS_H
# define PUSH_SWAP_UTILS_H

# include "libft.h"

typedef struct s_ps	t_ps;

t_node		*find_min(t_list *list);
uint32_t	get_median(t_list *list);
t_bool		is_pivot(t_list *list, uint32_t nbr);
t_bool		is_sorted(t_list *list);
uint8_t		find_intervall(t_ps *ps, t_node *node, uint8_t deepness);
uint32_t	get_greater_pivot(t_list *list, t_node *node);
t_bool		is_in_a(t_ps *ps, uint32_t value);

#endif

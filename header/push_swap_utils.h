/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 12:12:47 by agautier          #+#    #+#             */
/*   Updated: 2021/07/01 18:14:12 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_UTILS_H
# define PUSH_SWAP_UTILS_H

# include "libft.h"

t_node	*find_min(t_list *list);
t_node	*find_max(t_list *list);
t_bool	is_sorted(t_list *list);
uint8_t	get_sequence(t_node *node);

#endif

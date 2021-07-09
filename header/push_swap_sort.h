/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 18:26:43 by agautier          #+#    #+#             */
/*   Updated: 2021/07/09 12:13:08 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_SORT_H
# define PUSH_SWAP_SORT_H

# include "libft.h"

t_bool	sort_very_small(t_gc *gc, t_list **a, t_list **b, t_list **out);

t_bool	sort_two(t_gc *gc, t_list **a, t_list **b, t_list **out);
t_bool	sort_three(t_gc *gc, t_list **a, t_list **b, t_list **out);
t_bool	sort_five(t_gc *gc, t_list **a, t_list **b, t_list **out);
t_bool	quick_sort(t_gc *gc, t_list **a, t_list **b, t_list **out);
#endif

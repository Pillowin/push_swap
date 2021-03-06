/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 18:26:43 by agautier          #+#    #+#             */
/*   Updated: 2021/10/06 14:49:52 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_SORT_H
# define PUSH_SWAP_SORT_H

# include "libft.h"

typedef struct s_ps	t_ps;

t_bool	sort_very_small(t_ps *ps);

t_bool	sort_two(t_ps *ps);
t_bool	sort_three(t_ps *ps);
t_bool	sort_five(t_ps *ps);

t_bool	quick_sort(t_ps *ps);

t_bool	prep_insertion_sort(t_ps *ps);

#endif

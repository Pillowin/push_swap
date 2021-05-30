/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_instruction.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 22:46:59 by agautier          #+#    #+#             */
/*   Updated: 2021/05/30 23:01:26 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_INSTRUCTION_H
# define PUSH_SWAP_INSTRUCTION_H

# include "libft.h"

t_bool	sa(t_gc *gc, t_list **a, t_list **b, t_list **output);
t_bool	sb(t_gc *gc, t_list **a, t_list **b, t_list **output);
t_bool	ss(t_gc *gc, t_list **a, t_list **b, t_list **output);

t_bool	pa(t_gc *gc, t_list **a, t_list **b, t_list **output);
t_bool	pb(t_gc *gc, t_list **a, t_list **b, t_list **output);

t_bool	ra(t_gc *gc, t_list **a, t_list **b, t_list **output);
t_bool	rb(t_gc *gc, t_list **a, t_list **b, t_list **output);

t_bool	rra(t_gc *gc, t_list **a, t_list **b, t_list **output);
t_bool	rrb(t_gc *gc, t_list **a, t_list **b, t_list **output);
t_bool	rrr(t_gc *gc, t_list **a, t_list **b, t_list **output);

#endif

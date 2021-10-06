/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_instruction.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 22:46:59 by agautier          #+#    #+#             */
/*   Updated: 2021/10/06 14:51:32 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_INSTRUCTION_H
# define PUSH_SWAP_INSTRUCTION_H

# include "libft.h"

typedef struct s_ps	t_ps;
typedef t_bool		(*t_op)(t_ps *ps);

t_bool	sa(t_ps *ps);
t_bool	sb(t_ps *ps);
t_bool	ss(t_ps *ps);

t_bool	pa(t_ps *ps);
t_bool	pb(t_ps *ps);

t_bool	ra(t_ps *ps);
t_bool	rb(t_ps *ps);

t_bool	rra(t_ps *ps);
t_bool	rrb(t_ps *ps);
t_bool	rrr(t_ps *ps);

#endif

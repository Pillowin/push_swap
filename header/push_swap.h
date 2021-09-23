/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 18:26:49 by agautier          #+#    #+#             */
/*   Updated: 2021/09/23 15:11:47 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include "push_swap_parse.h"
# include "push_swap_exit.h"
# include "push_swap_instruction.h"
# include "push_swap_utils.h"
# include "push_swap_sort.h"
# include "push_swap_opti.h"

# define MAGIC 15

typedef struct	s_ps
{
	t_gc	*gc;
	t_list	*a;
	t_list	*b;
	t_list	*out;
}	t_ps;

#endif

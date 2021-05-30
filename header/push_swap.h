/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 18:26:49 by agautier          #+#    #+#             */
/*   Updated: 2021/05/28 12:02:46 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include "push_swap_instruction.h"

# define FALSE	0
# define TRUE	1

/*
**	exit.c
*/
t_bool	exit_success(t_gc *gc);
t_bool	exit_failure(t_gc *gc);

/*
**	parse.c
*/
t_bool	parse(t_gc *gc, t_list **a, int argc, char **argv);

#endif

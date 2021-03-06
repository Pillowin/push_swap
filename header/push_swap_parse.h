/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parse.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 14:08:50 by agautier          #+#    #+#             */
/*   Updated: 2021/07/01 16:46:03 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_PARSE_H
# define PUSH_SWAP_PARSE_H

# include "libft.h"

t_bool	update_set(t_gc *gc, t_list **a);
t_bool	parse(t_gc *gc, t_list **a, int argc, char **argv);

#endif

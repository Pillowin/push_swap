/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_is.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 17:13:05 by agautier          #+#    #+#             */
/*   Updated: 2021/05/31 13:43:07 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_IS_H
# define LIBFT_IS_H

typedef enum e_bool		t_bool;
typedef struct s_node	t_node;

t_bool	is_int(char *str);
t_bool	is_great(t_node *a, t_node *b);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_str.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 12:20:01 by agautier          #+#    #+#             */
/*   Updated: 2021/05/30 11:57:55 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_STR_H
#define LIBFT_STR_H

typedef	enum e_bool	t_bool;

int		ft_atoi(const char *str);
t_bool	is_int(char *str);

#endif

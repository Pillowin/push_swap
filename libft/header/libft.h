/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 13:15:19 by agautier          #+#    #+#             */
/*   Updated: 2021/05/25 22:17:25 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# include "gc.h"
# include "list.h"

typedef enum e_bool
{
	FALSE = 0,
	TRUE
}	t_bool;

int	ft_atoi(const char *str);

#endif

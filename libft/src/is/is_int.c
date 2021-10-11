/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 11:52:24 by agautier          #+#    #+#             */
/*   Updated: 2021/10/11 17:13:44 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Return TRUE if c is a digit, else return FALSE.
*/
static t_bool	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

/*
**	Return TRUE if str can be stored in an int, else return FALSE.
*/
t_bool	is_int(char *str)
{
	unsigned int	res;
	uint8_t			neg;
	uint8_t			i;

	neg = 0;
	i = 0;
	if (str[i] == '-')
	{
		neg = 1;
		i++;
		if (!is_digit(str[i]))
			return (FALSE);
	}
	res = 0;
	while (str[i] && is_digit(str[i]))
	{
		if (i > 11)
			return (FALSE);
		res = res * 10 + (str[i] - '0');
		i++;
	}
	if ((str[i] && !is_digit(str[i])) || res > (uint32_t)INT_MAX + neg)
		return (FALSE);
	return (TRUE);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adapt_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 16:30:22 by agautier          #+#    #+#             */
/*   Updated: 2021/10/06 22:12:45 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	If pa list A size increase by 1, if pb list A decrease by 1.
*/
uint16_t	adapt_size(char *data)
{
	uint16_t	ret;

	ret = 0;
	if (ft_strcmp(data, "pa"))
		ret += -1;
	if (ft_strcmp(data, "pb"))
		ret += 1;
	return (ret);
}

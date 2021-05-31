/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_great.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 17:09:17 by agautier          #+#    #+#             */
/*   Updated: 2021/05/31 13:42:27 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Return TRUE if a is greater than b, else return FALSE.
*/
t_bool	is_great(t_node *a, t_node *b)
{
	return (*(int *)(a->data) > *(int *)(b->data));
}

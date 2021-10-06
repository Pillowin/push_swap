/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invert_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 22:21:04 by agautier          #+#    #+#             */
/*   Updated: 2021/10/06 22:22:56 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**
*/
void	invert_op(t_node *curr)
{
	if (!ft_strcmp(curr->data, "ra"))
		curr->data = "rra";
	else if (!ft_strcmp(curr->data, "rra"))
		curr->data = "ra";
}

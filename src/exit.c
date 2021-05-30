/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 22:12:07 by agautier          #+#    #+#             */
/*   Updated: 2021/05/28 12:15:19 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	Call gc_clear before returning EXIT_SUCCESS.
*/

t_bool	exit_success(t_gc *gc)
{
	gc_clear(gc);
	return (EXIT_SUCCESS);
}

/*
**	Call gc_clear before returning EXIT_FAILURE.
*/

t_bool	exit_failure(t_gc *gc)
{
	gc_clear(gc);
	ft_putendl_fd("Error", STDERR_FILENO);
	return (EXIT_FAILURE);
}

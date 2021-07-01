/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 11:58:17 by agautier          #+#    #+#             */
/*   Updated: 2021/07/01 18:15:39 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

/*
**	Returns fastest rotation to sort list.
*/
//char	*get_last_rotate(t_list *out)
//{
//	t_node	*curr;
//	void	*data;
//
//	data = NULL;
//	curr = out->begin;
//	while (curr)
//	{
//		if (!ft_strcmp(curr->data, "ra") || !ft_strcmp(curr->data, "rra"))
//			data = curr->data;
//		curr = curr->next;
//	}
//	return (data);
//}

/*
** Returns fastest rotation to sort list.
*/
t_op	get_fastest_op(t_list *list, t_node *elem)
{
	uint16_t	pos;
	t_node		*curr;

	curr = list->begin;
	pos = 0;
	while (elem && curr && elem && is_great(elem, curr))
	{
		pos += 1;
		curr = curr->next;
	}
	if (list->begin == curr && pos > list->size / 2)
		pos = list->size - pos;
	if (pos > list->size / 2)
		return (rra);
	return (ra);
}

/*
**
*/
static t_bool	sort_a(t_gc *gc, t_list **a, t_list **b, t_list **out)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_op	op;

	stack_a = *a;
	stack_b = *b;
	op = get_fastest_op(stack_a, stack_b->begin);
	while (!(is_sorted(stack_a) && (is_great(stack_a->begin, stack_b->begin)
				|| is_great(stack_b->begin, stack_a->end)))
		&& ((op == rra && is_great(stack_a->end, stack_b->begin))
			|| (op == ra && is_great(stack_b->begin, stack_a->begin))))
		if (!op(gc, a, b, out))
			return (FALSE);
	if (!pa(gc, a, b, out))
		return (FALSE);
	if (op == ra)
		op = rra;
	else
		op = ra;
	while (!is_sorted(stack_a))
		if (!op(gc, a, b, out))
			return (FALSE);
	return (TRUE);
}

/*
**	Push both first elements of `a` in `b`.
**	Apply sort_three.
**	Push `b` back in `a`.
*/
t_bool	sort_five(t_gc *gc, t_list **a, t_list **b, t_list **out)
{
	uint8_t	size;
	t_list	*out_tmp;

	out_tmp = list_new(gc);
	if (!out_tmp)
		return (exit_failure(gc));
	size = (*a)->size == 5;
	if (size && !pb(gc, a, b, &out_tmp))
		return (FALSE);
	if (!pb(gc, a, b, &out_tmp))
		return (FALSE);
	if (!sort_three(gc, a, b, &out_tmp))
		return (FALSE);
	if (!sort_a(gc, a, b, &out_tmp))
		return (FALSE);
	if (size && !sort_a(gc, a, b, &out_tmp))
		return (FALSE);
	opti_sort_five(gc, *a, &out_tmp);
	list_merge(out, out_tmp);
	return (TRUE);
}

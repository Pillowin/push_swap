/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 11:58:17 by agautier          #+#    #+#             */
/*   Updated: 2021/10/06 22:23:03 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**
*/
static t_bool	sort_a(t_ps *ps)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_op	op;

	stack_a = ps->a;
	stack_b = ps->b;
	op = get_fastest_op(ps, stack_a, stack_b->begin);
	while (!(is_sorted(stack_a) && (is_great(stack_a->begin, stack_b->begin)
				|| is_great(stack_b->begin, stack_a->end)))
		&& ((op == rra && is_great(stack_a->end, stack_b->begin))
			|| (op == ra && is_great(stack_b->begin, stack_a->begin))))
		if (!op(ps))
			return (FALSE);
	if (!pa(ps))
		return (FALSE);
	if (op == ra)
		op = rra;
	else
		op = ra;
	while (!is_sorted(stack_a))
		if (!op(ps))
			return (FALSE);
	return (TRUE);
}

/*
**	Returns the number of same following op.
*/
uint8_t	get_sequence(t_node *node)
{
	char	*data;
	uint8_t	i;

	if (!node)
		return (0);
	data = (char *)node->data;
	i = 0;
	while (node && !ft_strcmp(node->data, data))
	{
		i += 1;
		node = node->next;
	}
	return (i);
}

/*
**	Delete next nb op.
*/
t_node	*del_nexts_op(t_gc *gc, t_list **out, t_node *prev, uint8_t nb)
{
	uint8_t	i;

	i = 0;
	while (i < nb)
	{
		prev = node_del(gc, out, prev);
		i += 1;
	}
	return (prev);
}

/*
**	Opti output of five list sort.
*/
void	opti_sort_five(t_ps *ps)
{
	t_list		*list;
	t_node		*prev;
	t_node		*curr;
	uint8_t		seq;
	uint16_t	size;

	size = ps->a->size;
	list = ps->out;
	prev = NULL;
	curr = list->begin;
	while (curr)
	{
		size += adapt_size(curr->data);
		seq = get_sequence(curr);
		if (seq == size)
			curr = del_nexts_op(ps->gc, &ps->out, prev, seq);
		else if (seq > (size + size % 2) >> 1 || (size == 3 && seq == 2))
		{
			curr = del_nexts_op(ps->gc, &ps->out, curr, seq - 1);
			invert_op(curr);
		}
		prev = curr;
		curr = curr->next;
	}
}

/*
**	Push both first elements of `a` in `b`.
**	Apply sort_three.
**	Push `b` back in `a`.
*/
t_bool	sort_five(t_ps *ps)
{
	uint8_t	size;
	t_list	*out_tmp;

	out_tmp = list_new(ps->gc);
	if (!out_tmp)
		return (exit_failure(ps->gc));
	size = ps->a->size == 5;
	if (size && !pb(ps))
		return (FALSE);
	if (!pb(ps))
		return (FALSE);
	if (!sort_three(ps))
		return (FALSE);
	if (!sort_a(ps))
		return (FALSE);
	if (size && !sort_a(ps))
		return (FALSE);
	opti_sort_five(ps);
	list_merge(&ps->out, out_tmp);
	return (TRUE);
}

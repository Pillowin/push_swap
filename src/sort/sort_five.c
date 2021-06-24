/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 11:58:17 by agautier          #+#    #+#             */
/*   Updated: 2021/06/24 17:04:05 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

/*
** Return TRUE if list is sorted, else return FALSE.
*/
t_bool	is_sorted(t_list *list)
{
	t_node	*curr;

	curr = list->begin;
	while (curr && curr->next)
	{
		if (is_great(curr, curr->next))
			return (FALSE);
		curr = curr->next;
	}
	return (TRUE);
}

/*
** Returns fastest rotation to sort list.
*/
char	*find_last_rotate(t_list *out)
{
	t_node	*curr;
	void	*data;

	data = NULL;
	curr = out->begin;
	while (curr)
	{
		if (!ft_strcmp(curr->data, "ra") || !ft_strcmp(curr->data, "rra"))
			data = curr->data;
		curr = curr->next;
	}
	return (data);
}

/*
** Returns fastest rotation to sort list.
*/
t_op	get_fastest_op(t_list *list, t_node *elem)
{
	uint16_t	pos;
	t_node		*curr;
//	char		*op;

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
//	if (pos < list->size / 2)
//		return (ra);
//	op = find_last_rotate(out);
//	if (op && !ft_strcmp(op, "ra"))
//		return (rra);
	return (ra);
}

///*
//**
//*/
//uint16_t	find_min_pos(t_list *list)
//{
//	int			min;
//	uint16_t	pos;
//	t_node		*curr;
//
//	min = 0;
//	curr = list->begin;
//	while (curr)
//	{
//		if (!min || min > *(int *)curr->data)
//			min = *(int *)curr->data;
//		curr = curr->next;
//	}
//	pos = 0;
//	curr = list->begin;
//	while (curr && min != *(int *)curr->data)
//	{
//		pos += 1;
//		curr = curr->next;
//	}
//	return (pos);
//}

///*
//** Returns fastest rotation to sort list.
//*/
//t_op	get_fastest_op_post_pa(t_list *list, t_list *out)
//{
//	uint16_t	pos;
//	char		*op;
//
//	pos = find_min_pos(list);
//	if (pos > list->size / 2)
//		return (rra);
//	if (pos < list->size / 2)
//		return (ra);
//	op = find_last_rotate(out);
//	if (op && !ft_strcmp(op, "ra"))
//		return (rra);
//	return (ra);
//}

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
//	op = get_fastest_op_post_pa(stack_a, *out);
	if (op == ra)
		op = rra;
	else
		op = ra;
	while (!is_sorted(stack_a))
	{
		if (!op(gc, a, b, out))
			return (FALSE);
	}
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

	size = (*a)->size == 5;
	//fprintf(stderr, "-------1-------\n");
	//list_print(*a);
	if (size && !pb(gc, a, b, out))
		return (FALSE);
	//fprintf(stderr, "-------2-------\n");
	//list_print(*a);
	if (!pb(gc, a, b, out))
		return (FALSE);
	//fprintf(stderr, "-------3-------\n");
	//list_print(*a);
	if (!sort_three(gc, a, b, out))
		return (FALSE);
	//fprintf(stderr, "-------4-------\n");
	//list_print(*a);
	if (!sort_a(gc, a, b, out))
		return (FALSE);
	//fprintf(stderr, "-------5-------\n");
	//list_print(*a);
	if (size && !sort_a(gc, a, b, out))
		return (FALSE);
	//fprintf(stderr, "-------6-------\n");
	//list_print(*a);
	return (TRUE);
}

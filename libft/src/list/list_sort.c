/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 17:04:31 by agautier          #+#    #+#             */
/*   Updated: 2021/10/05 17:15:48 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	rev_elem(t_node *curr)
{
	void	*tmp;

	tmp = curr->data;
	curr->data = curr->next->data;
	curr->next->data = tmp;
}

/*
**	Trie par ordre croissant le contenu de la liste, en comparant deux
**	éléments grâce à une fonction de comparaison de données des deux éléments.
*/
void	list_sort(t_list *list, int (*cmp)())
{
	t_node	*curr;
	int		done;

	done = 0;
	while (!done)
	{
		done = 1;
		curr = list->begin;
		while (curr->next)
		{
			if (cmp(curr->data, curr->next->data))
			{
				rev_elem(curr);
				done = 0;
			}
			curr = curr->next;
		}
	}
}

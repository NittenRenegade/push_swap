/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coskelet <coskelet@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:02:48 by coskelet          #+#    #+#             */
/*   Updated: 2022/03/04 14:48:11 by coskelet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_list **lst)
{
	t_list	*tmp;

	if (NULL == (*lst)->next)
		return ;
	tmp = *lst;
	ft_lstlast(*lst)->next = *lst;
	*lst = tmp->next;
	tmp->next = NULL;
}

void	rotate_a(t_stacks *st)
{
	if (NULL == st->a)
		return ;
	rotate(&(st->a));
}

void	rotate_b(t_stacks *st)
{
	if (NULL == st->b)
		return ;
	rotate(&(st->b));
}

void	rotate_both(t_stacks *st)
{
	rotate_a(st);
	rotate_b(st);
}

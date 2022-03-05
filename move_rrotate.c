/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rrotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coskelet <coskelet@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 14:08:47 by coskelet          #+#    #+#             */
/*   Updated: 2022/03/02 14:35:00 by coskelet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rrotate(t_list **lst)
{
	t_list	*tmp_l;
	t_list	*tmp_sl;

	if (NULL == (*lst)->next)
		return ;
	tmp_sl = ft_lstsublast(*lst);
	tmp_l = ft_lstlast(*lst);
	tmp_l->next = *lst;
	*lst = tmp_l;
	tmp_sl->next = NULL;
}

void	rrotate_a(t_stacks *st)
{
	if (NULL == st->a)
		return ;
	rrotate(&(st->a));
}

void	rrotate_b(t_stacks *st)
{
	if (NULL == st->b)
		return ;
	rrotate(&(st->b));
}

void	rrotate_both(t_stacks *st)
{
	rrotate_a(st);
	rrotate_b(st);
}

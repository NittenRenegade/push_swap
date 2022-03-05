/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coskelet <coskelet@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 17:04:42 by coskelet          #+#    #+#             */
/*   Updated: 2022/02/27 17:27:41 by coskelet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list *l)
{
	void	*tmp;

	if (NULL == l->next)
		return ;
	tmp = l->content;
	l->content = l->next->content;
	l->next->content = tmp;
}

void	swap_a(t_stacks *st)
{
	swap(st->a);
}

void	swap_b(t_stacks *st)
{
	swap(st->b);
}

void	swap_both(t_stacks *st)
{
	swap_a(st);
	swap_b(st);
}

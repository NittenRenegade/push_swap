/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coskelet <coskelet@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 17:26:40 by coskelet          #+#    #+#             */
/*   Updated: 2022/03/02 13:30:32 by coskelet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_list **targ, t_list **source)
{
	t_list	*tmp;

	if (NULL == *source)
		return ;
	tmp = *targ;
	*targ = *source;
	if (NULL != *source)
		*source = (*source)->next;
	(*targ)->next = tmp;
}

void	push_a(t_stacks *st)
{
	if (NULL == st->b)
		return ;
	push(&st->a, &st->b);
	st->a_size++;
	st->b_size--;
}

void	push_b(t_stacks *st)
{
	if (NULL == st->a)
		return ;
	push(&st->b, &st->a);
	st->b_size++;
	st->a_size--;
}

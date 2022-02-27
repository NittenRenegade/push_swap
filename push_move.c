/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coskelet <coskelet@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 17:26:40 by coskelet          #+#    #+#             */
/*   Updated: 2022/02/27 18:07:15 by coskelet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **l, t_list **f)
{
	t_list	*tmp;

	tmp = *l;
	*l = *f;
	if (NULL != *f)
		*f = (*f)->next;
	(*l)->next = tmp;
}


void	push_a(t_stacks *st)
{
	push(&st->a, &st->b);
}

void	push_b(t_stacks *st)
{
	push(&st->b, &st->a);
}

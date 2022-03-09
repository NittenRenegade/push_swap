/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_comparator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coskelet <coskelet@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:01:39 by coskelet          #+#    #+#             */
/*   Updated: 2022/03/05 15:35:30 by coskelet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

short	a_a1(t_stacks *st)
{
	long	a;
	long	a1;

	if (NULL == st->a || NULL == st->a->next)
		return (0);
	a = (long)st->a->content;
	a1 = (long)st->a->next->content;
	if ((st->shrt || st->a_size <= SH_STACK) && st->a_size > 3)
	{
		find_short_boundaries(st);
		if (a >= st->sh_sigma2[1])
			move_back(st);
		a = (long)st->a->content;
		a1 = (long)st->a->next->content;
	}
	if (a > a1)
		return (1);
	else
		return (0);
}

short	b_b1(t_stacks *st)
{
	long	b;
	long	b1;

	if (NULL == st->b || NULL == st->b->next)
		return (0);
	b = (long)st->b->content;
	b1 = (long)st->b->next->content;
	if (b < b1)
		return (1);
	else
		return (0);
}

short	a_al(t_stacks *st)
{
	long	a;
	long	al;

	if (NULL == st->a || NULL == st->a->next)
		return (0);
	a = (long)st->a->content;
	al = (long)ft_lstlast(st->a)->content;
	if (a > al)
		return (1);
	else
		return (0);
}

short	b_bl(t_stacks *st)
{
	long	b;
	long	bl;

	if (NULL == st->b || NULL == st->b->next)
		return (0);
	b = (long)st->b->content;
	bl = (long)ft_lstlast(st->b)->content;
	if (b < bl)
		return (1);
	else
		return (0);
}

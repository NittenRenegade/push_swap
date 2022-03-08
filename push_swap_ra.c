/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ra.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coskelet <coskelet@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 15:45:32 by coskelet          #+#    #+#             */
/*   Updated: 2022/03/08 15:45:34 by coskelet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static short	l_need_to_ra_a(t_stacks *st)
{
	long tmp_a;

	if (st->shrt || st->a_size <= SH_STACK)
		return (0);
	tmp_a = (long) st->a->content;
	if (tmp_a >= st->sigma2[1] || (r_side(st) && tmp_a >= st->sigma[1]))
		return (1);
	else
		return (0);
}

static short	sh_need_to_ra_a(t_stacks *st)
{
	long tmp_a;

	if (!st->shrt && st->a_size >= SH_STACK)
		return (0);
	find_short_boundaries(st);
	tmp_a = (long) st->a->content;
	if (3 == st->a_size && tmp_a >= (long)ft_lstlast(st->a)->content)
		return (1);
	else if (st->a_size < 4)
		return (0);
	if ((sh_sigma2(st) && tmp_a >= st->sh_sigma2[1])
		|| (sh_r_side(st) && tmp_a > st->sh_sigma[1]))
		return (1);
	else
		return (0);
}
static short	l_need_to_ra_b(t_stacks *st)
{
	long	tmp_b;
	if (st->shrt)
		return (0);
	tmp_b = (long)st->b->content;
	if (st->b_size < 3)
		return (0);
	if (tmp_b <= st->sigma2[0] || (!r_side(st) && tmp_b < st->sigma[0]))
		return (1);
	else
		return (0);
}

static short	sh_need_to_ra_b(t_stacks *st)
{
	long	tmp_b;
	if (!st->shrt)
		return (0);
	find_short_boundaries(st);
	tmp_b = (long)st->b->content;
	if (3 == st->b_size && tmp_b <= (long)ft_lstlast(st->b)->content)
		return (1);
	else if (st->b_size < 4)
		return (0);
	if ((!sh_r_side(st) && tmp_b < st->sh_sigma[0])
		|| (st->b_size > 2 && sh_sigma2(st)	&& tmp_b <= st->sh_sigma2[0]))
		return (1);
	else
		return (0);
}

void	need_to_ra(short *a, short *b, t_stacks *st)
{
	if (NULL != st->a)
		if (sh_need_to_ra_a(st)	|| l_need_to_ra_a(st))
			*a = 1;
	if (NULL != st->b )
		if (sh_need_to_ra_b(st) || l_need_to_ra_b(st))
			*b = 1;
	return ;
}


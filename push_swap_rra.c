/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rra.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coskelet <coskelet@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 15:47:32 by coskelet          #+#    #+#             */
/*   Updated: 2022/03/08 15:47:34 by coskelet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static short	l_need_to_rra(t_stacks *st)
{
	long tmp_al;

	if (st->shrt)
		return (0);
	tmp_al = (long)ft_lstlast(st->a)->content;
	if (tmp_al <= st->sigma2[0]	|| (r_side(st) && tmp_al <= st->sigma[0]))
		return (1);
	else
		return (0);
}

static short	sh_need_to_rra(t_stacks *st)
{
	long tmp_al;

	if (!st->shrt && st->a_size >= SH_STACK)
		return (0);
	find_short_boundaries(st);
	tmp_al = (long)ft_lstlast(st->a)->content;
	if ((sh_sigma2(st) && tmp_al <= st->sh_sigma2[0])
		|| (r_side(st) && tmp_al <= st->sh_sigma[0]))
		return (1);
	else
		return (0);
}

void	need_to_rra(short *a, t_stacks *st)
{
	if (NULL != st->a)
	{
		if (sh_need_to_rra(st) || l_need_to_rra(st))
			*a = 1;
	}
	return ;
}
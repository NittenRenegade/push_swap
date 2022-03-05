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
	int	a;
	int	a1;

	if (NULL == st->a || NULL == st->a->next)
		return (0);
	a = (int)st->a->content;
	a1 = (int)st->a->next->content;
	if (a > a1)
		return (1);
	else
		return (0);
}

short	b_b1(t_stacks *st)
{
	int	b;
	int	b1;

	if (NULL == st->b || NULL == st->b->next)
		return (0);
	b = (int)st->b->content;
	b1 = (int)st->b->next->content;
	if (b < b1)
		return (1);
	else
		return (0);
}

short	a_al(t_stacks *st)
{
	int	a;
	int	al;

	if (NULL == st->a || NULL == st->a->next)
		return (0);
	a = (int)st->a->content;
	al = (int)ft_lstlast(st->a)->content;
	if (a > al)
		return (1);
	else
		return (0);
}

short	b_bl(t_stacks *st)
{
	int	b;
	int	bl;

	if (NULL == st->b || NULL == st->b->next)
		return (0);
	b = (int)st->b->content;
	bl = (int)ft_lstlast(st->b)->content;
	if (b < bl)
		return (1);
	else
		return (0);
}

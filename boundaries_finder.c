/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boundaries_finder.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coskelet <coskelet@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 09:51:38 by coskelet          #+#    #+#             */
/*   Updated: 2022/03/09 09:51:44 by coskelet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_boundaries(t_stacks *st)
{
	long	*ar;
	int		i;

	ar = get_sort_array(st->a, st->a_size, &i);
	st->median = ar[(long)(i / 2)];
	st->sigma[0] = ar[(long)(i / 3)];
	st->sigma[1] = ar[(long)(i - (i / 3))];
	if (i >= SH_STACK)
	{
		st->pos_sigma2[0] = (long) (i / SH_STACK);
		st->pos_sigma2[1] = (long) (i - (i / SH_STACK));
		st->sigma2[0] = ar[st->pos_sigma2[0]];
		st->sigma2[1] = ar[st->pos_sigma2[1]];
	}
	if (i <= SH_STACK)
		st->shrt = 1;
	free(ar);
}

void	fill_short_boundaries(t_stacks *st, long *ar, size_t size)
{
	st->sh_median = ar[(long) (size / 2)];
	st->sh_sigma[0] = ar[(long) (size / 3)];
	st->sh_sigma[1] = ar[(long) (size - (size / 3))];
	if (size >= SH_STACK)
	{
		st->sh_sigma2[0] = ar[(long) (size / SH_STACK)];
		st->sh_sigma2[1] = ar[(long) (size - (size / SH_STACK))];
	} else if (size < SH_STACK && size >= 5)
	{
		st->sh_sigma2[0] = ar[0];
		st->sh_sigma2[1] = ar[size - 1];
	}
}

static void	find_short_boundaries_a(t_stacks *st)
{
	long	*ar;
	int 	size;

	ar = get_sort_array(st->a, st->a_size, &size);
	fill_short_boundaries(st, ar, size);
	free(ar);

}

static void	find_short_boundaries_b(t_stacks *st)
{
	long	*ar;
	int 	size;

	ar = get_sort_array(st->b, st->b_size, &size);
	fill_short_boundaries(st, ar, size);
	free(ar);

}

void	find_short_boundaries(t_stacks *st)
{
	if ((st->size < SH_STACK && st->size == st->a_size)
		|| SH_STACK == st->a_size)
		find_short_boundaries_a(st);
	else if (st->size > SH_STACK && SH_STACK == st->b_size)
		find_short_boundaries_b(st);
}
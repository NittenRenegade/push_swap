/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boundaries_comparator.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coskelet <coskelet@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:54:48 by coskelet          #+#    #+#             */
/*   Updated: 2022/03/08 13:54:50 by coskelet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

short	sigma2(t_stacks *st)
{
	if (st->sigma2[0] != st->sigma2[1])
		return (1);
	else
		return (0);
}

short	sh_sigma2(t_stacks *st)
{
	if (st->sh_sigma2[0] != st->sh_sigma2[1])
		return (1);
	else
		return (0);
}

short	sh_r_side(t_stacks *st)
{
	if (st->a_size > SH_STACK / 2)
		return (1);
	else
		return (0);
}

short	r_side(t_stacks *st)
{
	if (st->a_size > st->size / 2)
		return (1);
	else
		return (0);
}
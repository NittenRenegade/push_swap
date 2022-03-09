/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_move_to.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coskelet <coskelet@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:15:49 by coskelet          #+#    #+#             */
/*   Updated: 2022/03/07 17:46:14 by coskelet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static short	try_put_b(t_stacks *st)
{

	if (move_rback(st))
		return(0);
	if (move_back(st))
		return (0);
	exec_cmd(st, "pb", 1);
	find_short_boundaries(st);
	return (1);
}

void	move_to_b(t_stacks *st)
{
	int	i;

	i = 0;
	while (!try_put_b(st))
		i++;
	return ;
}

static short	try_put_a(t_stacks *st)
{
	if (move_back(st))
		return (0);
	exec_cmd(st, "pa", 1);
	return (1);
}

void	move_to_a(t_stacks *st)
{
	int	i;

	i = 0;
	while (!try_put_a(st))
		i++;
	return ;
}

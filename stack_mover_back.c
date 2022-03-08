/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_mover_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coskelet <coskelet@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 16:54:03 by coskelet          #+#    #+#             */
/*   Updated: 2022/03/07 17:17:30 by coskelet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

short	move_back(t_stacks *st)
{
	short	a;
	short	b;

	a = 0;
	b = 0;
	need_to_ra(&a, &b, st);
	if (a && b)
		exec_cmd(st, "rr", 1);
	else if (a)
		exec_cmd(st, "ra", 1);
	else if (b)
		exec_cmd(st, "rb", 1);
	else
		return (0);
	print_stacks(st);
	return (1);
}

short	move_rback(t_stacks *st)
{
	short	a;
	short	b;

	a = 0;
	b = 0;
	need_to_rra(&a, st);
	if (a && b)
		exec_cmd(st, "rrr", 1);
	else if (a)
		exec_cmd(st, "rra", 1);
	else if (b)
		exec_cmd(st, "rrb", 1);
	else
		return (0);
	print_stacks(st);
	return (1);
}

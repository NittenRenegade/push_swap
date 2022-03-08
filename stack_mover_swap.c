/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_mover_swap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coskelet <coskelet@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 16:08:04 by coskelet          #+#    #+#             */
/*   Updated: 2022/03/08 16:08:07 by coskelet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

short	swap_head(t_stacks *st)
{
	if (a_a1(st) && b_b1(st))
		exec_cmd(st, "ss", 1);
	else if (a_a1(st))
		exec_cmd(st, "sa", 1);
	else if (b_b1(st))
		exec_cmd(st, "sb", 1);
	else
		return (0);
	print_stacks(st);
	return (1);
}
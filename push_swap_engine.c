/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_engine.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coskelet <coskelet@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 13:58:57 by coskelet          #+#    #+#             */
/*   Updated: 2022/03/07 17:27:56 by coskelet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_stack_b(t_stacks *st)
{
	int	i;

	i = 0;
	while (!ft_lst_issort(st->b, 0) || st->b_size > 0)
	{
		while (move_back(st) || swap_head(st))
			swap_head(st);
		if (NULL != st->b)
			move_to_a(st);
		else if (PRINT_CMD)
			write(1, "\n", 1);
		print_stacks(st);
	}
	if (PRINT_CMD)
		write(1, "!\n", 2);
	if (!ft_lst_issort(st->a, 1))
	{
		if (PRINT_CMD)
			write(1, "\n", 1);
	}
}

short	sort_stack_a(t_stacks *st)
{
	print_stacks(st);
	while (move_rback(st))
	{
		swap_head(st);
		exec_cmd(st, "pb", 1);
		print_stacks(st);
	}
	while (!ft_lst_issort(st->a, 1))
	{
		while (move_back(st) || swap_head(st))
			swap_head(st);
		if (!ft_lst_issort(st->a, 1))
			move_to_b(st);
		else if (PRINT_CMD)
			write(1, "\n", 1);
		print_stacks(st);
	}
	if (NULL == st->b)
		return (1);
	sort_stack_b(st);
	return (0);
}

void	start_push_swap(t_stacks *st)
{
	while (NULL == st->b && !ft_lst_issort(st->a, 1))
		sort_stack_a(st);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_engine.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coskelet <coskelet@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 13:58:57 by coskelet          #+#    #+#             */
/*   Updated: 2022/03/05 15:42:43 by coskelet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

short	sort_head(t_stacks *st)
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

short	move_back(t_stacks *st)
{
	int		tmp_a;
	int		tmp_b;
	short	a;
	short	b;

	a = 0;
	b = 0;
	if (NULL != st->a)
	{
		tmp_a = (int)st->a->content;
		if (tmp_a > st->sigma[1] && st->a_size > st->size / 2)
			a = 1;
	}
	if (NULL != st->b)
	{
		tmp_b = (int)st->b->content;
		if (tmp_b < st->sigma[0] && st->a_size <= st->size / 2)
			b = 1;
	}
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

void	start_push_swap(t_stacks *st)
{
	int	i;

	i = 0;
	print_stacks(st);
	while (!ft_lst_issort(st->a, 1))
	{
		while (move_back(st))
			sort_head(st);
		while (sort_head(st))
			i++;
		if (!ft_lst_issort(st->a, 1))
			exec_cmd(st, "pb", 1);
		else
			write(1, "\n", 1);
		print_stacks(st);
	}
	if (NULL == st->b)
		return ;
	while (!ft_lst_issort(st->b, 0) || 1 == st->b_size)
	{
		while (move_back(st))
			sort_head(st);
		while (sort_head(st))
			i++;
		if (NULL != st->b)
			exec_cmd(st, "pa", 1);
		else
			write(1, "\n", 1);
		print_stacks(st);
	}
	if (!ft_lst_issort(st->a, 1))
	{
		write(1, "\n", 1);
		start_push_swap(st);
	}
}

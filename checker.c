/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coskelet <coskelet@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 14:25:51 by coskelet          #+#    #+#             */
/*   Updated: 2022/02/27 15:34:02 by coskelet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static short	process_cmds(t_stacks **st);

int	main(int argc, char **argv)
{
	t_stacks	*st;

	if (argc < 2)
		return (0);
	st = create_stack(argc, argv);
	if (NULL == st)
	{
		ft_putstr_fd("Error\n", 0);
		return (0);
	}
	ft_lstiter(st->a, ft_print_nbr);
	if (!process_cmds(&st))
	{
		ft_putstr_fd("Error\n", 0);
		return (0);
	}
	if (ft_lst_issort(st->a))
	{
		ft_putstr_fd("OK\n", 0);
		return (0);
	}
}

static short	process_cmds(t_stacks **st)
{
	char		*cmd;

	cmd = get_next_line(0);
	while (cmd != NULL)
	{
		if (exec_cmd(*st, cmd) < 0)
		{
			stack_clean(&(*st));
			ft_putstr_fd("Error\n", 0);
			free(cmd);
			return (0);
		}
		ft_lstiter((*st)->a, ft_print_nbr);
		free(cmd);
		cmd = get_next_line(0);
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coskelet <coskelet@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 14:25:51 by coskelet          #+#    #+#             */
/*   Updated: 2022/03/05 14:11:03 by coskelet         ###   ########.fr       */
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
	if (!process_cmds(&st))
	{
		ft_putstr_fd("Error\n", 0);
		return (0);
	}
	if (NULL == st->b && ft_lst_issort(st->a, 1))
		ft_putstr_fd("OK\n", 0);
	else
		ft_putstr_fd("KO\n", 0);
	return (0);
}

static short	process_cmds(t_stacks **st)
{
	char		*cmd;

	cmd = get_next_line(0);
	while (cmd != NULL)
	{
		if (exec_cmd(*st, cmd, 0) < 0)
		{
			stack_clean(&(*st));
			ft_putstr_fd("Error\n", 0);
			free(cmd);
			return (0);
		}
		free(cmd);
		cmd = get_next_line(0);
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coskelet <coskelet@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 13:25:57 by coskelet          #+#    #+#             */
/*   Updated: 2022/02/27 17:03:49 by coskelet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_command(char *cmd)
{
	size_t	size;

	size = ft_strlen(cmd);
	if (size < 2 || size > 3)
		return (0);
	else if (ft_strcmp(cmd, "sa") || ft_strcmp(cmd, "sb"))
		return (1);
	else if (ft_strcmp(cmd, "ss") || ft_strcmp(cmd, "rr"))
		return (1);
	else if (ft_strcmp(cmd, "pa") || ft_strcmp(cmd, "pb"))
		return (1);
	else if (ft_strcmp(cmd, "ra") || ft_strcmp(cmd, "rb"))
		return (1);
	else if (ft_strcmp(cmd, "rra") || ft_strcmp(cmd, "rrb"))
		return (1);
	else if (ft_strcmp(cmd, "rrr"))
		return (1);
	else
		return (0);
}

int	exec_cmd(t_stacks *st, char *cmd)
{
	char	*cmds[11] = {"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr",
	"rra", "rrb", "rrr"};

	short	i;

	i = 0;
	while (i < 11)
	{
		if (ft_strcmp(cmd, cmds[i]))
		{
			(*st->func[i])(st);
			return (i);
		}
		i++;
	}
	return (-1);
}

void	stack_clean(t_stacks **st)
{
		ft_lst_shortclear(&((*st)->a));
		ft_lst_shortclear(&((*st)->b));
		free(*st);
		*st = NULL;
}

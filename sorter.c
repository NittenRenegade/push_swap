/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coskelet <coskelet@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 15:44:40 by coskelet          #+#    #+#             */
/*   Updated: 2022/03/05 14:10:45 by coskelet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_boundaries(t_stacks *st);

int	main(int argc, char **argv)
{
	t_stacks	*st;

	if (argc < 2)
	{
		ft_putstr_fd("no parameter list\n", 0);
		return (0);
	}
	st = create_stack(argc, argv);
	if (NULL == st)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	find_boundaries(st);

	if (ft_lst_issort(st->a, 1))
		return (0);
	return (0);
}

void	find_boundaries(t_stacks *st)
{
	int		*ar;
	int		i;
	t_list	*tmp;

	ar = malloc(sizeof(int) * st->a_size);
	tmp = st->a;
	i = 0;
	while (tmp)
	{
		ar[i] = (int)tmp->content;
		i++;
		tmp = tmp->next;
	}
	ft_sort_quick(ar, 0, i - 1);
	st->sigma[0] = ar[(int)(i / 3)];
	st->median = ar[(int)(i / 2)];
	st->sigma[1] = ar[(int)(i / 3 * 2)];
	start_push_swap(st);
	if (NULL == st->b && ft_lst_issort(st->a, 1))
		ft_putstr_fd("OK\n", 0);
	else
		ft_putstr_fd("KO\n", 0);
	free(ar);
}

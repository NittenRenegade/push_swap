/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coskelet <coskelet@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 15:44:40 by coskelet          #+#    #+#             */
/*   Updated: 2022/03/07 14:47:49 by coskelet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	find_short_boundaries(st);
	start_push_swap(st);
	return (0);
}

long	*get_sort_array(t_list *lst, size_t size, int *i)
{
	long	*ar;

	ar = malloc(sizeof(long) * size);
	*i = 0;
	while (lst)
	{
		ar[*i] = (long)lst->content;
		(*i)++;
		lst = lst->next;
	}
	ft_sort_quick(ar, 0, *i - 1);
	return (ar);
}
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

static void	find_boundaries(t_stacks *st);

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

static void	find_boundaries(t_stacks *st)
{
	long	*ar;
	int		i;

	ar = get_sort_array(st->a, st->a_size, &i);
	st->median = ar[(long)(i / 2)];
	st->sigma[0] = ar[(long)(i / 3)];
	st->sigma[1] = ar[(long)(i - (i / 3))];
	if (i >= SH_STACK)
	{
		st->sigma2[0] = ar[(long) (i / SH_STACK)];
		st->sigma2[1] = ar[(long) (i - (i / SH_STACK))];
	}
	if (i <= SH_STACK)
		st->shrt = 1;
	free(ar);
}

void	find_short_boundaries(t_stacks *st)
{
	long	*ar;
	int 	i;

	if ((st->size < SH_STACK && st->size == st->a_size)
		|| SH_STACK == st->a_size)
	{
		ar = get_sort_array(st->a, st->a_size, &i);
		st->sh_median = ar[(long) (i / 2)];
		st->sh_sigma[0] = ar[(long) (i / 3)];
		st->sh_sigma[1] = ar[(long) (i - (i / 3))];
		if (i >= SH_STACK)
		{
			st->sh_sigma2[0] = ar[(long) (i / SH_STACK)];
			st->sh_sigma2[1] = ar[(long) (i - (i / SH_STACK))];
		} else if (i < SH_STACK && i >= 5)
		{
			st->sh_sigma2[0] = ar[0];
			st->sh_sigma2[1] = ar[i - 1];
		}
		free(ar);
	};
}
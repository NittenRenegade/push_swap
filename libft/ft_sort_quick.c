/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_quick.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coskelet <coskelet@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 17:35:06 by coskelet          #+#    #+#             */
/*   Updated: 2022/03/04 12:21:06 by coskelet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	swap(long *a, long *b)
{
	long	t;

	t = *a;
	*a = *b;
	*b = t;
}

static int	partition(long ar[], long low, long high)
{
	long	h;
	long	j;

	h = (low - 1);
	j = low;
	while (j < high)
	{
		if (ar[j] <= ar[high])
		{
			h++;
			swap(&ar[h], &ar[j]);
		}
		j++;
	}
	swap(&ar[h + 1], &ar[high]);
	return (h + 1);
}

void	ft_sort_quick(long ar[], long low, long high)
{
	int	pivot;

	if (low < high)
	{
		pivot = partition(ar, low, high);
		ft_sort_quick(ar, low, pivot - 1);
		ft_sort_quick(ar, pivot + 1, high);
	}
}

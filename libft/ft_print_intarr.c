/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_intarr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coskelet <coskelet@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 10:14:32 by coskelet          #+#    #+#             */
/*   Updated: 2022/03/04 11:34:41 by coskelet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_intarr(int ar[], size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		ft_putnbr_fd(ar[i++], 0);
		write(1, " ", 1);
	}
	return ;
}

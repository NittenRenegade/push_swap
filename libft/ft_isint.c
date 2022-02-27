/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coskelet <coskelet@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 12:51:29 by coskelet          #+#    #+#             */
/*   Updated: 2022/02/26 13:03:15 by coskelet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isint(char *str)
{
	int		neg;
	long	acc;

	neg = 1;
	if (*str == '-')
		neg = -1;
	if (*str == '-' || *str == '+')
		str++;
	acc = 0;
	while(*str)
	{
		acc = acc * 10 + (*str - '0');
		str++;
	}
	acc *= neg;
	if (acc < INT_MIN || acc > INT_MAX)
		return (0);
	else
		return (1);
}

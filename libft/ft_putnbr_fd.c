/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coskelet <coskelet@il-c2.msk.21-school.ru> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 11:44:36 by coskelet          #+#    #+#             */
/*   Updated: 2022/02/27 14:38:52 by coskelet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	pass_int(char s[], int n, short sgn);
static int	fnd_c(int n, int *d);

void	ft_putnbr_fd(int n, int fd)
{
	char	s[11];

	if (-2147483648 == n)
	{
		write(fd, "-2147483648", 11 * sizeof (char));
		return ;
	}
	ft_bzero(s, 11);
	if (n < 0)
	{
		pass_int(s, -n, 1);
	}
	else
		pass_int(s, n, 0);
	write(fd, s, ft_strlen(s) * sizeof (char));
}

static void	pass_int(char s[], int n, short sgn)
{
	int		d;
	int		c;
	int		i;

	d = 1;
	c = fnd_c(n, &d);
	i = 0;
	while (i < c)
	{
		s[i + sgn] = n / d + '0';
		n = n - (n / d * d);
		d /= 10;
		if (1 > d)
			break ;
		i ++;
	}
	if (sgn)
		s[0] = '-';
	return ;
}

static int	fnd_c(int n, int *d)
{
	int	c;

	c = 1;
	while (n / 10 >= 1)
	{
		c++;
		*d *= 10;
		n /= 10;
	}
	return (c);
}

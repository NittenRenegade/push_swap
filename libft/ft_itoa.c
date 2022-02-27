/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coskelet <coskelet@il-c2.msk.21-school.ru> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 11:58:59 by coskelet          #+#    #+#             */
/*   Updated: 2021/11/09 12:42:21 by coskelet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*pass_int(int n, short sgn);
int		fnd_c(int n, int *d);

char	*ft_itoa(int n)
{
	if (-2147483648 == n)
		return (ft_strdup("-2147483648"));
	if (n < 0)
		return (pass_int(-n, 1));
	return (pass_int(n, 0));
}

char	*pass_int(int n, short sgn)
{
	char	*a;
	int		d;
	int		c;
	int		i;

	d = 1;
	c = fnd_c(n, &d);
	a = malloc((c + 1 + sgn) * sizeof (char ));
	if (!a)
		return (NULL);
	a[c + sgn] = '\0';
	i = 0;
	while (i < c)
	{
		a[i + sgn] = n / d + '0';
		n = n - (n / d * d);
		d /= 10;
		if (1 > d)
			break ;
		i ++;
	}
	if (sgn)
		a[0] = '-';
	return (a);
}

int	fnd_c(int n, int *d)
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

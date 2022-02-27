/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coskelet <coskelet@il-c2.msk.21-school.ru> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 15:26:29 by coskelet          #+#    #+#             */
/*   Updated: 2021/11/09 12:42:21 by coskelet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		parse_int(char **pos, char **fin, short sign, long res);
static char		*find_fin(char *pos, char **fin_pos);
static char		*pass_space(const char *str, char *pos);
static short	pass_sign(char **pos);

int	ft_atoi(const char *str)
{
	char	*pos;
	char	*fin_pos;
	short	sign;
	long	res;

	if (ft_strlen(str) == 0)
		return (0);
	pos = (char *)str;
	pos = pass_space(str, pos);
	if (NULL == pos)
		return (0);
	sign = pass_sign(&pos);
	if (0 == sign)
		return (0);
	fin_pos = pos;
	res = 1;
	return (parse_int(&pos, &fin_pos, sign, res));
}

static int	parse_int(char **pos, char **fin_pos, short sign, long res)
{
	long	base;

	if (!find_fin(*pos, fin_pos))
		return (0);
	base = 1;
	while ((*fin_pos - *pos) / (int) sizeof (char) > res)
	{
		if (res > 18)
			sign *= 2;
		base *= 10;
		res++;
	}
	res = (**pos - '0') * sign * base;
	base /= 10;
	while (++(*pos) < *fin_pos)
	{
		res += (**pos - '0') * sign * base;
		if (sign > 0 && (sign > 1 || res < 0))
			return (-1);
		if (sign < 0 && (sign < -1 || res > 0))
			return (0);
		base /= 10;
	}
	return ((int)res);
}

static char	*find_fin(char *pos, char **fin_pos)
{
	*fin_pos = pos;
	while (ft_isdigit(**fin_pos))
		(*fin_pos)++;
	if (*fin_pos == pos)
		return (NULL);
	return (*fin_pos);
}

static char	*pass_space(const char *str, char *pos)
{
	pos = (char *)str;
	while (1)
	{
		if ('+' == *pos || '-' == *pos || ft_isdigit(*pos))
			return (pos);
		else if (' ' == *pos || '\t' == *pos || '\n' == *pos || '\v' == *pos)
			pos++;
		else if (' ' == *pos || '\f' == *pos || '\r' == *pos)
			pos++;
		else
			return (NULL);
	}
}

static short	pass_sign(char **pos)
{
	if (ft_isdigit(**pos))
		return (1);
	if (!ft_isdigit(*((*pos) + 1)))
		return (0);
	if ('+' == **pos)
	{
		(*pos)++;
		return (1);
	}
	if ('-' == **pos)
	{
		(*pos)++;
		return (-1);
	}
	else
		return (0);
}

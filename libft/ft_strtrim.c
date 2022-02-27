/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coskelet <coskelet@il-c2.msk.21-school.ru> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 22:27:36 by coskelet          #+#    #+#             */
/*   Updated: 2021/11/10 20:05:45 by coskelet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_end(char const *s1, size_t pos_strt, char const *set);
static size_t	pass_left(char const *s1, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	pos_strt;

	if (!s1)
		return (NULL);
	pos_strt = pass_left(s1, set);
	return (ft_substr(s1, pos_strt, get_end(s1, pos_strt, set)));
}

static size_t	get_end(char const *s1, size_t pos_strt, char const *set)
{
	size_t	len;

	len = ft_strlen(s1 + pos_strt);
	if (0 == len)
		return (0);
	while (len - 1 >= 0)
	{
		if (!ft_strchr(set, *(s1 + pos_strt + len - 1)))
			return (len);
		len--;
	}
	return (0);
}

static size_t	pass_left(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	while (*(s1 + i) != '\0')
	{
		if (!ft_strchr(set, *(s1 + i)))
			return (i);
		i++;
	}
	return (i);
}

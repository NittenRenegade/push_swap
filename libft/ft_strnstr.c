/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coskelet <coskelet@il-c2.msk.21-school.ru> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 19:37:04 by coskelet          #+#    #+#             */
/*   Updated: 2021/11/09 12:42:21 by coskelet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_min(size_t *lens);
static char		*find_str(const char *big, const char *little, size_t *lens);

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	lens[4];

	if ('\0' == *little)
		return ((char *)big);
	lens[0] = len;
	lens[1] = ft_strlen(big);
	lens[2] = ft_strlen(little);
	lens[3] = get_min(lens);
	if (lens[1] < lens[2])
		return (NULL);
	return (find_str(big, little, lens));
}

static char	*find_str(const char *big, const char *little, size_t *lens)
{
	size_t	i;
	size_t	j;

	i = 0;
	while ((lens[2] + i) <= lens[3] && *(big + i) != '\n')
	{
		j = 0;
		while (*(little + j) != '\n' && j <= lens[0])
		{
			if (j == lens[2])
				return ((char *)(big + i));
			if (*(big + i + j) != *(little + j))
				break ;
			j++;
		}
		i++;
	}
	return (NULL);
}

static size_t	get_min(size_t *lens)
{
	if (lens[1] < lens[0])
	{
		return (lens[1]);
	}
	else
		return (lens[0]);
}

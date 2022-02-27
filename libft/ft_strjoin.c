/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coskelet <coskelet@il-c2.msk.21-school.ru> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 21:41:39 by coskelet          #+#    #+#             */
/*   Updated: 2021/11/10 19:45:57 by coskelet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*ptr;

	if (s1 && s2)
	{
		len1 = ft_strlen(s1);
		len2 = ft_strlen(s2);
	}
	else
	{
		len1 = 0;
		len2 = -1;
	}
	ptr = malloc(sizeof (char) * (len1 + len2 + 1));
	if (!ptr)
		return (NULL);
	if (s1 && s2)
	{
		ft_strlcpy(ptr, s1, len1 + 1);
		ft_strlcpy(ptr + len1, s2, len2 + 1);
	}
	return (ptr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coskelet <coskelet@il-c2.msk.21-school.ru> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 21:17:09 by coskelet          #+#    #+#             */
/*   Updated: 2021/11/10 18:47:52 by coskelet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	s_len;

	if (s)
	{
		s_len = ft_strlen(s);
		if (s_len < start + len)
			len = s_len - start;
		if (ft_strlen(s) < start)
			len = 0;
	}
	else
		len = -1;
	ptr = (char *)malloc(sizeof (char) * (len + 1));
	if (!ptr)
		return (NULL);
	if (!s)
		return (ptr);
	ft_strlcpy(ptr, s + start, len + 1);
	return (ptr);
}

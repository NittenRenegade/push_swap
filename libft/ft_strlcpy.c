/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coskelet <coskelet@il-c2.msk.21-school.ru> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 18:29:38 by coskelet          #+#    #+#             */
/*   Updated: 2021/11/09 12:42:21 by coskelet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t		src_len;
	size_t		pos;

	src_len = ft_strlen(src);
	if (0 == dstsize)
		return (src_len);
	pos = 0;
	while (pos < (dstsize - 1) && pos < (size_t)src_len)
	{
		*(dst + pos) = *(src + pos);
		pos++;
	}
	*(dst + pos) = '\0';
	return (src_len);
}

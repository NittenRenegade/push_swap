/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coskelet <coskelet@il-c2.msk.21-school.ru> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 20:32:04 by coskelet          #+#    #+#             */
/*   Updated: 2021/11/09 12:42:21 by coskelet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t	src_len;
	size_t	dst_len;
	size_t	count;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	if (dstsize <= dst_len)
		return (dstsize + src_len);
	if (dstsize <= dst_len + 1)
		return (dstsize - 1 + src_len);
	count = src_len;
	if (dstsize - dst_len <= count)
		count = dstsize - dst_len - 1;
	ft_memcpy(dst + dst_len, src, count);
	*(dst + dst_len + count) = '\0';
	return (dst_len + src_len);
}

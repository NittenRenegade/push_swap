/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coskelet <coskelet@il-c2.msk.21-school.ru> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 13:08:06 by coskelet          #+#    #+#             */
/*   Updated: 2021/11/09 12:42:21 by coskelet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*src_c;
	unsigned char	*dst_c;

	if (!dst && !src)
		return (dst);
	src_c = (unsigned char *)src;
	dst_c = (unsigned char *)dst;
	if (src < dst && (src_c + n - 1) >= dst_c)
	{
		i = n;
		while (i > 0)
		{
			*(dst_c + i - 1) = *(src_c + i - 1);
			i--;
		}
		return (dst);
	}
	i = 0;
	while (i < n)
	{
		*(dst_c + i) = *(src_c + i);
		i++;
	}
	return (dst);
}

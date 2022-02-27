/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coskelet <coskelet@il-c2.msk.21-school.ru> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:40:19 by coskelet          #+#    #+#             */
/*   Updated: 2021/11/10 18:26:27 by coskelet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*pos;
	char	*smb;

	smb = (char *) 0;
	pos = (char *) s;
	while (1)
	{
		if (*pos == (char) c)
			smb = pos;
		if (!*pos)
			break ;
		pos++;
	}
	return (smb);
}

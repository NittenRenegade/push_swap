/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_getfpos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coskelet <coskelet@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 15:20:27 by coskelet          #+#    #+#             */
/*   Updated: 2022/03/04 15:29:05 by coskelet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lst_getfpos(t_list *lst, void *value)
{
	size_t	pos;

	pos = 0;
	while (lst)
	{
		if (lst->content == value)
			return (pos);
		lst = lst->next;
		pos++;
	}
	return (-1);
}

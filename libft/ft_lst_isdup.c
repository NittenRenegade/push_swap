/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_isdup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coskelet <coskelet@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 09:44:27 by coskelet          #+#    #+#             */
/*   Updated: 2022/02/26 09:55:22 by coskelet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lst_isdup(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp->next)
	{
		while (lst->next)
		{
			if (tmp->content == lst->next->content)
				return (0);
			lst = lst->next;
		}
		tmp = tmp->next;
		lst = tmp;
	}
	return (1);
}

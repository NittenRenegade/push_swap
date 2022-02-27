/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstissort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coskelet <coskelet@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 09:36:58 by coskelet          #+#    #+#             */
/*   Updated: 2022/02/26 13:10:40 by coskelet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lst_issort(t_list *lst)
{
	while (lst->next)
	{
		if ((int)lst->content > (int)lst->next->content)
			return (0);
		lst = lst->next;
	}
	return (1);
}

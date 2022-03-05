/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstissort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coskelet <coskelet@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 09:36:58 by coskelet          #+#    #+#             */
/*   Updated: 2022/03/05 14:30:35 by coskelet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lst_issort(t_list *lst, short asc)
{
	if (!lst)
		return (1);
	while (lst->next)
	{
		if (asc && (int)lst->content > (int)lst->next->content)
			return (0);
		else if (!asc && (int)lst->content < (int)lst->next->content)
			return (0);
		lst = lst->next;
	}
	return (1);
}

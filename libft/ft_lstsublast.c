/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsublast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coskelet <coskelet@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 14:13:27 by coskelet          #+#    #+#             */
/*   Updated: 2022/03/02 14:32:17 by coskelet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstsublast(t_list *lst)
{
	t_list	*prev;

	while (lst && lst->next)
	{
		prev = lst;
		lst = lst->next;
	}
	return (prev);
}

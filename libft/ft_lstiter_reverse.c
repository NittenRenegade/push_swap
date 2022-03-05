/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_reverse.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coskelet <coskelet@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 13:16:36 by coskelet          #+#    #+#             */
/*   Updated: 2022/03/05 13:29:00 by coskelet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter_reverse(t_list *lst, void (*f)(void *))
{
	if (!lst)
		return ;
	if (lst->next)
		ft_lstiter_reverse(lst->next, f);
	(*f)(lst->content);
	return ;
}

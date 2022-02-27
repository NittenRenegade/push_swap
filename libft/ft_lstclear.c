/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coskelet <coskelet@il-c2.msk.21-school.ru> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 14:56:27 by coskelet          #+#    #+#             */
/*   Updated: 2022/02/27 14:30:43 by coskelet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*cur;

	cur = *lst;
	while (cur)
	{
		tmp = cur->next;
		(*del)(cur->content);
		free(cur);
		cur = tmp;
	}
	free(cur);
	*lst = NULL;
}

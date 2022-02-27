/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstshortclear.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coskelet <coskelet@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 14:30:18 by coskelet          #+#    #+#             */
/*   Updated: 2022/02/27 14:30:34 by coskelet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_shortclear(t_list **lst)
{
	t_list	*tmp;
	t_list	*cur;

	cur = *lst;
	while (cur)
	{
		tmp = cur->next;
		free(cur);
		cur = tmp;
	}
	*lst = NULL;
}

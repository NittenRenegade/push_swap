/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_engine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coskelet <coskelet@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 13:50:06 by coskelet          #+#    #+#             */
/*   Updated: 2022/02/27 17:06:23 by coskelet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stacks	*init_stacks(void);
static void		init_stacks_funcs(t_stacks **st);

t_stacks	*create_stack(int cnt, char **argv)
{
	int			i;
	t_stacks	*ptr;

	ptr = init_stacks();
	i = 0;
	while (++i < cnt)
	{
		if (!ft_isnum(argv[i]) || !ft_isint(argv[i]))
		{
			ft_lst_shortclear(&(ptr->a));
			free(ptr);
			return (NULL);
		}
		add_to_stack(ptr, atoi(argv[i]));
	}
	if (!ft_lst_isdup(ptr->a))
	{
		ft_lst_shortclear(&(ptr->a));
		free(ptr);
		return (NULL);
	}
	reload_stack_properties(ptr);
	return (ptr);
}

void	add_to_stack(t_stacks *st, size_t val)
{
	ft_lstadd_back(&st->a, ft_lstnew((void *)val));
}

void	reload_stack_properties(t_stacks *st)
{
	st->a2 = st->a->next;
	st->a_f = ft_lstlast(st->a);
	st->a_size = ft_lstsize(st->a);
	if (NULL == st->b)
		return ;
	st->b2 = st->b->next;
	st->b_f = ft_lstlast(st->b);
	st->b_size = ft_lstsize(st->b);
}

static t_stacks	*init_stacks(void)
{
	t_stacks	*ptr;

	ptr = (t_stacks *)malloc(sizeof(t_stacks));
	if (!ptr)
		return (NULL);
	ptr->a = NULL;
	ptr->b = NULL;
	ptr->a_size = 0;
	ptr->b_size = 0;
	ptr->a2 = NULL;
	ptr->b2 = NULL;
	ptr->a_f = NULL;
	ptr->b_f = NULL;
	init_stacks_funcs(&ptr);
	return (ptr);
}

static void	init_stacks_funcs(t_stacks **st)
{
	(*st)->func[0] = swap_a;
	(*st)->func[1] = swap_b;
	(*st)->func[2] = swap_both;
	(*st)->func[3] = push_a;
	(*st)->func[4] = push_b;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_engine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coskelet <coskelet@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 13:50:06 by coskelet          #+#    #+#             */
/*   Updated: 2022/03/05 16:44:50 by coskelet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stacks	*init_stacks(void);
static void		init_stacks_funcs(t_stacks **st);
static void		init_stacks_median(t_stacks *st);

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
		ptr->a_size++;
		ptr->size++;
	}
	if (!ft_lst_isdup(ptr->a))
	{
		ft_lst_shortclear(&(ptr->a));
		free(ptr);
		return (NULL);
	}
	return (ptr);
}

void	add_to_stack(t_stacks *st, size_t val)
{
	ft_lstadd_back(&st->a, ft_lstnew((void *)val));
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
	ptr->size = 0;
	init_stacks_funcs(&ptr);
	ptr->func_dict[0] = "sa";
	ptr->func_dict[1] = "sb";
	ptr->func_dict[2] = "ss";
	ptr->func_dict[3] = "pa";
	ptr->func_dict[4] = "pb";
	ptr->func_dict[5] = "ra";
	ptr->func_dict[6] = "rb";
	ptr->func_dict[7] = "rr";
	ptr->func_dict[8] = "rra";
	ptr->func_dict[9] = "rrb";
	ptr->func_dict[10] = "rrr";
	init_stacks_median(ptr);
	return (ptr);
}

static void	init_stacks_funcs(t_stacks **st)
{
	(*st)->func[0] = swap_a;
	(*st)->func[1] = swap_b;
	(*st)->func[2] = swap_both;
	(*st)->func[3] = push_a;
	(*st)->func[4] = push_b;
	(*st)->func[5] = rotate_a;
	(*st)->func[6] = rotate_b;
	(*st)->func[7] = rotate_both;
	(*st)->func[8] = rrotate_a;
	(*st)->func[9] = rrotate_b;
	(*st)->func[10] = rrotate_both;
}

static void	init_stacks_median(t_stacks *st)
{
	st->median = 0;
	st->sigma[0] = 0;
	st->sigma[1] = 0;
	st->sigma2[0] = 0;
	st->sigma2[1] = 0;
	st->shrt = 0;
	st->sh_median = 0;
	st->sh_sigma[0] = 0;
	st->sh_sigma[1] = 0;
	st->sh_sigma2[0] = 0;
	st->sh_sigma2[1] = 0;
}

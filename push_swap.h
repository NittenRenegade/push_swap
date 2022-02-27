/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coskelet <coskelet@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 13:50:51 by coskelet          #+#    #+#             */
/*   Updated: 2022/02/27 17:08:10 by coskelet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./libft/libft.h"
# include <limits.h>
# include <stdarg.h>

typedef struct s_stacks {
	t_list	*a;
	t_list	*b;
	size_t	a_size;
	size_t	b_size;
	t_list	*a2;
	t_list	*b2;
	t_list	*a_f;
	t_list	*b_f;
	void	(*func[11])(struct s_stacks *);
}	t_stacks;

enum e_cmds {sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr};
t_stacks	*create_stack(int cnt, char **argv);
void		reload_stack_properties(t_stacks *st);
void		add_to_stack(t_stacks *st, size_t val);
void		stack_clean(t_stacks **st);
int			is_command(char *cmd);
int			exec_cmd(t_stacks *st, char *cmd);
void		swap_a(t_stacks *st);
void		swap_b(t_stacks *st);
void		swap_both(t_stacks *st);
void		push_a(t_stacks *st);
void		push_b(t_stacks *st);
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coskelet <coskelet@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 13:50:51 by coskelet          #+#    #+#             */
/*   Updated: 2022/03/07 17:29:55 by coskelet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define PRINT_CMD 1
# define SH_STACK 6
# include "./libft/libft.h"
# include <limits.h>
# include <stdarg.h>

typedef struct s_stacks {
	t_list		*a;
	t_list		*b;
	size_t		a_size;
	size_t		b_size;
	size_t		size;
	long		sigma[2];
	long		sigma2[2];
	long		median;
	long		sh_sigma[2];
	long		sh_sigma2[2];
	long		sh_median;
	short		shrt;
	void		(*func[11])(struct s_stacks *);
	const char	*func_dict[11];
}	t_stacks;

enum e_cmds {sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr};
t_stacks	*create_stack(int cnt, char **argv);
void		reload_stack_properties(t_stacks *st);
void		add_to_stack(t_stacks *st, size_t val);
void		stack_clean(t_stacks **st);
void		print_stacks(t_stacks *st);
int			is_command(char *cmd);
int			exec_cmd(t_stacks *st, char *cmd, char print);
void		swap_a(t_stacks *st);
void		swap_b(t_stacks *st);
void		swap_both(t_stacks *st);
void		push_a(t_stacks *st);
void		push_b(t_stacks *st);
void		rotate_a(t_stacks *st);
void		rotate_b(t_stacks *st);
void		rotate_both(t_stacks *st);
void		rrotate_a(t_stacks *st);
void		rrotate_b(t_stacks *st);
void		rrotate_both(t_stacks *st);
void		start_push_swap(t_stacks *st);
long		*get_sort_array(t_list *lst, size_t size, int *i);
void		find_short_boundaries(t_stacks *st);
void		need_to_ra(short *a, short *b, t_stacks *st);
void		need_to_rra(short *a, t_stacks *st);
short		a_a1(t_stacks *st);
short		b_b1(t_stacks *st);
short		a_al(t_stacks *st);
short		b_bl(t_stacks *st);
short		swap_head(t_stacks *st);
short		move_back(t_stacks *st);
short		move_rback(t_stacks *st);
short		sigma2(t_stacks *st);
short		r_side(t_stacks *st);
short		sh_sigma2(t_stacks *st);
short		sh_r_side(t_stacks *st);
short		shrt(t_stacks *st);
void		move_to_b(t_stacks *st);
void		move_to_a(t_stacks *st);
#endif

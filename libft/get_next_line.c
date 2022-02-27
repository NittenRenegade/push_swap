/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coskelet <coskelet@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 19:09:57 by coskelet          #+#    #+#             */
/*   Updated: 2022/02/26 10:15:23 by coskelet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static ssize_t	read_buf(int fd, t_gnllist *lst);
static char		*get_from_buf(t_gnllist **lst, ssize_t str_size);
static void		con_alloc(char *str, ssize_t str_size, t_gnllist **lst);
static ssize_t	get_nl_pos(t_gnllist *lst, ssize_t	*i);

char	*get_next_line(int fd)
{
	static t_gnllist	*lst;
	t_gnllist			*l_elem;
	ssize_t				read_cnt;
	ssize_t				i;

	get_list_elem(fd, &lst, &l_elem);
	i = 0;
	if (get_nl_pos(l_elem, &i) > 0)
		return (get_from_buf(&l_elem, i));
	read_cnt = read_buf(fd, l_elem);
	if (read_cnt <= 0 && l_elem->buf_line_size == 0)
	{
		free_list(&lst, fd);
		return (NULL);
	}
	i = 0;
	get_nl_pos(l_elem, &i);
	return (get_from_buf(&l_elem, i));
}

static ssize_t	get_nl_pos(t_gnllist *lst, ssize_t	*i)
{
	while (*i < lst->buf_line_size)
	{
		if (lst->buf_line[*i] == '\n')
			return (++(*i));
		(*i)++;
	}
	return (-1);
}

static ssize_t	read_buf(int fd, t_gnllist *lst)
{
	char	*str;
	ssize_t	read_cnt;
	ssize_t	i;

	if (BUFFER_SIZE <= 0)
		return (0);
	str = NULL;
	str = malloc(sizeof(char) * BUFFER_SIZE);
	if (!str)
		return (-1);
	read_cnt = read(fd, str, BUFFER_SIZE);
	if (read_cnt <= 0)
	{
		free(str);
		return (0);
	}
	con_alloc(str, read_cnt, &lst);
	i = 0;
	if (get_nl_pos(lst, &i) < 0)
		read_cnt += read_buf(fd, lst);
	return (read_cnt);
}

static void	con_alloc(char *str, ssize_t str_size, t_gnllist **lst)
{
	ssize_t		new_str_size;
	ssize_t		i;
	char		*new_str;

	if (str_size == 0)
		return ;
	new_str_size = str_size + (*lst)->buf_line_size;
	new_str = (char *)malloc(sizeof(char) * new_str_size);
	if (!new_str)
		return ;
	i = -1;
	while (++i < (*lst)->buf_line_size && (*lst)->buf_line_size != 0)
		new_str[i] = (*lst)->buf_line[i];
	i--;
	while (++i < new_str_size)
		new_str[i] = str[i - (*lst)->buf_line_size];
	if ((*lst)->buf_line)
		free((*lst)->buf_line);
	(*lst)->buf_line = new_str;
	(*lst)->buf_line_size = new_str_size;
	free(str);
	return ;
}

static char	*get_from_buf(t_gnllist **lst, ssize_t str_size)
{
	char	*new_str;
	char	*tmp_str;
	ssize_t	i;

	new_str = (char *)malloc(sizeof(char) * str_size);
	if (!new_str)
		return (NULL);
	i = -1;
	while (++i < str_size - 1)
		new_str[i] = (*lst)->buf_line[i];
	new_str[i] = '\0';
	if ((*lst)->buf_line_size - str_size != 0)
	{
		tmp_str = (char *)malloc(sizeof(char)
				* (*lst)->buf_line_size - str_size);
		i--;
		while (++i < (*lst)->buf_line_size)
			tmp_str[i - str_size] = (*lst)->buf_line[i];
	}
	else
		tmp_str = NULL;
	free((*lst)->buf_line);
	(*lst)->buf_line_size = (*lst)->buf_line_size - str_size;
	(*lst)->buf_line = tmp_str;
	return (new_str);
}

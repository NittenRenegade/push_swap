/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coskelet <coskelet@il-c2.msk.21-school.ru> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 20:23:31 by coskelet          #+#    #+#             */
/*   Updated: 2021/11/09 12:42:21 by coskelet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static short	prepare_mas(size_t size, char ***mas);
static short	pass_str(char **b_ch, size_t *b_st, char **mas);
static char		*alloc_str(char **b_ch, size_t *b_st, char **mas);
static void		free_mas(char **mas);

char	**ft_split(char const *s, char c)
{
	char	**mas;
	char	*b_ch[4];
	size_t	b_st[4];

	if (!s)
		return (NULL);
	b_ch[0] = (char *)s;
	b_ch[1] = &c;
	b_ch[2] = NULL;
	b_ch[3] = NULL;
	b_st[0] = 0;
	b_st[1] = 0;
	b_st[3] = ft_strlen(s);
	mas = NULL;
	if (!pass_str(b_ch, b_st, mas))
		return (NULL);
	if (!prepare_mas(b_st[0], &mas))
		return (mas);
	b_st[0] = 0;
	b_st[1] = 0;
	b_ch[3] = 0;
	pass_str(b_ch, b_st, mas);
	return (mas);
}

static short	prepare_mas(size_t size, char ***mas)
{
	size_t	i;

	*mas = (char **) malloc((size + 1) * sizeof (char *));
	if (NULL == *mas)
		return (0);
	if (!size)
	{
		**mas = NULL;
		return (1);
	}
	i = 1;
	while (i <= size)
	{
		*((*mas) + i) = NULL;
		i++;
	}
	return (1);
}

static short	pass_str(char **b_ch, size_t *b_st, char **mas)
{
	while (1)
	{
		if (b_ch[3] == b_ch[0] + b_st[3])
		{
			b_ch[2] = b_ch[0];
			return (1);
		}
		b_ch[3] = ft_strchr(b_ch[0] + b_st[1], *b_ch[1]);
		if (NULL == b_ch[3])
			b_ch[3] = b_ch[0] + b_st[3];
		if (b_ch[3] > (b_ch[0] + b_st[1]))
		{
			if (b_ch[2] != NULL)
				if (mas != NULL && !alloc_str(b_ch, b_st, mas))
					return (0);
			b_st[0]++;
			b_st[1] = b_ch[3] - b_ch[0];
		}
		b_st[1]++;
	}
}

static char	*alloc_str(char **b_ch, size_t *b_st, char **mas)
{
	char	*str;
	size_t	len;

	len = b_ch[3] - (b_ch[0] + b_st[1]);
	str = ft_substr(b_ch[0], b_st[1], len);
	if (NULL == str)
	{
		free_mas(mas);
		return (NULL);
	}
	mas[b_st[0]] = str;
	return (str);
}

static void	free_mas(char **mas)
{
	while (*mas != NULL)
	{
		free(*mas);
		mas++;
	}
	free(mas);
	return ;
}

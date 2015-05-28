/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrosnie <acrosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/31 15:08:50 by acrosnie          #+#    #+#             */
/*   Updated: 2015/01/31 15:13:53 by acrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

int				ft_strchr_index(const char *s, int c, int index)
{
	int			i;
	char		*s2;
	char		search;

	search = (char)c;
	i = 0;
	s2 = (char *)s;
	while (s2[index])
	{
		if (s2[index] == search)
			return (i);
		i++;
		index++;
	}
	if (s2[index] == search)
		return (i);
	return (BUFF_SIZE);
}

static char		*ft_strcat2(char *s1, char *s2, int *find, int *index)
{
	char		*s1o;
	char		*cpy;
	int			size_s1;

	size_s1 = ft_strlen(s1);
	cpy = ft_strnew(size_s1 + ft_strchr_index(s2, (int)'\n', *index) + 1);
	cpy = ft_strcpy(cpy, s1);
	s1o = cpy;
	if (!s2)
		return (cpy);
	while (s2[*(index)] != '\n' && s2[*index])
	{
		if (s2[*index] != -50)
			cpy[size_s1++] = s2[*index];
		s2[*index] = -50;
		(*index)++;
	}
	if (s2[*index] == '\n')
	{
		*find = 1;
		s2[(*index)++] = -50;
	}
	cpy[++size_s1] = '\0';
	free(s1);
	return (s1o);
}

static int		check_cond(char *buff, char **line, int *i)
{
	int			find;

	find = 0;
	*line = ft_strcat2(*line, buff, &find, i);
	if (find == 1)
		return (1);
	*i = 0;
	return (0);
}

int				get_next_line(int const fd, char **line)
{
	static char	buff[BUFF_SIZE + 1];
	static int	i = 0;

	if (BUFF_SIZE <= 0 || !line || (fd < 2 && fd != 0))
		return (-1);
	*line = ft_memalloc(1);
	if (check_cond(buff, line, &i) == 1)
		return (1);
	while ((read(fd, buff, BUFF_SIZE)) > 0)
	{
		if (check_cond(buff, line, &i) == 1)
			return (1);
	}
	if (**line)
		return (1);
	return (0);
}

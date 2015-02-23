/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrosnie <acrosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 16:12:11 by acrosnie          #+#    #+#             */
/*   Updated: 2014/01/12 15:46:48 by acrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../main.h"
#include <stdlib.h>
#include <unistd.h>

int		looking_for_end_of_line(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
		{
			str[i] = '\0';
			return (1);
		}
		i++;
	}
	return (0);
}

int		get_next_line(int const fd, char **line)
{
	static char	*mem = "";
	int			ret;
	char		*buffer;

	if (BUFF_SIZE < 1)
		return (-1);
	ret = BUFF_SIZE;
	while (!(looking_for_end_of_line(mem)) && (ret == BUFF_SIZE))
	{
		buffer = (char *)ft_memalloc(sizeof(char) * (BUFF_SIZE + 1));
		if ((ret = read(fd, buffer, BUFF_SIZE)) == -1)
			return (-1);
		buffer[ret] = '\0';
		mem = ft_strjoin(mem, buffer);
		free(buffer);
	}
	*line = ft_strdup(mem);
	mem = mem + ft_strlen(*line) + 1;
	if (ret < BUFF_SIZE && (ft_strlen(*line) == 0) && ft_strlen(mem) == 0)
		return (0);
	return (1);
}

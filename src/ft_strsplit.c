/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrosnie <acrosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 17:51:18 by acrosnie          #+#    #+#             */
/*   Updated: 2014/01/12 15:38:44 by acrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../main.h"

char	**ft_strsplit(const char* str, const char c)
{
	char	*buff;
	char	**result;
	int		i;
	int		j;
	int		k;

	k = j = i = 0;
	result = ft_memalloc(sizeof(str) * ft_strlen(str) + 10);
	buff = ft_memalloc(ft_strlen(str) + 1);
	while (str[i])
	{
		if ((str[i] == c && buff[0]))
		{
			buff[j] = '\0';
			result[k++] = ft_strjoin("", buff);
			ft_bzero(buff, j);
			buff = ft_memalloc(ft_strlen(str) + 1);
			j = 0;
		}
		else if (str[i] != c)
			buff[j++] = str[i];
		i++;
	}
	if (buff[0])
	{
		buff[j] = '\0';
		result[k++] = ft_strjoin("", buff);
	}	
	result[k] = '\0';
    return (result);
}

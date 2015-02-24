/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrosnie <acrosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 13:34:10 by acrosnie          #+#    #+#             */
/*   Updated: 2013/11/22 17:08:39 by acrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>

void	ft_bzero(void *s, size_t n)
{
    char	*buff;
	int		i;

	i = -1;
    buff = s;
	if (s && n)
	{
		while (++i < (int)n)
			buff[i] = 0;
	}
}
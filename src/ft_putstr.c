/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrosnie <acrosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 14:17:42 by acrosnie          #+#    #+#             */
/*   Updated: 2014/01/12 15:40:33 by acrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../main.h"

void	ft_putstr(char const *s)
{
	char	*buff;
	int		i;

	i = -1;
	buff = (char *)s;
	while (buff[++i])
		ft_putchar(buff[i]);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrosnie <acrosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 11:33:13 by acrosnie          #+#    #+#             */
/*   Updated: 2013/11/22 18:17:13 by acrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>

size_t		ft_strlen(const char *string)
{
	size_t		i;

	if (!string)
		return (0);
	i = 0;
	while (*string++)
	{
		i++;
	}
	return (i);
}

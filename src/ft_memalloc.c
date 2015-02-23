/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrosnie <acrosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 17:00:21 by acrosnie          #+#    #+#             */
/*   Updated: 2014/01/03 01:36:00 by acrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_bzero(void *s, size_t n);

void*	ft_memalloc(size_t size)
{
	void	*str;
	int		i;

	i = -1;
	if (!(str = malloc(size)))
		return (NULL);
	ft_bzero(str, size);
	return (str);
}

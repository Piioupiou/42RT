/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrosnie <acrosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/05 21:46:57 by acrosnie          #+#    #+#             */
/*   Updated: 2015/01/05 21:46:57 by acrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "../main.h"

void	ft_bzero(void *s, size_t n)
{
	size_t		i;
	char		*a;

	i = 0;
	a = (char*)s;
	while (n > i)
	{
		a[i] = '\0';
		i++;
	}
}

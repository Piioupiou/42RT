/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrosnie <acrosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 14:35:17 by acrosnie          #+#    #+#             */
/*   Updated: 2014/01/12 15:49:55 by acrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../main.h"
#include <stdlib.h>

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	int		len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	if ((dst = (char *)malloc(sizeof(char) * len + 1)))
	{
		len = 0;
		while (*s1 != '\0')
		{
			dst[len] = *s1;
			s1++;
			len++;
		}
		while (*s2 != '\0')
		{
			dst[len] = *s2;
			len++;
			s2++;
		}
		dst[len] = '\0';
		return (dst);
	}
	return (NULL);
}

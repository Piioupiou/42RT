/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrosnie <acrosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/05 21:55:09 by acrosnie          #+#    #+#             */
/*   Updated: 2015/01/05 21:55:09 by acrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../main.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strnew;
	int		s1len;
	int		s2len;

	if (!s1 && !s2)
		return (NULL);
	s1len = (s1 != NULL) ? ft_strlen(s1) : 0;
	s2len = (s2 != NULL) ? ft_strlen(s2) : 0;
	strnew = (char *)malloc (s1len + s2len + 1);
	if (strnew == NULL)
		return (NULL);
	strnew[s1len + s2len] = 0;
	strnew[0] = 0;
	if (s1len != 0)
		ft_strcat(strnew, s1);
	if (s2len != 0)
		ft_strcat(strnew, s2);
	return (strnew);
}

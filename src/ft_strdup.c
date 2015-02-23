/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrosnie <acrosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 16:46:29 by acrosnie          #+#    #+#             */
/*   Updated: 2014/01/12 15:47:59 by acrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "../main.h"

char    *ft_strdup(const char *s1)
{
    char    *d;
    int     i;

    d = malloc(ft_strlen (s1) + 1);
    i = 0;
    if (d != NULL)
    {
        while (1)
        {
            d[i] = s1[i];
            if (d[i] == '\0')
                break;
            ++i;
        }
    }
    return (d);
}

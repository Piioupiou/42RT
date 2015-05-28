/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrosnie <acrosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/05 21:46:44 by acrosnie          #+#    #+#             */
/*   Updated: 2015/02/21 22:42:47 by acrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "../main.h"
#include <stdio.h>
#include <stdlib.h>

int	ok_while(char s)
{
	if (s == ' ' || s == '\t' || s == '\n'
		|| s == '\v' || s == '\f' || s == '\r')
		return (1);
	return (0);
}

int	allowsymbole(char s)
{
	if (s != '-' && s != '+' && (s < 48 || s > 57) && s != ' ')
	{
		if (!ok_while(s))
			return (0);
	}
	return (1);
}

int ft_calc(const char *str, int i, int number)
{
	while (str[i++])
	{
		if (str[i - 1] >= '0' && str[i - 1] <= '9')
		{
			number *= 10;
			number += str[i - 1] - '0';
		}
		else
			break ;
	}
	return (number);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		neg;
	int		number;

	i = -1;
	number = 0;
	neg = 0;
	if (allowsymbole(str[0]) == 0)
		return (0);
	while (ok_while(str[++i]))
		;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			neg = -2;
	}
	number = ft_calc(str, i, number);
	return (number * (neg + 1));
}

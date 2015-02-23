/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrosnie <acrosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 11:27:39 by acrosnie          #+#    #+#             */
/*   Updated: 2014/01/12 15:52:51 by acrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int		i;
	int		neg;
	int		number;

	i = -1;
	number = neg = 0;
	while (str[++i] == ' ' || str[i] == '\t');
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			neg = -2;
	}
	while (str[i++])
	{
		if (str[i - 1] >= '0' && str[i - 1] <= '9')
		{
			number *= 10;
			number += str[i - 1] - '0';
		}
		else
			break;
	}
	return (number * (neg + 1));
}

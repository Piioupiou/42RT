/* ************************************************************************** */
/*	                                                                   		  */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrosnie <acrosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/31 00:50:58 by acrosnie          #+#    #+#             */
/*   Updated: 2015/02/24 21:11:12 by pgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

float	ft_rad(float angle)
{
	return (M_PI * (angle) / 180);
}

float	square(float nbr)
{
	nbr = nbr * nbr;
	return (nbr);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_math.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrosnie <acrosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/21 05:15:09 by acrosnie          #+#    #+#             */
/*   Updated: 2015/05/21 05:15:09 by acrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

float	ft_square(float nbr)
{
	nbr = nbr * nbr;
	return (nbr);
}

t_vec	*normalize(t_vec *v1)
{
	float	m;

	m = magnitude(v1);
	v1->x = v1->x / m;
	v1->y = v1->y / m;
	v1->z = v1->z / m;
	return (v1);
}

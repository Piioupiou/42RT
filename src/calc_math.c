/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_math.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrosnie <acrosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/21 05:15:09 by acrosnie          #+#    #+#             */
/*   Updated: 2015/05/29 14:47:50 by pgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	create_vec(t_data *d, int number)
{
	int i;

	d->objet[d->n]->m_vec = ft_memalloc(sizeof(t_vec *) * 10);
	i = -1;
	while (++i < number)
	{
		d->objet[d->n]->m_vec[i] = ft_vec(0, 0, 0);
	}
}

float	magnitude(t_vec *v)
{
	return (sqrt((v->x * v->x) + (v->y * v->y) + (v->z * v->z)));
}

void	color_assigne(t_color *c, float r, float g, float b)
{
	c->r = r;
	c->g = g;
	c->b = b;
}

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

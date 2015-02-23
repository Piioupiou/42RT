/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrosnie <acrosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/06 20:18:32 by acrosnie          #+#    #+#             */
/*   Updated: 2014/02/12 11:26:16 by acrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"
#include <stdlib.h>

float		findinter_sphere(t_ray *fray, t_objet *sphere)
{
	float    delta;
	float  a, b, c, tmpa, tmpb, tmpc;
	t_ray   *ray;

	ray = ft_memalloc(sizeof(t_ray) + 1);
	ray->o = vector_sub(fray->o, sphere->ori);
	ray->d = vector_sub(fray->d, sphere->ori);
	a = ray->d->x - ray->o->x;
	b = ray->d->y - ray->o->y;
	c = ray->d->z - ray->o->z;
	tmpa = pow(a, 2) + pow(b, 2) + pow(c, 2);
	tmpb = 2.0 * ((ray->o->x * a) + (ray->o->y * b) + (ray->o->z * c));
	tmpc = pow(ray->o->x, 2) + pow(ray->o->y, 2) + pow(ray->o->z, 2) - pow(sphere->radius, 2);
	delta = pow(tmpb, 2) - (4 * tmpa * tmpc);
	if (delta >= 0)
		return (delta);
	return (0);
}

int		findinter_cylinder(t_ray *fray, t_objet *cylinder)
{
	float  delta;
	float  a, b, c, tmpa, tmpb, tmpc, x1, x2;
	t_ray   *rayfound;
	t_ray   *ray;

	ray = ft_memalloc(sizeof(t_ray));
	ray->o = vector_sub(fray->o, cylinder->ori);
	ray->d = vector_sub(fray->d, cylinder->ori);
	a = ray->d->x - ray->o->x;
	b = ray->d->y - ray->o->y;
	c = ray->d->z - ray->o->z;
	tmpa = square(a) + square(c);
	tmpb = 2 * ((ray->o->z * c) + (ray->o->x * a));
	tmpc = square(ray->o->z) + square(ray->o->x) - square(cylinder->radius);
	delta = square(tmpb) - (4 * (tmpa) * (tmpc));
	if (tmpa == 0)
		return (0);
	if (delta > 0)
	{
		x1 = ((- tmpb) - sqrt(delta)) / (2 * tmpa);
		x2 = ((- tmpb) + sqrt(delta)) / (2 * tmpa);
		rayfound = getfoundray(x1, x2, a, b, c, ray);
		return (checkfoundray(rayfound, cylinder));
	}
	if (delta == 0)
	{
		x1 = ((- tmpb) / (2 * tmpa));
		rayfound = getfoundray(x1, (x1 + 2), a, b, c, ray);
		return (checkfoundray(rayfound, cylinder));
	}
	return (0);
}

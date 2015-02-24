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

int hitSphere(t_ray *r, t_objet *s, float *t)
{
   // intersection rayon/sphere
	t_vec *dist = vector_sub(s->ori, r->start); 
  	float B = vector_dot(r->dir, dist);
  	float D = B * B - vector_dot(dist, dist) + s->radius * s->radius; 
  	if (D < 0.0f) 
  		return (0); 
   float t0 = B - sqrtf(D); 
   float t1 = B + sqrtf(D);
   int retvalue = 0;  
   if ((t0 > 0.1f) && (t0 < *t)) 
   {
     *t = t0;
     retvalue = 1; 
   } 
   if ((t1 > 0.1f) && (t1 < *t)) 
   {
     *t = t1; 
     retvalue = 1; 
   }
  return retvalue;
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

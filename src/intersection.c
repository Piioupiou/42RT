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

int hit_plane(t_objet *p, t_ray *ray, float *t)
{
    float t2;
    float dv;
    
    normalize(p->normal);
    dv = vector_dot(p->normal, ray->dir);
    if (dv == 0)
      return (0);
    t2 = -(vector_dot(p->normal, vector_sub(ray->start, p->point)) / dv);
    if (t2 < 0.01f)
      return (0);
    if (t2 < *t)
      *t = t2;
    else
      return (0);
    if (dv < 0)
      p->normalInfo = normalize(p->normal);
    else
      p->normalInfo = negative(normalize(p->normal));

    return (1);
}

int		findinter_cylinder(t_ray *fray, t_objet *cylinder)
{
	(void) cylinder;
	(void) fray;
	return (0);
}

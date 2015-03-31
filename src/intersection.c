/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrosnie <acrosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/06 20:18:32 by acrosnie          #+#    #+#             */
/*   Updated: 2015/03/31 19:34:57 by pgallois         ###   ########.fr       */
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
	t_vec *normal_tmp;
	t_vec *rstart;
	t_vec *rdir;

	rstart = vector_copy(ray->start);
	rdir = vector_copy(ray->dir);
	normal_tmp = vector_copy(p->normal);
	rotate_vec_axe(normal_tmp, ft_vec(p->anglx, p->angly, p->anglz));
	rotate_vec_axe(rstart, ft_vec(p->anglx, p->angly, p->anglz));
	rotate_vec_axe(rdir, ft_vec(p->anglx, p->angly, p->anglz));
    normalize(normal_tmp);
    dv = vector_dot(normal_tmp, rdir);
    if (dv == 0)
      return (0);
    t2 = -(vector_dot(normal_tmp, vector_sub(rstart, p->point)) / dv);
    if (t2 < 0.01f)
      return (0);
    if (t2 < *t)
      *t = t2;
    else
      return (0);
    if (dv < 0)
      p->normalInfo = normalize(normal_tmp);
    else
      p->normalInfo = negative(normalize(normal_tmp));
    return (1);
}

int   hit_cylinder(t_objet *p, t_ray *ray, float *t)
{
  float Aq,Bq,Cq;
  float A,B,C; // Coeff de la quadrique cylindre
  float det,t0,t1,t2;
  t_vec *intersect;
  float Xd,Yd,Zd,Xo,Yo,Zo;

  Xd = ray->dir->x;
  Yd = ray->dir->y;
  Zd = ray->dir->z;

  Xo = ray->start->x - p->ori->x;
  Yo = ray->start->y - p->ori->y;
  Zo = ray->start->z - p->ori->z;

  if (p->normal_ext->x == 1.0) 
    A = 0;
  else
    A = 1;
  if (p->normal_ext->y == 1.0) 
    B = 0;
  else
    B = 1;
  if (p->normal_ext->z == 1.0) 
    C = 0;
  else
    C = 1;
  Aq = A*Xd*Xd + B*Yd*Yd + C*Zd*Zd;
  Bq = 2*A*Xd*Xo + 2*B*Yd*Yo + 2*C*Zd*Zo; 
  Cq = A*Xo*Xo + B*Yo*Yo + C*Zo*Zo - p->radius;

  if (Aq == 0)
    t2 = -(Cq / Bq);
  else
  {
    if((det=Bq*Bq - 4 * Aq * Cq) < 0)
      return 0;

    // Calcul t0 et t1
    t0 = ( - Bq - sqrt(det) )/ (2*Aq);
    t1 = ( - Bq + sqrt(det) )/ (2*Aq);
    if( t0<0 && t1<0)
      return 0;
    if (t1 < t0)
      t2 = t1;
    else
      t2 = t0;
  }
  if (t2 < 0.01) 
    return (0);
  intersect = vector_add(ray->start, ft_vec(Xd * t2,Yd * t2,Zd * t2));

  if( p->h != 0 &&( ((A==0)&&(fabs((vector_sub(intersect,p->ori))->x)>p->h)) || ((B==0)&&(fabs((vector_sub(intersect,p->ori))->y)>p->h)) || ((C==0)&&(fabs((vector_sub(intersect,p->ori))->z)>p->h))) )
    return 0;
  
//   //   // Calcul de la normale
    p->normalInfo->x = 2*A*(intersect->x- p->ori->x);
    p->normalInfo->y = 2*B*(intersect->y- p->ori->y);
    p->normalInfo->z = 2*C*(intersect->z- p->ori->z);

  if (vector_dot(p->normalInfo, ray->dir) < 0)
    p->normalInfo = normalize(p->normalInfo);
  else
    p->normalInfo = negative(normalize(p->normalInfo));

// //----------
   if ((t2 > 0.1f) && (t2 < *t)) 
   {
     *t = t2;
     return (1);
   }

    return 0;
}

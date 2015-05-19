/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrosnie <acrosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/06 20:18:32 by acrosnie          #+#    #+#             */
/*   Updated: 2015/05/19 03:11:11 by pgallois         ###   ########.fr       */
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

t_vec   *get_normal_at_cone(t_objet *cone, t_vec *point)
{
	t_vec  *v;

	v = normalize(vector_add(point, negative(cone->ori)));
	return (v);
}

int    delta_cone(float *t, float delta, float a, float b)
{
	float  x1;
	float  x2;

	x1 = (-b - sqrt(delta)) / (2 * a);
	x2 = (-b + sqrt(delta)) / (2 * a);
	if (x1 > 0.000001 && (x1 < x2 || x2 < 0.000001) && x1 < *t)
	{
		*t = x1;
	}
	else if (x2 > 0.00001 && (x2 < x1 || x1 < 0.00001) && x2 < *t)
	{
		*t = x2;
	}
	return (1);
}



int hit_cone(t_objet *p, t_ray *ray, float *t)
{
	float a, b ,c, delta, k;
	float alpha = 35;
	float tanj = tan(pow(alpha * M_PI / 180, 2.0f));
	//float al = alpha * M_PI / 180;
	t_vec *rstart = NULL;
	t_vec *rdir = NULL;
	rstart = vector_copy(ray->start);
	rdir = vector_copy(ray->dir);
	//rotate_vec_axe(rdir, ft_vec(p->anglx, p->angly, p->anglz));
	//a = pow(ray->dir->x, 2) + pow(ray->dir->y, 2) - (pow(ray->dir->z, 2) / tanj);
	//b = 2 * ((p->ori->x) * ray->dir->x + (p->ori->y) * ray->dir->y) - ((ray->dir->z) / tanj);
	//c = pow((p->ori->x), 2) + pow((p->ori->y), 2) - ((p->ori->z) / tanj);
	a = pow(rdir->x, 2.0f) + pow(rdir->y, 2.0f) - pow(alpha * M_PI / 180, 2.0f) * pow(rdir->z, 2.0f);
	b = rstart->x * rdir->x + rstart->y * rdir->y - pow(alpha * M_PI / 180, 2.0f) * rstart->z * rdir->z;
	b = b * 2.0f;
	c = pow(rstart->x, 2.0f) + pow(rstart->y, 2) - pow(alpha * M_PI / 180, 2.0f) * pow(rstart->z, 2);
	delta = pow(b, 2.0f) - 4 * a * c;
	if (delta >= 0)
	{
		k = ((-b) - sqrt(delta)) / (2 * a);
		float tmp = (-b + sqrt(delta)) / (2 * a);
		if (tmp < k && tmp > 0)
			k = tmp;
		if (k > 0 && *t > k)
		{
			*t = k;
			t_vec *P = NULL;
			t_vec *V = NULL;
			float m;
			P = vector_add(ray->start, ft_vec(ray->dir->x * k, ray->dir->y * k, ray->dir->z * k));
			V = ft_vec(P->x - p->ori->x, 0, P->z - p->ori->z);
			m = sqrt(pow(V->x, 2) + pow(V->z, 2));
			V->x /= m;
			V->z /= m;
			p->normalInfo->x = P->x;
			p->normalInfo->y = P->y;
			p->normalInfo->z = -P->z * tanj;
			//p->normalInfo->x = V->x * p->h / al;
			//p->normalInfo->y = al / p->h;
			//p->normalInfo->z = V->z * p->h / al;
			if (vector_dot(p->normalInfo, rdir) < 0)
				p->normalInfo = normalize(p->normalInfo);
			else
				p->normalInfo = negative(normalize(p->normalInfo));
			return (1);
		}
	}
	return (0);
}

int   hit_cylinder(t_objet *p, t_ray *ray, float *t)
{
	float Aq,Bq,Cq;
	float A,B,C; // Coeff de la quadrique cylindre
	float det,t0,t1,t2;
	t_vec *intersect;
	float Xd,Yd,Zd,Xo,Yo,Zo;
	t_vec *rstart;
	t_vec *rdir;
	t_vec *pori;
	t_vec *pnormalext;

	rstart = vector_copy(ray->start);
	rdir = vector_copy(ray->dir);
	pori = vector_copy(p->ori);
	pnormalext = vector_copy(p->normal_ext);
	rotate_vec_axe(rstart, ft_vec(p->anglx, p->angly, p->anglz));
	rotate_vec_axe(rdir, ft_vec(p->anglx, p->angly, p->anglz));
	rotate_vec_axe(pori, ft_vec(p->anglx, p->angly, p->anglz));
	normalize(pnormalext);
	// t_ray *ray2;

	// ray2 = ft_memalloc(sizeof(t_ray));
	// ray2->start = vector_copy(ray->start);
	// ray2->dir = vector_copy(ray->dir);
	// ray2 = rotation(ray2, p);
	Xd = rdir->x;
	Yd = rdir->y;
	Zd = rdir->z;

	Xo = rstart->x - pori->x;
	Yo = rstart->y - pori->y;
	Zo = rstart->z - pori->z;

	if (pnormalext->x == 1.0)
		A = 0;
	else
		A = 1;
	if (pnormalext->y == 1.0)
		B = 0;
	else
		B = 1;
	if (pnormalext->z == 1.0)
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
	if (t2 < 1)
		return (0);
	intersect = vector_add(rstart, ft_vec(Xd * t2,Yd * t2,Zd * t2));
	if( p->h != 0 &&( ((A==0)&&(fabs((vector_sub(intersect,pori))->x)>p->h)) || ((B==0)&&(fabs((vector_sub(intersect,pori))->y)>p->h)) || ((C==0)&&(fabs((vector_sub(intersect,pori))->z)>p->h))) )
		return 0;

	//   //   // Calcul de la normale
	p->normalInfo->x = 2*A*(intersect->x- p->ori->x);
	p->normalInfo->y = 2*B*(intersect->y- p->ori->y);
	p->normalInfo->z = 2*C*(intersect->z- p->ori->z);
	rotate_vec_axe(p->normalInfo, ft_vec(-p->anglx, -p->angly, -p->anglz));
	if (vector_dot(p->normalInfo, ray->dir) < 0)
		p->normalInfo = normalize(p->normalInfo);
	else
		p->normalInfo = negative(normalize(p->normalInfo));

	// //----------
	if ((t2 > 0.0f) && (t2 < *t)) 
	{
		*t = t2;
		return (1);
	}

	return 0;
}

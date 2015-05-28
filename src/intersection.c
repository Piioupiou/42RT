/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrosnie <acrosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/06 20:18:32 by acrosnie          #+#    #+#             */
/*   Updated: 2015/05/19 06:52:03 by pgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"
#include <stdlib.h>

int		hit_sphere(t_ray *r, t_objet *p, float *t)
{
	int		retvalue;

	retvalue = 0;
	assign_value_vec(vector_sub(*p->ori, *r->start), p->m_vec[0]);
	p->tab[0] = vector_dot(*r->dir, *p->m_vec[0]);
	p->tab[1] = p->tab[0] * p->tab[0] - vector_dot(*p->m_vec[0], *p->m_vec[0]) + p->radius * p->radius;
	if (p->tab[1] < 0.0f)
		return (0);
	p->tab[2] = p->tab[0] - sqrtf(p->tab[1]);
	p->tab[3] = p->tab[0] + sqrtf(p->tab[1]);
	if ((p->tab[2] > 0.1f) && (p->tab[2] < *t))
	{
		*t = p->tab[2];
		retvalue = 1;
	}
	if ((p->tab[3] > 0.1f) && (p->tab[3] < *t))
	{
		*t = p->tab[3];
		retvalue = 1;
	}
	if (retvalue == 1)
		retvalue = normal_sphere(r, p, t);
	return (retvalue);
}

int		hit_plane(t_objet *p, t_ray *ray, float *t)
{
	float t2;
	float dv;

	p->m_vec[0] = vector_assign(p->m_vec[0], ray->start);
	p->m_vec[1] = vector_assign(p->m_vec[1], ray->dir);
	p->m_vec[2] = vector_assign(p->m_vec[2], p->normal);
	rotate_vec_axe(p->m_vec[2], p->angle);
	rotate_vec_axe(p->m_vec[0], p->angle);
	rotate_vec_axe(p->m_vec[1], p->angle);
	normalize(p->m_vec[2]);
	dv = vector_dot(*p->m_vec[2], *p->m_vec[1]);
	if (dv == 0)
		return (0);
	t2 = -(vector_dot(*p->m_vec[2], vector_sub(*p->m_vec[0], *p->point)) / dv);
	if (t2 < 0.01f)
		return (0);
	if (t2 < *t)
		*t = t2;
	else
		return (0);
	normal_plane(dv, p->m_vec[2], p);
	return (1);
}

int		hit_cone_norm(float *tab, t_vec **rr, t_objet *p, float *t)
{
	float tmp;

	tab[4] = ((-tab[1]) - sqrtf(tab[3])) / (2 * tab[0]);
	tmp = (-tab[1] + sqrtf(tab[3])) / (2 * tab[0]);
	if (tmp <= tab[4] && tmp > 0)
		tab[4] = tmp;
	if (tab[4] > 0.1f && *t > tab[4])
	{
		*t = tab[4];
		rr[4]->x = rr[1]->x * tab[4];
		rr[4]->y = rr[1]->y * tab[4];
		rr[4]->z = rr[1]->z * tab[4];
		assign_value_vec(*rr[4], rr[3]);
		assign_value_vec(vector_add(*rr[0], *rr[3]), rr[2]);
		normal_cone(rr[2], p, rr, tab);
		rotate_vec_axe(p->normali, negative(p->angle));
		negative(p->angle);
		return (1);
	}
	return (0);
}

int		hit_cone(t_objet *p, t_ray *ray, float *t)
{
	p->tab[5] = powf(p->h * M_PI / 180.0f, 2.0f);
	assign_value_vec(vector_sub(*ray->start, *p->ori), p->m_vec[0]);
	assign_value_vec(*ray->dir, p->m_vec[1]);
	rotate_vec_axe(p->m_vec[1], p->angle);
	rotate_vec_axe(p->m_vec[0], p->angle);
	p->tab[0] = powf(p->m_vec[1]->x, 2.0f) + powf(p->m_vec[1]->y, 2.0f)
		- p->tab[5] * powf(p->m_vec[1]->z, 2.0f);
	p->tab[1] = p->m_vec[0]->x * p->m_vec[1]->x + p->m_vec[0]->y * p->m_vec[1]->y
		- p->tab[5] * p->m_vec[0]->z * p->m_vec[1]->z;
	p->tab[1] = p->tab[1] * 2.0f;
	p->tab[2] = powf(p->m_vec[0]->x, 2.0f) + powf(p->m_vec[0]->y, 2)
		- p->tab[5] * powf(p->m_vec[0]->z, 2);
	p->tab[3] = powf(p->tab[1], 2.0f) - 4 * p->tab[0] * p->tab[2];
	if (p->tab[3] > 0.1f)
		return (hit_cone_norm(p->tab, p->m_vec, p, t));
	return (0);
}

int		hit_cylinder(t_objet *p, t_ray *ray, float *t)
{
	vector_assign(p->m_vec[0], ray->start);
	vector_assign(p->m_vec[1], ray->dir);
	vector_assign(p->m_vec[2], p->ori);
	vector_assign(p->m_vec[3], ray->dir);
	rotate_vec_axe(p->m_vec[0], p->angle);
	rotate_vec_axe(p->m_vec[1], p->angle);
	rotate_vec_axe(p->m_vec[2], p->angle);
	p->tab[10] = p->m_vec[1]->x;
	p->tab[11] = p->m_vec[1]->y;
	p->tab[12] = p->m_vec[1]->z;
	p->tab[13] = p->m_vec[0]->x - p->m_vec[2]->x;
	p->tab[14] = p->m_vec[0]->y - p->m_vec[2]->y;
	p->tab[15] = p->m_vec[0]->z - p->m_vec[2]->z;
	p->tab[3] = (p->normal_ext->x == 1.0) ? 0 : 1;
	p->tab[4] = (p->normal_ext->y == 1.0) ? 0 : 1;
	p->tab[5] = (p->normal_ext->z == 1.0) ? 0 : 1;
	return (hit_cylinder2(p->tab, p->m_vec, p, t));
}


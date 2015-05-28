/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrosnie <acrosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/21 06:57:52 by acrosnie          #+#    #+#             */
/*   Updated: 2015/05/21 06:57:56 by acrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

int	normal_sphere(t_ray *r, t_objet *p, float *t)
{
	float	temp;
	int		retvalue;

	retvalue = 1;
	assign_value_vec(vector_sub(vector_add(*r->start, vector_dot_float(*t, *r->dir)), *p->ori), p->normali);
	temp = vector_dot(*p->normali, *p->normali);
	if (temp == 0.0f)
		retvalue = 0;
	temp = 1.0f / sqrtf(temp);
	assign_value_vec(vector_dot_float(temp, *p->normali), p->normali);

	return (retvalue);
}

int	normal_plane(float dv, t_vec *normal_tmp, t_objet *p)
{
	if (dv < 0)
		p->normali = normalize(normal_tmp);
	else
		p->normali = negative(normalize(normal_tmp));
	return (0);
}

int	normal_cone(t_vec *pp, t_objet *p, t_vec **rr, float *tab)
{
	p->normali->x = pp->x;
	p->normali->y = pp->y;
	p->normali->z = -pp->z * tanf(tab[5]);
	if (vector_dot(*p->normali, *rr[1]) < 0)
		p->normali = normalize(p->normali);
	else
		p->normali = negative(normalize(p->normali));
	return (0);
}

int normal_cylindre(float *tab, t_vec **vect, t_objet *p, float *t)
{
	p->m_vec[6]->x = tab[10] * tab[9];
	p->m_vec[6]->y = tab[11] * tab[9];
	p->m_vec[6]->z = tab[12] * tab[9];
	assign_value_vec(vector_add(*vect[0], *p->m_vec[6]), p->m_vec[5]);
	if (p->h != 0 && (((tab[3] == 0) &&
		(fabs((vector_sub(*p->m_vec[5], *vect[2])).x) > p->h)) || ((tab[4] == 0)
			&& (fabs((vector_sub(*p->m_vec[5], *vect[2])).y) > p->h)) ||
		((tab[5] == 0) && (fabs((vector_sub(*p->m_vec[5], *vect[2])).z) > p->h))))
		return (0);
	p->normali->x = 2 * tab[3] * (p->m_vec[5]->x - p->ori->x);
	p->normali->y = 2 * tab[4] * (p->m_vec[5]->y - p->ori->y);
	p->normali->z = 2 * tab[5] * (p->m_vec[5]->z - p->ori->z);
	negative(p->angle);
	rotate_vec_axe(p->normali, p->angle);
	negative(p->angle);
	if (vector_dot(*p->normali, *vect[3]) < 0)
	{
		//negative(p->normali);
		normalize(p->normali);
	}
	else
	{
		negative(p->normali);
		normalize(p->normali);
		
	}
	if ((tab[9] > 0.1f) && (tab[9] < *t))
	{
		*t = tab[9];
		return (1);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vecteur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrosnie <acrosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 22:30:34 by acrosnie          #+#    #+#             */
/*   Updated: 2014/02/14 11:43:53 by acrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"
#include <math.h>

t_vec	*normalize(t_vec *v1)
{
	t_vec	*v2;
	float	m;

	m = magnitude(v1);
	v2 = ft_vec(v1->x / m, v1->y / m, v1->z / m);
	return (v2);
}

t_vec	*crossProduct(t_vec *v1, t_vec *v2)
{
	t_vec	*rslt;

	rslt = ft_vec(v1->y * v2->z - v1->z * v2->y,
						v1->z * v2->x - v1->x * v2->z,
						v1->x * v2->y - v1->y * v2->x);
	return (rslt);
}

t_vec	*negative(t_vec *v1)
{
	t_vec	*v2;

	v2 = ft_vec(v1->x * -1, v1->y * -1, v1->z * -1);
	return (v2);
}

float	magnitude(t_vec *v)
{
	return (sqrt((v->x * v->x) + (v->y * v->y) + (v->z * v->z)));
}

float	vector_dot(t_vec *a, t_vec *b)
{
	return ((a->x * b->x) + (a->y * b->y) + (a->z * b->z));  
}

t_vec 	*vector_dot_float(float c, t_vec *v1)
{
	t_vec	*v;

	v = ft_memalloc(sizeof(t_vec) + 1);

	v->x = v1->x * c;
	v->y = v1->y * c;
	v->z = v1->z * c;
	return v;
}

t_vec	*vector_copy(t_vec *a)
{
	return (ft_vec(a->x, a->y, a->z));
}

t_vec	*ft_vec(float x, float y, float z)
{
	t_vec	*vec;

	vec = ft_memalloc(sizeof(t_vec) + 1);
	vec->x = x;
	vec->y = y;
	vec->z = z;
	return (vec);
}

t_vec	*vector_sub(t_vec *a, t_vec *b)
{
	t_vec	*v;

	v = ft_memalloc(sizeof(t_vec) + 1);
	v->x = a->x - b->x;
	v->y = a->y - b->y;
	v->z = a->z - b->z;
	return (v);
}

t_vec	*vector_add(t_vec *a, t_vec *b)
{
	t_vec	*v;

	v = ft_memalloc(sizeof(t_vec) + 1);
	v->x = a->x + b->x;
	v->y = a->y + b->y;
	v->z = a->z + b->z;
	return (v);
}
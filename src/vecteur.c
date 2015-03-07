/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vecteur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrosnie <acrosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 22:30:34 by acrosnie          #+#    #+#             */
/*   Updated: 2015/02/28 05:25:54 by pgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"
#include <math.h>

float GetSquareLength(t_vec *v)
{
    return (v->x * v->x + v->y * v->y + v->z * v->z);
}

void    printVec(t_vec *v)
{
	printf("x = %f, y = %f, z = %f\n", v->x, v->y, v->z);
}

float	getMagnitude(t_vec *v)
{
	return (sqrtf(v->x * v->x + v->y * v->y + v->z * v->z));
}

t_vec	*normalize(t_vec *v)
{
	int		mag;

	mag = getMagnitude(v);
	v->x /= mag;
	v->y /= mag;
	v->z /= mag;
	return v;
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

t_vec	*vector_Vmultiple(t_vec *a, t_vec *b)
{
	t_vec	*v;

	v = ft_memalloc(sizeof(t_vec) + 1);
	v->x = (a->y * b->z) - (a->z * b->y);
	v->y = (a->z * b->x) - (a->x * b->z);
	v->z = (a->x * b->y) - (a->y * b->x);
	return (v);
}

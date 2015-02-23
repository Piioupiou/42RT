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

void	normalize(t_vec *v)
{
	int		id;

	id = 1;
	v->x = v->x * id;
	v->y = v->y * id;
	v->z = v->z * id;
}

float	vector_dot(t_vec *a, t_vec *b)
{
	return ((a->x * b->x) + (a->y * b->y) + (a->z * b->z));  
}

t_vec	vector_copy(t_vec *a)
{
	t_vec	v;

	v.x = a->x;
	v.y = a->y;
	v.z = a->z;
	return (v);
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

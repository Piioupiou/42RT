/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vecteur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrosnie <acrosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 22:30:34 by acrosnie          #+#    #+#             */
/*   Updated: 2015/05/29 14:47:34 by pgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"
#include <math.h>

t_vec	*cross_product(t_vec *v1, t_vec *v2)
{
	t_vec	*rslt;

	rslt = ft_vec(v1->y * v2->z - v1->z * v2->y,
						v1->z * v2->x - v1->x * v2->z,
						v1->x * v2->y - v1->y * v2->x);
	return (rslt);
}

t_vec	*negative(t_vec *v1)
{
	v1->x *= -1;
	v1->y *= -1;
	v1->z *= -1;
	return (v1);
}

float	vector_dot(t_vec a, t_vec b)
{
	return ((a.x * b.x) + (a.y * b.y) + (a.z * b.z));
}

t_vec	vector_dot_float(float c, t_vec v1)
{
	t_vec	v;

	v.x = v1.x * c;
	v.y = v1.y * c;
	v.z = v1.z * c;
	return (v);
}

void	assign_value_vec(t_vec vec1, t_vec *vec2)
{
	vec2->x = vec1.x;
	vec2->y = vec1.y;
	vec2->z = vec1.z;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vecteur_again.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrosnie <acrosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/21 05:10:05 by acrosnie          #+#    #+#             */
/*   Updated: 2015/05/21 05:10:06 by acrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"
#include <math.h>

t_vec	*vector_copy(t_vec *a)
{
	return (ft_vec(a->x, a->y, a->z));
}

t_vec	*vector_assign(t_vec *a, t_vec *b)
{
	a->x = b->x;
	a->y = b->y;
	a->z = b->z;
	return (a);
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

t_vec	vector_sub(t_vec a, t_vec b)
{
	t_vec	v;

	v.x = a.x - b.x;
	v.y = a.y - b.y;
	v.z = a.z - b.z;
	return (v);
}

t_vec	vector_add(t_vec a, t_vec b)
{
	t_vec	v;

	v.x = a.x + b.x;
	v.y = a.y + b.y;
	v.z = a.z + b.z;
	return (v);
}

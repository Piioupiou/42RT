/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrosnie <acrosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/06 20:59:28 by acrosnie          #+#    #+#             */
/*   Updated: 2014/02/06 23:17:29 by acrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../main.h"

t_vec		*rotatepoint(t_vec *point, t_rotation *rotation)
{
	t_rot	*rot;
	t_vec	*res;

	rot = ft_memalloc(sizeof(t_rot));
	res = ft_memalloc(sizeof(t_vec));
	rot->c = vector_copy(rotation->point);
	rot->s = vector_copy(rotation->point);
	rot->a = vector_copy(point);
	rot->xy = (rot->c->x * rot->a->y) - rot->s->x * rot->a->z;
	rot->xz = (rot->s->x * rot->a->y) + rot->c->x * rot->a->z;
	rot->yz = rot->c->y * rot->xz - rot->s->y * rot->a->x;
	rot->yx = rot->s->y * rot->xz + rot->c->y * rot->a->x;
	rot->zx = rot->c->z * rot->yx - rot->s->z * rot->xy;
	rot->zy = rot->s->z * rot->yx + rot->c->z * rot->xy;
	res->x = rot->zx;
	res->y = rot->zy;
	res->z = rot->yz;
	return (res);
}

t_ray		*rotation(t_ray *vect, t_objet *object)
{
	t_rotation		*rotation;

	rotation = ft_memalloc(sizeof(t_rotation));
	if (object->type == 2)
	{
		rotation->point = ft_memalloc(sizeof(t_vec) + 1);
		rotation->point->x = object->normal_ext->x;
		rotation->point->y = object->normal_ext->y;
		rotation->point->z = object->normal_ext->z;
		vect->start = rotatepoint(vect->start, rotation);
		vect->dir = rotatepoint(vect->dir, rotation);
	}
	return (vect);
}

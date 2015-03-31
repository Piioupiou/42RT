/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objet.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrosnie <acrosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/06 20:23:28 by acrosnie          #+#    #+#             */
/*   Updated: 2015/03/31 18:37:20 by pgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../main.h"

void	sphere(t_data *d, t_vec *vec, int rayon, t_color *color)
{

	d->objet[d->n] = ft_memalloc(sizeof(t_objet));
	d->objet[d->n]->ori = ft_memalloc(sizeof(t_vec));
	d->objet[d->n]->ori->x = vec->x;
	d->objet[d->n]->ori->y = vec->y;
	d->objet[d->n]->ori->z = vec->z;
	d->objet[d->n]->radius = rayon;
	d->objet[d->n]->color = color;
	d->objet[d->n]->type = 1;
	d->n++;
}

void	cone(t_data *d, t_vec *vec, float h, t_color *color)
{

	d->objet[d->n] = ft_memalloc(sizeof(t_objet));
	d->objet[d->n]->ori = ft_memalloc(sizeof(t_vec));
	d->objet[d->n]->ori->x = vec->x;
	d->objet[d->n]->ori->y = vec->y;
	d->objet[d->n]->ori->z = vec->z;
	d->objet[d->n]->h = h;
	d->objet[d->n]->color = color;
	d->objet[d->n]->type = 4;
	d->objet[d->n]->normalInfo = ft_vec(0, 0, 0);
	printf("%f, %f, %f\n", d->objet[d->n]->ori->x, d->objet[d->n]->ori->y, d->objet[d->n]->ori->z);
	d->n++;
}

void	plane(t_data *d, t_vec *vec, t_vec *vec2, t_color *color, t_vec *vec3)
{

	d->objet[d->n] = ft_memalloc(sizeof(t_objet));
	d->objet[d->n]->point = ft_memalloc(sizeof(t_vec));
	d->objet[d->n]->normal = ft_memalloc(sizeof(t_vec));
	d->objet[d->n]->point->x = vec->x;
	d->objet[d->n]->point->y = vec->y;
	d->objet[d->n]->point->z = vec->z;
	d->objet[d->n]->normal->x = vec2->x;
	d->objet[d->n]->normal->y = vec2->y;
	d->objet[d->n]->normal->z = vec2->z;
	d->objet[d->n]->color = color;
	d->objet[d->n]->anglx = vec3->x;
	d->objet[d->n]->angly = vec3->y;
	d->objet[d->n]->anglz = vec3->z;
	d->objet[d->n]->type = 3;
	//printf("%f, %f, %f\n", d->objet[d->n]->normal->x, d->objet[d->n]->normal->y, d->objet[d->n]->normal->z);
	d->n++;
}

void	cylinder_start(t_data *d, float h, float rad)
{
	d->objet[d->n] = ft_memalloc(sizeof(t_objet) + 1);
	d->objet[d->n]->h = h;
	d->objet[d->n]->radius = rad;
	d->objet[d->n]->normalInfo = ft_vec(0, 0, 0);
	printf("%f\n", rad);
}

void	cylinder(t_data *d, t_vec *vec1, t_vec *vec2, t_color *color)
{
	d->objet[d->n]->ori = vector_copy(vec1);
	d->objet[d->n]->normal_ext = vector_copy(vec2);
	d->objet[d->n]->color = color;
	d->objet[d->n]->type = 2;
	printf("%f, %f, %f\n", d->objet[d->n]->normal_ext->x, d->objet[d->n]->normal_ext->y, d->objet[d->n]->normal_ext->z);
	d->n++;
}

void light(t_data *d, t_vec *vec, float intensity, t_color *color)
{
	d->objet[d->n] = ft_memalloc(sizeof(t_objet));
	d->objet[d->n]->ori = ft_memalloc(sizeof(t_vec));
	d->objet[d->n]->ori->x = vec->x;
	d->objet[d->n]->ori->y = vec->y;
	d->objet[d->n]->ori->z = vec->z;
	d->objet[d->n]->intensity = intensity;
	d->objet[d->n]->color = color;
	d->objet[d->n]->type = 10;
	d->n++;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objet.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrosnie <acrosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/06 20:23:28 by acrosnie          #+#    #+#             */
/*   Updated: 2015/03/07 17:27:47 by pgallois         ###   ########.fr       */
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

void	plane(t_data *d, t_vec *vec, t_vec *vec2, t_color *color)
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
	d->objet[d->n]->type = 3;
	//printf("%f, %f, %f\n", d->objet[d->n]->normal->x, d->objet[d->n]->normal->y, d->objet[d->n]->normal->z);
	d->n++;
}

void	cylinder_start(t_data *d, int h, int rad)
{
	d->objet[d->n] = ft_memalloc(sizeof(t_objet) + 1);
	d->objet[d->n]->h = h;
	d->objet[d->n]->radius = rad;
}

void	cylinder(t_data *d, t_vec *vec1, t_vec *vec2, int color)
{
	d->objet[d->n]->ori = ft_memalloc(sizeof(t_vec));
	d->objet[d->n]->ori->x = vec1->x;
	d->objet[d->n]->ori->y = vec1->y;
	d->objet[d->n]->ori->z = vec1->z;
	d->objet[d->n]->anglx = ft_rad(vec2->x);
	d->objet[d->n]->angly = ft_rad(vec2->y);
	d->objet[d->n]->anglz = ft_rad(vec2->z);
	d->objet[d->n]->color = convertColor(color);
	d->objet[d->n]->type = 2;
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

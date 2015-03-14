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

// void	camera(t_data *d,  int x, int y, int z)
// {
// 	// d->cam->origine->x = 1.0f;
// 	// d->cam->origine->y = 3.0f;
// 	// d->cam->origine->z = -20.0f;
// 	// d->cam->viewplaneWidth = 0.5f;
// 	// d->cam->viewplaneHeight = 0.35f;
// 	// d->cam->viewplaneDist = 1.0f;
// 	// d->cam->vise = ft_vec(0.0f, 0.0f, 0.0f);
// 	// d->cam->vecDir = vector_sub(d->cam->vise, d->cam->origine);
// 	// d->cam->vecDir = normalize(d->cam->vecDir);
// 	// d->cam->vecUp = ft_vec(0.0f, 1.0f, 0.0f);
// 	// d->cam->vecRight = vector_Vmultiple(d->cam->vecUp, d->cam->vecDir);
// 	// d->cam->vecUp = vector_Vmultiple(d->cam->vecDir, d->cam->vecRight);
// 	// t_vec *tmp1;
// 	// t_vec *tmp2;
// 	// t_vec *tmp3;
// 	// tmp1 = vector_dot_float(d->cam->viewplaneDist, d->cam->vecDir);
// 	// tmp2 = vector_dot_float(d->cam->viewplaneHeight / 2.0f, d->cam->vecUp);
// 	// tmp3 = vector_dot_float(d->cam->viewplaneWidth / 2.0f, d->cam->vecRight);
// 	// d->cam->vecUpLeft = vector_sub(vector_add(d->cam->origine, vector_add(tmp1, tmp2)), tmp3);
// 	// //d->cam->vecUpLeft =
// 	// //		vector_sub(vector_add(d->cam->origine, vector_add(vector_dot_float(
// 	// //		d->cam->viewplaneDist,d->cam->vecDir),
// 	// //		vector_dot_float(d->cam->viewplaneHeight/2.0f, d->cam->vecUp))),
// 	// //		vector_dot_float(d->cam->viewplaneWidth/2.0f, d->cam->vecRight));
// 	// d->cam->f = -(WINDOW_X / (2.0f * tan(d->cam->fov / 2.0f)));
// 	// d->cam->xIndent = d->cam->viewplaneWidth / (float)WINDOW_X;
// 	// d->cam->yIndent = d->cam->viewplaneHeight / (float)WINDOW_Y;
// }

void light(t_data *d, t_vec *vec, int intensity, t_color *color)
{
	d->objet[d->n] = ft_memalloc(sizeof(t_objet));
	d->objet[d->n]->ori = ft_memalloc(sizeof(t_vec));
	d->objet[d->n]->ori->x = vec->x;
	d->objet[d->n]->ori->y = vec->y;
	d->objet[d->n]->ori->z = vec->z;
	d->objet[d->n]->intensity = intensity;
	d->objet[d->n]->color = color;
	d->objet[d->n]->type = 10;
	printf("%f, %f, %f\n", d->objet[d->n]->ori->x, d->objet[d->n]->ori->y, d->objet[d->n]->ori->z);
	d->n++;
}

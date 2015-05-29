/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_shadow.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgallois <pgallois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/21 05:54:24 by pgallois          #+#    #+#             */
/*   Updated: 2015/05/29 14:31:58 by pgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	lambert_function_color(t_data *d, int j, t_ray light_ray, t_vec *n)
{
	float	lambert;
	float	temp;
	float	blinn_term;

	lambert = vector_dot(*light_ray.dir, *n) * d->coef;
	d->color->r += (lambert * d->objet[j]->color->r
		* d->objet[d->current]->color->r) * d->objet[j]->intensity;
	d->color->g += (lambert * d->objet[j]->color->g
		* d->objet[d->current]->color->g) * d->objet[j]->intensity;
	d->color->b += (lambert * d->objet[j]->color->b
		* d->objet[d->current]->color->b) * d->objet[j]->intensity;
	assign_value_vec(vector_sub(*light_ray.dir, *d->ray->dir), d->blinn_dir);
	temp = sqrtf(vector_dot(*d->blinn_dir, *d->blinn_dir));
	if (temp != 0.0f)
	{
		assign_value_vec(vector_dot_float((1.0f / temp), *d->blinn_dir), \
				d->blinn_dir);
		blinn_term = ft_max(vector_dot(*d->blinn_dir, *n), 0.0f);
		blinn_term = 40.0f * powf(blinn_term, 60) * d->coef;
		d->color->r += blinn_term * d->objet[d->current]->color->r;
		d->color->g += blinn_term * d->objet[d->current]->color->g;
		d->color->b += blinn_term * d->objet[d->current]->color->b;
	}
}

t_vec	*return_for_norm(t_data *d, t_ray lray, int cur_ob, t_vec *n)
{
	d->light_ray = &lray;
	d->current = cur_ob;
	return (n);
}

t_vec	*calcul_light_shadow(t_data *d, float *t, t_vec *new_s, int c)
{
	int		j;
	t_vec	*n;

	j = -1;
	n = d->objet[c]->normali;
	while (d->objet[++j])
	{
		if (d->objet[j]->type == 10 && d->option->activate_light)
		{
			assign_value_vec(vector_sub(*d->objet[j]->ori, *new_s), d->dist);
			if ((vector_dot(*n, *d->dist) <= 0.0f ||
			((*t = sqrtf(vector_dot(*d->dist, *d->dist))) <= 0.0f)))
				continue ;
			d->lray.start = new_s;
			assign_value_vec(vector_dot_float((1 / *t), *d->dist), d->lray.dir);
			if (!d->option->activate_shadow || (col_object(d, t, &d->lray) == -1
						&& (d->current = c) == c))
				lambert_function_color(d, j, d->lray, n);
		}
		else if (!d->option->activate_light)
			color_assigne(d->color, d->objet[d->current]->color->r, \
			d->objet[d->current]->color->g, d->objet[d->current]->color->b);
	}
	return (return_for_norm(d, d->lray, c, n));
}

void	calcul_next_iteration(t_data *d, t_ray *ray, t_vec *n, t_vec *new_start)
{
	float	reflet;

	reflet = 2.0f * vector_dot(*ray->dir, *n);
	d->coef *= 0.5f;
	ray->start = new_start;
	assign_value_vec(vector_sub(*ray->dir,
		vector_dot_float(reflet, *n)), ray->dir);
	d->option->level++;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objet.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrosnie <acrosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/06 20:23:28 by acrosnie          #+#    #+#             */
/*   Updated: 2015/05/19 03:53:28 by pgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	create_cylinder(t_data *d, char **split)
{
	t_vec	*vec;
	t_vec	*vec2;
	t_vec	*angle;

	d->objet[d->n] = ft_memalloc(sizeof(t_objet) + 1);
	create_vec(d, 7);
	d->objet[d->n]->h = atof(split[5]);
	d->objet[d->n]->radius = atof(split[4]);
	d->objet[d->n]->color = new_color_rgb(atof(split[9]),
		atof(split[10]), atof(split[11]));
	vec = ft_vec(atof(split[1]), atof(split[2]), atof(split[3]));
	vec2 = ft_vec(atof(split[6]), atof(split[7]), atof(split[8]));
	angle = ft_vec(atof(split[12]), atof(split[13]), atof(split[14]));
	cylinder(d, vec, vec2, angle);
}

void	create_plane(t_data *d, char **split)
{
	t_vec	*vec;
	t_vec	*vec2;
	t_vec	*angle;

	d->objet[d->n] = ft_memalloc(sizeof(t_objet));
	d->objet[d->n]->color = new_color_rgb(atof(split[7]),
		atof(split[8]), atof(split[9]));
	vec = ft_vec(atof(split[1]), atof(split[2]), atof(split[3]));
	vec2 = ft_vec(atof(split[4]), atof(split[5]), atof(split[6]));
	angle = ft_vec(atof(split[10]), atof(split[11]), atof(split[12]));
	plane(d, vec, vec2, angle);
}

void	create_light(t_data *d, char **split)
{
	t_vec	*vec;

	vec = ft_vec(atof(split[1]), atof(split[2]), atof(split[3]));
	light(d, vec, atof(split[4]), new_color_rgb(atof(split[5]),
		atof(split[6]), atof(split[7])));
}

void	create_sphere(t_data *d, char **split)
{
	t_vec	*vec;

	vec = ft_vec(atof(split[1]), atof(split[2]), atof(split[3]));
	sphere(d, vec, ft_atoi(split[4]), new_color_rgb(atof(split[5]),
		atof(split[6]), atof(split[7])));
}

void	create_cone(t_data *d, char **split)
{
	t_vec	*vec;
	t_vec	*angle;

	d->objet[d->n] = ft_memalloc(sizeof(t_objet));
	d->objet[d->n]->h = atof(split[4]);
	vec = ft_vec(atof(split[1]), atof(split[2]), atof(split[3]));
	angle = ft_vec(atof(split[8]), atof(split[9]), atof(split[10]));
	cone(d, vec, new_color_rgb(atof(split[5]), atof(split[6]),
		atof(split[7])), angle);
}

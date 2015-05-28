/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrosnie <acrosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/21 04:08:42 by acrosnie          #+#    #+#             */
/*   Updated: 2015/05/21 04:08:43 by acrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

t_camera	*new_camera(t_vec *p, t_vec *di, t_vec *r, t_vec *dwn)
{
	t_camera	*c;

	c = (t_camera*)malloc(sizeof(t_camera));
	c->campos = p;
	c->camdir = di;
	c->camright = r;
	c->camdown = dwn;
	return (c);
}

void		init_cam(t_data *d, char **split)
{
	t_camera	*c;
	t_vec		*look_at;
	t_vec		*diff_btw;

	c = new_camera(NULL, NULL, NULL, NULL);
	c->campos = ft_vec(atof(split[2]), atof(split[3]), atof(split[4]));
	look_at = ft_vec(atof(split[5]), atof(split[6]), atof(split[7]));
	c->vise = look_at;
	diff_btw = ft_vec(c->campos->x - look_at->x, c->campos->y - look_at->y,
		c->campos->z - look_at->z);
	c->camdir = normalize(negative(diff_btw));
	c->camright = normalize(cross_product(ft_vec(0, 1, 0), c->camdir));
	c->camdown = cross_product(c->camright, c->camdir);
	d->cam2 = c;
}

float		get_x_point(float x)
{
	float	rslt;

	if (WINDOW_X > WINDOW_Y)
		rslt = ((x + 0.5) / WINDOW_X) * ASPR -
			(((WINDOW_X - WINDOW_Y) / (float)WINDOW_Y) / 2);
	else
		rslt = (x + 0.5) / (float)WINDOW_X;
	return (rslt);
}

float		get_y_point(float y)
{
	float	rslt;

	if (WINDOW_Y > WINDOW_X)
		rslt = ((y + 0.5) / WINDOW_Y) / ASPR -
			(((WINDOW_Y - WINDOW_X) / (float)WINDOW_X) / 2);
	else
		rslt = (y + 0.5) / WINDOW_Y;
	return (rslt);
}

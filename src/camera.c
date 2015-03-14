/* ************************************************************************** */
/*	                                                                   		  */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrosnie <acrosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/31 00:50:58 by acrosnie          #+#    #+#             */
/*   Updated: 2015/02/24 21:11:12 by pgallois         ###   ########.fr       */
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


void init_cam(t_data *d, char **split)
{
	t_camera	*c;
	t_vec 		*look_at;
	t_vec		*diff_btw;

	c = new_camera(NULL, NULL, NULL, NULL);
	c->campos = ft_vec(atof(split[2]), atof(split[3]), atof(split[4]));
	look_at = ft_vec(atof(split[5]), atof(split[6]), atof(split[7]));
	diff_btw = ft_vec(c->campos->x - look_at->x, c->campos->y - look_at->y, c->campos->z - look_at->z);
	c->camdir = normalize(negative(diff_btw));
	c->camright = normalize(crossProduct(ft_vec(0, 1, 0), c->camdir));
	c->camdown = crossProduct(c->camright, c->camdir);
	d->cam2 = c;
}
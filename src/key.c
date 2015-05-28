/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrosnie <acrosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/21 05:30:35 by acrosnie          #+#    #+#             */
/*   Updated: 2015/05/21 05:30:45 by acrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void		reset_cam(t_data *d)
{
	t_vec		*diff_btw;

	diff_btw = ft_vec(d->cam2->campos->x - d->cam2->vise->x,
		d->cam2->campos->y - d->cam2->vise->y,
		d->cam2->campos->z - d->cam2->vise->z);
	d->cam2->camright = normalize(cross_product(ft_vec(0, 1, 0),
		d->cam2->camdir));
	d->cam2->camdown = cross_product(d->cam2->camright, d->cam2->camdir);
}

int			send_key_first(int key, t_data *d)
{
	if (key == 53)
	{
		free_all(d);
		exit(0);
	}
	if (key == 123)
		rotate_vec_axe(d->cam2->camdir, d->cam2->camdown);
	if (key == 124)
		rotate_vec_axe(d->cam2->camdir, negative(d->cam2->camdown));
	if (key == 78)
		d->qrender++;
	if (key == 69)
		d->qrender--;
	if (key == 257)
		assign_value_vec(vector_add(*d->cam2->campos, *d->cam2->camdown), d->cam2->campos);
	if (key == 49)
		assign_value_vec(vector_sub(*d->cam2->campos, *d->cam2->camdown), d->cam2->campos);
	return (0);
}

int			send_key(int key, t_data *d)
{
	send_key_first(key, d);
	if (key == 13)
		rotate_vec_axe(d->cam2->camdir, d->cam2->camright);
	if (key == 1)
		rotate_vec_axe(d->cam2->camdir, negative(d->cam2->camright));
	if (key == 125)
		assign_value_vec(vector_sub(*d->cam2->campos, vector_dot_float(8, *d->cam2->camdir)), d->cam2->campos);
	if (key == 126)
		assign_value_vec(vector_add(*d->cam2->campos, vector_dot_float(8, *d->cam2->camdir)), d->cam2->campos);
	if (d->qrender < 1)
		d->qrender = 1;
	else
	{
		normalize(d->cam2->camdir);
		d->cam2->camright = normalize(cross_product(ft_vec(0, 1, 0),
			d->cam2->camdir));
		d->cam2->camdown = cross_product(d->cam2->camright, d->cam2->camdir);
		display(d);
		expose(d);
	}
	return (0);
}

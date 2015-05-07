/* ************************************************************************** */
/*	                                                                   		  */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrosnie <acrosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/31 00:50:58 by acrosnie          #+#    #+#             */
/*   Updated: 2015/03/31 18:13:39 by pgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

int		expose(t_data *d)
{
	if (d->img)
	put_all_image(d);
	return (0);
}

void		reset_cam(t_data *d)
{
	t_vec		*diff_btw;

	diff_btw = ft_vec(d->cam2->campos->x - d->cam2->vise->x, d->cam2->campos->y - d->cam2->vise->y, d->cam2->campos->z - d->cam2->vise->z);
	//d->cam2->camdir = normalize(negative(diff_btw));
	d->cam2->camright = normalize(crossProduct(ft_vec(0, 1, 0), d->cam2->camdir));
	d->cam2->camdown = crossProduct(d->cam2->camright, d->cam2->camdir);
}

int			send_key(int key, t_data *d)
{
	if (key == 53)
		exit(0);
	if (key == 123)
		rotate_vec_axe(d->cam2->camdir, d->cam2->camdown);
	if (key == 124)
		rotate_vec_axe(d->cam2->camdir, negative(d->cam2->camdown));
	if (key == 78)
		d->qRender++;
	if (key == 69)
		d->qRender--;
	if (key == 257)
	{
		d->cam2->campos = vector_add(d->cam2->campos, d->cam2->camdown);
	//	d->cam2->camdir = vector_add(d->cam2->camdir, d->cam2->camdown);
	}
	if (key == 49)
	{
		d->cam2->campos = vector_sub(d->cam2->campos, d->cam2->camdown);
	//	d->cam2->camdir = vector_sub(d->cam2->camdir, d->cam2->camdown);
	}
	if (key == 13)
		rotate_vec_axe(d->cam2->camdir, d->cam2->camright);
	if (key == 1)
		rotate_vec_axe(d->cam2->camdir, negative(d->cam2->camright));
	if (key == 125)
	{
		d->cam2->campos = vector_sub(d->cam2->campos, vector_dot_float(8, d->cam2->camdir));
	//	d->cam2->camdir = vector_sub(d->cam2->camdir, vector_dot_float(8, d->cam2->camdir));
	}
	if (key == 126)
	{
		d->cam2->campos = vector_add(d->cam2->campos, vector_dot_float(8, d->cam2->camdir));
	//	d->cam2->camdir = vector_add(d->cam2->camdir, vector_dot_float(8, d->cam2->camdir));
	}
	if (d->qRender < 1)
		d->qRender = 1;
	else
	{
		//reset_cam(d);
		normalize(d->cam2->camdir);
		d->cam2->camright = normalize(crossProduct(ft_vec(0, 1, 0), d->cam2->camdir));
		d->cam2->camdown = crossProduct(d->cam2->camright, d->cam2->camdir);
		display(d);
		expose(d);
	}
	printf("Key %d\n", key);
	return (0);
}

void		rtv1(t_data data)
{
	data.n = 0;
	data.qRender = 4;
	data.ptr = mlx_init();
	data.win = mlx_new_window(data.ptr, WINDOW_X, WINDOW_Y, "rtv1");
	init(&data);
	display(&data);
	mlx_expose_hook(data.win, expose, &data);
	mlx_key_hook(data.win, send_key, &data);
	mlx_loop(data.ptr);
}

int		main(int ac, char **av)
{
	t_data	data;

	if (ac > 1)
	{
		data.argv = av;
		if ((data.fd = open(av[1], O_RDONLY)) < 1)
			return (0);
		rtv1(data);
	}
	rtv1(data);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrosnie <acrosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 23:32:02 by acrosnie          #+#    #+#             */
/*   Updated: 2014/02/14 12:00:29 by acrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <mlx.h>
#include "../main.h"

t_new_img	*create_img(t_new_img *img, t_data *data,
						unsigned long color, int *t)
{
	img->color = 0x000000;
	img->size_x = t[0];
	img->size_y = t[1];
	img->pos_x = t[2];
	img->pos_y = t[3];
	if (color)
		img->color = mlx_get_color_value(data->ptr, color);
	img->img = (char *)mlx_new_image(data->ptr, t[0], t[1]);
	img->data = mlx_get_data_addr(img->img, &img->bits, &img->sizeline, &img->endian);
	return (img);
}

void	background(t_data *data, t_new_img *b)
{
    int		t[4];

	t[0] = WINDOW_X;
	t[1] = WINDOW_Y;
	t[2] = t[3] = 0;
	data->img[0] = create_img(b, data, 0, t);
}

void	parse(t_data *d)
{
	char	*line;
	char	**split;
	t_vec	*vec;
	t_vec	*vec2;

	while (get_next_line(d->fd, &line) == 1)
    {
		split = ft_strsplit(line, ',');
		if (split[4] && !ft_strcmp("camera", split[0]))
		{
			d->cam->fov = ft_atoi(split[1]);
			camera(d, ft_atoi(split[2]), ft_atoi(split[3]), ft_atoi(split[4]));
		}
		if (split[5] && !ft_strcmp("sphere", split[0]))
		{
			vec = ft_vec(ft_atoi(split[1]), ft_atoi(split[2]), ft_atoi(split[3]));
			sphere(d, vec, ft_atoi(split[4]), ft_atoi(split[5]));
		}
		if (split[9] && !ft_strcmp("cylinder", split[0]))
		{
			cylinder_start(d, ft_atoi(split[5]), ft_atoi(split[4]));
			vec = ft_vec(ft_atoi(split[1]), ft_atoi(split[2]), ft_atoi(split[3]));
			vec2 = ft_vec(ft_atoi(split[6]), ft_atoi(split[7]), ft_atoi(split[8]));
			cylinder(d, vec, vec2, ft_atoi(split[9]));
		}
	}
}

void	init(t_data *d)
{
	int		i;

	i = -1;
	d->img = ft_memalloc(1000);
	d->vec = ft_memalloc(1000);
	d->objet = ft_memalloc(1000);
	d->cam = ft_memalloc(sizeof(t_cam));
	d->cam->origine = ft_memalloc(sizeof(t_vec));
	d->cam->vise = ft_memalloc(sizeof(t_vec));
	while (++i < 100)
		d->img[i] = ft_memalloc(100);
	background(d, d->img[0]);
	parse(d);
}

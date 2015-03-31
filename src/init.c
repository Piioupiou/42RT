/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrosnie <acrosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 23:32:02 by acrosnie          #+#    #+#             */
/*   Updated: 2015/03/31 19:06:58 by pgallois         ###   ########.fr       */
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
	t_vec	*vec3;

	while (get_next_line(d->fd, &line) == 1)
    {
		split = ft_strsplit(line, ',');
		if (split[7] && !ft_strcmp("camera", split[0]))
		{
			init_cam(d, split);
			//d->cam->fov = ft_atoi(split[1]);
			//camera(d, ft_atoi(split[2]), ft_atoi(split[3]), ft_atoi(split[4]));
		}
		if (split[7] && !ft_strcmp("sphere", split[0]))
		{
			vec = ft_vec(atof(split[1]), atof(split[2]), atof(split[3]));
			sphere(d, vec, ft_atoi(split[4]), createColorRgb(atof(split[5]), atof(split[6]), atof(split[7])));
		}
		if (split[7] && !ft_strcmp("cone", split[0]))
		{
			vec = ft_vec(atof(split[1]), atof(split[2]), atof(split[3]));
			cone(d, vec, atof(split[4]), createColorRgb(atof(split[5]), atof(split[6]), atof(split[7])));
		}
		if (split[9] && !ft_strcmp("cylinder", split[0]))
		{
			cylinder_start(d, atof(split[5]), atof(split[4]));
			vec = ft_vec(atof(split[1]), atof(split[2]), atof(split[3]));
			vec2 = ft_vec(atof(split[6]), atof(split[7]), atof(split[8]));
			cylinder(d, vec, vec2, createColorRgb(atof(split[9]), atof(split[10]), atof(split[11])));
		}
		if (split[12] && !ft_strcmp("plane", split[0]))
		{
			vec = ft_vec(atof(split[1]), atof(split[2]), atof(split[3]));
			vec2 = ft_vec(atof(split[4]), atof(split[5]), atof(split[6]));
			vec3 = ft_vec(atof(split[10]), atof(split[11]), atof(split[12]));
			plane(d, vec, vec2, createColorRgb(atof(split[7]), atof(split[8]), atof(split[9])), vec3);
		}
		if (split[7] && !ft_strcmp("light", split[0]))
		{
			vec = ft_vec(atof(split[1]), atof(split[2]), atof(split[3]));
			light(d, vec, atof(split[4]), createColorRgb(atof(split[5]), atof(split[6]), atof(split[7])));
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

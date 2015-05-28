/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrosnie <acrosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 23:32:02 by acrosnie          #+#    #+#             */
/*   Updated: 2015/05/19 07:02:01 by pgallois         ###   ########.fr       */
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
	img->data = mlx_get_data_addr(img->img, &img->bits,
		&img->sizeline, &img->endian);
	return (img);
}

void		background(t_data *data, t_new_img *b)
{
	int		t[4];

	t[0] = WINDOW_X;
	t[1] = WINDOW_Y;
	t[2] = 0;
	t[3] = 0;
	data->img[0] = create_img(b, data, 0, t);
}

int			parse(t_data *d)
{
	char	*line;
	char	**split;
	int		i;

	i = 0;
	while (get_next_line(d->fd, &line) == 1)
	{
		split = ft_strsplit(line, ',');
		if (split[7] && !ft_strcmp("camera", split[0]))
			init_cam(d, split);
		else if (split[7] && !ft_strcmp("sphere", split[0]))
			create_sphere(d, split);
		else if (split[10] && !ft_strcmp("cone", split[0]))
			create_cone(d, split);
		else if (split[14] && !ft_strcmp("cylinder", split[0]))
			create_cylinder(d, split);
		else if (split[12] && !ft_strcmp("plane", split[0]))
			create_plane(d, split);
		else if (split[7] && !ft_strcmp("light", split[0]))
			create_light(d, split);
		else
			return (0);
		i++;
	}
	return (i);
}

void		init(t_data *d)
{
	int		i;

	i = -1;
	d->img = ft_memalloc(1000);
	d->vec = ft_memalloc(1000);
	d->objet = ft_memalloc(1000);
	d->vec_simple = ft_vec(0, 0, 0);
	d->v1 = ft_vec(0, 0, 0);
	d->v2 = ft_vec(0, 0, 0);
	d->new_start = ft_vec(0, 0, 0);
	d->blinn_dir = ft_vec(0, 0, 0);
	d->dist = ft_vec(0, 0, 0);
	d->lray.dir = ft_vec(0, 0, 0);
	d->lray.start = ft_vec(0, 0, 0);
	d->ray = ft_memalloc(sizeof(t_ray) + 1);
	while (++i < 100)
		d->img[i] = ft_memalloc(100);
	background(d, d->img[0]);
	if (parse(d) == 0)
	{
		free(d->img);
		free(d->vec);
		free(d->objet);
		ft_putstr("Bad map\n");
		exit(0);
	}
}

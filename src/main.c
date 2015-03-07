/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrosnie <acrosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/31 00:50:58 by acrosnie          #+#    #+#             */
/*   Updated: 2015/02/27 20:37:57 by pgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

int		expose(t_data *d)
{
	if (d->img)
	put_all_image(d);
	return (0);
}

int			send_key(int key)
{
	if (key == 65307)
		exit(0);
	return (0);
}

void		rtv1(t_data data)
{
	data.n = 0;
	data.ptr = mlx_init();
	data.win = mlx_new_window(data.ptr, WINDOW_X, WINDOW_Y, "rtv1");
	init(&data);
	display(&data);
	mlx_key_hook(data.win, send_key, "");
	mlx_expose_hook(data.win, expose, &data);
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

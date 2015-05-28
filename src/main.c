/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrosnie <acrosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/21 05:27:24 by acrosnie          #+#    #+#             */
/*   Updated: 2015/05/21 05:27:26 by acrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

int		expose(t_data *d)
{
	if (d->img)
		put_all_image(d);
	return (0);
}

void	optionNormal(t_data *d)
{
	t_option	*o;

	o = (t_option*)malloc(sizeof(t_option));
	o->level_max = 10;
	o->coef = 0.25f;
	o->activate_gama = 1;
	o->activate_exposure = 1;
	o->activate_shadow = 1;
	o->activate_light = 1;
	o->activate_reflection = 1;
	o->activate_antialiasing = 8;
	d->option = o;
}

void	rtv1(t_data data)
{
	optionNormal(&data);
	data.n = 0;
	data.qrender = 1;
	data.ptr = mlx_init();
	data.win = mlx_new_window(data.ptr, WINDOW_X, WINDOW_Y, "rtv1");
	init(&data);
	clear(&data);
	display(&data);
	mlx_expose_hook(data.win, expose, &data);
	mlx_key_hook(data.win, send_key, &data);
	mlx_loop(data.ptr);
}

void	ft_free_double(void **ap)
{
	int i;

	if (ap && *ap != NULL)
	{
		i = -1;
		while (ap[++i])
		{
			free(ap[i]);
		}
		free(ap);
	}
}

void	free_all(t_data *d)
{
	free(d->ptr);
	free(d->win);
	ft_free_double((void **)d->img);
	ft_free_double((void **)d->vec);
	ft_free_double((void **)d->objet);
	free(d->color);
	free(d->tmpcolor);
	free(d->cam2);
	free(d->ray);
}

void	interface(t_data *d)
{
	ft_putstr("Welcome to the interface bitch!\n");

}

int		main(int ac, char **av)
{
	t_data	data;

	if (ac > 1)
	{
		data.argv = av;
		if (!ft_strcmp(av[1], "interface"))
		{
			interface(&data);
		}
		else
		{
			if ((data.fd = open(av[1], O_RDONLY)) < 1)
			{
				ft_putstr("Error\n");
				return (0);
			}
			rtv1(data);
		}
	}
	else
		ft_putstr("Error\n");
	return (0);
}

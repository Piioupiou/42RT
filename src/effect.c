/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   effect.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrosnie <acrosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/21 05:50:51 by acrosnie          #+#    #+#             */
/*   Updated: 2015/05/29 15:30:18 by pgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	exposure(t_color *color)
{
	float	exposure;

	exposure = -1.00f;
	color->b = 1.0f - expf(color->b * exposure);
	color->r = 1.0f - expf(color->r * exposure);
	color->g = 1.0f - expf(color->g * exposure);
}

void	option_normal(t_data *d)
{
	t_option	*o;

	o = (t_option*)malloc(sizeof(t_option));
	o->level_max = 10;
	o->coef = 0.25f;
	o->activate_gama = 1;
	o->activate_exposure = 1;
	o->activate_shadow = 1;
	o->activate_light = 1;
	o->activate_reflection = 0;
	o->activate_antialiasing = 1;
	d->option = o;
}

void	interface(t_data *d)
{
	ft_putstr("Welcome to the interface bitch!\n");
}

void	gama(t_color *color)
{
	float	invgamma;

	invgamma = 0.45f;
	color->b = powf(color->b, invgamma);
	color->r = powf(color->r, invgamma);
	color->g = powf(color->g, invgamma);
}

void	clear(t_data *d)
{
	int	x;
	int	y;

	y = 0;
	d->color = new_color_rgb(0, 0, 0);
	while (++y < WINDOW_Y)
	{
		x = 0;
		while (++x < WINDOW_X)
		{
			pixel_put(d->img[0], x, y, d->color);
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   effect.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrosnie <acrosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/21 05:50:51 by acrosnie          #+#    #+#             */
/*   Updated: 2015/05/21 05:51:04 by acrosnie         ###   ########.fr       */
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

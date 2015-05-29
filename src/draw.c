/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgallois <pgallois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/03 15:39:11 by pgallois          #+#    #+#             */
/*   Updated: 2015/05/29 14:36:29 by pgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

float	ft_min(float a, float b)
{
	if (a < b)
		return (a);
	else if (b < a)
		return (b);
	return (a);
}

float	ft_max(float a, float b)
{
	if (a > b)
		return (a);
	else if (b > a)
		return (b);
	return (a);
}

void	pixel_put(t_new_img *img, int x, int y, t_color *color)
{
	img->data[y * img->sizeline + x * img->bits / 8] =
		(unsigned char)ft_min(color->b * 255.0f, 255.0f);
	img->data[y * img->sizeline + x * img->bits / 8 + 1] =
			(unsigned char)ft_min(color->g * 255.0f, 255.0f);
	img->data[y * img->sizeline + x * img->bits / 8 + 2] =
			(unsigned char)ft_min(color->r * 255.0f, 255.0f);
}

t_color	*new_color_rgb(float r, float g, float b)
{
	t_color	*c;

	c = ft_memalloc(sizeof(t_color) + 1);
	c->b = b;
	c->g = g;
	c->r = r;
	return (c);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrosnie <acrosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/03 15:39:11 by acrosnie          #+#    #+#             */
/*   Updated: 2014/02/03 15:39:12 by acrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

float ft_min(float a, float b)
{
	if (a < b)
		return (a);
	else if(b < a)
		return (b);
	return (a);
}

void	pixel_put(t_new_img *img, int x, int y, t_color *color)
{
	img->data[y * img->sizeline + x * img->bits / 8] = (unsigned char)ft_min(color->b * 255.0f, 255.0f);
	img->data[y * img->sizeline + x * img->bits / 8 + 1] = (unsigned char)ft_min(color->g * 255.0f, 255.0f);
	img->data[y * img->sizeline + x * img->bits / 8 + 2] = (unsigned char)ft_min(color->r * 255.0f, 255.0f);
}

t_color *convertColor(unsigned long color)
{
	t_color *c;

	c = ft_memalloc(sizeof(t_color) + 1);
	c->b = (color & 0xFF0000) >> 16;
	c->g = (color & 0xFF00) >> 8;
	c->r = (color & 0xFF);
	//printf("%f\n", c->g);
	return (c);
}

t_color *createColorRgb(float r, float g, float b)
{
	t_color *c;

	c = ft_memalloc(sizeof(t_color) + 1);
	c->b = b;
	c->g = g;
	c->r = r;
	return (c);
}
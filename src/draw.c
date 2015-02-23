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

void	pixel_put(t_new_img *img, int x, int y, unsigned long color)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	b = (color & 0xFF0000) >> 16;
	g = (color & 0xFF00) >> 8;
	r = (color & 0xFF);
	img->data[y * img->sizeline + x * img->bits / 8] = b;
	img->data[y * img->sizeline + x * img->bits / 8 + 1] = g;
	img->data[y * img->sizeline + x * img->bits / 8 + 2] = r;
}

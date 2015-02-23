/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrosnie <acrosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 23:39:57 by acrosnie          #+#    #+#             */
/*   Updated: 2014/02/03 15:01:01 by acrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"
#include <mlx.h>

void	img_to_img(t_new_img *s, t_new_img *d)
{
	int		ps;
	int		pd;
	int		t[2];

	t[0] = -1;
	while (++t[0] < s->size_x)
	{
		t[1] = -1;
		while (++t[1] < s->size_y)
		{
			ps = (t[1] * s->sizeline) + (t[0] * (s->bits >> 3));
			pd = ((t[1] + s->pos_y) * d->sizeline) +
				((t[0] + s->pos_x) * (d->bits >> 3));
			if (!(s->data[ps] == (char)0xFF &&
				  s->data[ps + 1] == (char)0 && s->data[ps + 2] == (char)0xFF))
			{
				d->data[pd] = s->data[ps];
				d->data[pd + 1] = s->data[ps + 1];
				d->data[pd + 2] = s->data[ps + 2];
			}
		}
	}
}

void	put_all_image(t_data *data)
{
	mlx_put_image_to_window(data->ptr, data->win, data->img[0]->img,
							data->img[0]->pos_x, data->img[0]->pos_y);
}

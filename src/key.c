/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgallois <pgallois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/21 05:30:35 by pgallois          #+#    #+#             */
/*   Updated: 2015/05/29 14:23:40 by pgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void		reset_cam(t_data *d)
{
	t_vec		*diff_btw;

	diff_btw = ft_vec(d->cam2->campos->x - d->cam2->vise->x,
		d->cam2->campos->y - d->cam2->vise->y,
		d->cam2->campos->z - d->cam2->vise->z);
	d->cam2->camright = normalize(cross_product(ft_vec(0, 1, 0),
		d->cam2->camdir));
	d->cam2->camdown = cross_product(d->cam2->camright, d->cam2->camdir);
}

int			send_key_first(int key, t_data *d)
{
	if (key == 53)
	{
		free_all(d);
		exit(0);
	}
	return (0);
}

int			send_key(int key, t_data *d)
{
	send_key_first(key, d);
	return (0);
}

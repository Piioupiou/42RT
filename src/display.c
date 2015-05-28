/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrosnie <acrosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/21 06:33:15 by acrosnie          #+#    #+#             */
/*   Updated: 2015/05/21 06:33:15 by acrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"
#include <stdio.h>
#include <time.h>

int		col_object(t_data *d, float *t, t_ray *ray)
{
	int	k;
	int	current;

	current = -1;
	k = -1;
	while (d->objet[++k])
	{
		if (d->objet[k]->type == 1 && hit_sphere(ray, d->objet[k], t) == 1)
			current = k;
		else if (d->objet[k]->type == 2 &&
			hit_cylinder(d->objet[k], ray, t) == 1)
			current = k;
		else if (d->objet[k]->type == 3 && hit_plane(d->objet[k], ray, t) == 1)
			current = k;
		else if (d->objet[k]->type == 4 && hit_cone(d->objet[k], ray, t) == 1)
			current = k;
	}
	d->current = current;
	return (current);
}

t_ray	*get_ray(t_data *d, float x, float y)
{
	assign_value_vec(vector_dot_float(x - 0.5, *d->cam2->camright), d->v1);
	assign_value_vec(vector_dot_float(y - 0.5, *d->cam2->camdown), d->v2);
	assign_value_vec(vector_add(*d->v1, *d->v2), d->v1);
	assign_value_vec(vector_add(*d->cam2->camdir, *d->v1), d->v1);
	normalize(d->v1);
	d->ray->start = d->cam2->campos;
	d->ray->dir = d->v1;
	return (d->ray);
}

void	raytracing(t_data *d, float fragmentx, float fragmenty)
{
	float	t;
	t_vec	*n;
	int		current;

	d->coef = d->option->coef;
	d->ray = get_ray(d, get_x_point(fragmentx), get_y_point(fragmenty));

	d->option->level = 0;
	while ((d->coef > 0.0f) && (d->option->level < d->option->level_max))
	{
		t = 20000.0f;
		current = col_object(d, &t, d->ray);
		if (current == -1)
			break ;
		assign_value_vec(vector_add(*d->ray->start, vector_dot_float(t, *d->ray->dir)), d->new_start);
		if ((n = calcul_light_shadow(d, &t, d->new_start, current)) == NULL)
			break ;
		calcul_next_iteration(d, d->ray, n, d->new_start);
		if (!d->option->activate_reflection)
			break ;
	}
}

void colorZero(t_color *c)
{
	c->r = 0;
	c->g = 0;
	c->b = 0;
}

void	raytracing_aliasing(t_data *d, int x, int y)
{
	float	fragmentx;
	float	fragmenty;
	float a = 1.0f / d->option->activate_antialiasing; // 0.5f // 1.0f
	float p = 1 / pow(d->option->activate_antialiasing, 2); //0.25f // 0.5f
	colorZero(d->tmp2clr);
	fragmentx = x - 0.5f; //x=1; 0.5f
	while (fragmentx < x + 0.5f)
	{
		fragmenty = y - 0.5f;
		while (fragmenty < y + 0.5f)
		{
			colorZero(d->color);
			raytracing(d, fragmentx, fragmenty);
			if (d->option->activate_exposure)
				exposure(d->color);
			d->tmp2clr->r = d->tmp2clr->r + (d->color->r * p);
			d->tmp2clr->g = d->tmp2clr->g + (d->color->g * p);
			d->tmp2clr->b = d->tmp2clr->b + (d->color->b * p);
			// if (d->tmp2clr->r > 0)
			// 	printf("%f\n", d->tmp2clr->r);
			fragmenty += a;
		}
		fragmentx += a;
	}
	//d->color = d->tmp2clr;
	if (d->option->activate_gama)
		gama(d->tmp2clr);
	pixel_put(d->img[0], x, y, d->tmp2clr);
}

void	display(t_data *d)
{
	clock_t t;
    t = clock();
	int		x;
	int		y;

	clear(d);
	d->tmp2clr = new_color_rgb(0, 0, 0);
	d->color = new_color_rgb(0, 0, 0);
	d->vec_simple = ft_vec(0, 0, 0);
	y = 0;
	while (y < WINDOW_Y)
	{
		x = 0;
		while (x < WINDOW_X)
		{
			// pthread_t ray;
			// ret = pthread_create(ray, NULL, raytracing_aliasing, datas);
			// pthread_mutex_lock(&mutex);
			// pthread_mutex_t		mutex;
			raytracing_aliasing(d, x, y);
			x += d->qrender;
		}
		y += d->qrender;
	}
  	t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
 
    printf("fun() took %f seconds to execute \n", time_taken);
	ft_putstr("Done !\n");
}

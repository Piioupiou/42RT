/* ************************************************************************** */
/*	                                                                   */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrosnie <acrosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/31 00:50:58 by acrosnie          #+#    #+#             */
/*   Updated: 2014/02/14 12:07:35 by acrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <mlx.h>
#include "../main.h"
#include <math.h>

float	ft_rad(float angle)
{
	return (M_PI * (angle) / 180);
}

float	square(float nbr)
{
	nbr = nbr * nbr;
	return (nbr);
}

t_ray		*getfoundray(float x1, float x2, float a, float b, float c, t_ray *ray)
{
	t_ray	*res;
	double	truex;

	truex = x1;
	if (x1 > x2)
		truex = x2;
	res = ft_memalloc(sizeof(t_ray));
	res->o = ft_memalloc(sizeof(t_vec));
	res->d = ft_memalloc(sizeof(t_vec));
	res->o->x = 0;
	res->o->y = 0;
	res->o->z = 0;
	res->d->x = ray->o->x + (truex * a);
	res->d->y = ray->o->y + (truex * b);
	res->d->z = ray->o->z + (truex * c);
	return (res);
}

int			checkfoundray(t_ray *ray, t_objet *cylinder)
{
	double tmp;
	double tmp2;

	tmp = square(0 - ray->d->x) + square(cylinder->h - ray->d->y) + square(0 - ray->d->z);
	tmp2 = square(cylinder->radius) + square(cylinder->h);
	if (tmp < tmp2)
		return (tmp);
	return (0);
}

int hitSphere(t_ray *r, t_objet *s, float *t)
{
   // intersection rayon/sphere
	t_vec *dist = vector_sub(s->ori, r->start); 
  	float B = vector_dot(r->dir, dist);
  	float D = B * B - vector_dot(dist, dist) + s->radius * s->radius; 
  	if (D < 0.0f) 
  		return (0); 
   float t0 = B - sqrtf(D); 
   float t1 = B + sqrtf(D);
   int retvalue = 0;  
   if ((t0 > 0.1f) && (t0 < *t)) 
   {
     *t = t0;
     retvalue = 1; 
   } 
   if ((t1 > 0.1f) && (t1 < *t)) 
   {
     *t = t1; 
     retvalue = 1; 
   }
  return retvalue;
}

void display2(t_data *d)
{
	int		x;
	int		y;
	t_color *color;

	t_ray	ray;
	t_ray 	lightRay;
	ray.start = ft_memalloc(sizeof(t_vec));
	ray.dir = ft_memalloc(sizeof(t_vec));
	lightRay.start = ft_memalloc(sizeof(t_vec));
	lightRay.dir = ft_memalloc(sizeof(t_vec));
	for (y = 0; y < WINDOW_Y; y++)
	{
		for (x = 0; x < WINDOW_X; x++)
		{
			float coef = 1.0f;
			int level = 0;
			color = createColorRgb(0, 0, 0);
			ray.start = ft_vec((float)x, (float)y, (float)-20.0f);
			ray.dir = ft_vec(0.0, 0.0, 1.0);
			while ((coef > 0) && (level < 10))
			{
				float t = 20000.0f;
				int currentSphere = -1;
				int k = -1;
				while (d->objet[++k])
				{
					if (d->objet[k]->type == 1 && hitSphere(&ray, d->objet[k], &t) == 1)
					{
						currentSphere = k;
						//color = d->objet[currentSphere]->color;
					}
				}
				if (currentSphere == -1)
					break;
				t_vec *newStart = vector_add(ray.start, vector_dot_float(t, ray.dir));
		       // la normale au point d'intersection 
				t_vec *n = vector_sub(newStart, d->objet[currentSphere]->ori);
				float temp = vector_dot(n, n);
				if (temp == 0.0f) 
					break ;
				temp = 1.0f / sqrtf(temp); 
				n = vector_dot_float(temp, n);
				// calcul de la valeur d'éclairement au point 
				int j = -1;
				while (d->objet[++j])
				{
					if (d->objet[j]->type == 10)
					{
						t_vec *dist = vector_sub(d->objet[j]->ori, newStart);
						if (vector_dot(n, dist) <= 0.0f)
							continue ;
						float t = sqrtf(vector_dot(dist, dist));
						if (t <= 0.0f)
							continue ;
						lightRay.start = newStart;
						lightRay.dir = vector_dot_float((1 / t), dist);
						// calcul des ombres 
						int inShadow = 0;
						int i = -1;
						while (d->objet[++i])
						{
							if (d->objet[i]->type == 1 && hitSphere(&lightRay, d->objet[i], &t))
							{
						 		inShadow = 1;
						 		break ;
							}
						}
						if (inShadow == 0)
						{
							// lambert
							float lambert = vector_dot(lightRay.dir, n) * coef;
							//float lambert = 1.0f;
							color->r += lambert * d->objet[j]->color->r * d->objet[currentSphere]->color->r;
							color->g += lambert * d->objet[j]->color->g * d->objet[currentSphere]->color->g;
							color->b += lambert * d->objet[j]->color->b * d->objet[currentSphere]->color->b;
						}
					}
				}
				// on itére sur la prochaine reflexion
				coef *= 0.5f;
				float reflet = 2.0f * vector_dot(ray.dir, n);
				ray.start = newStart;
				ray.dir = vector_sub(ray.dir, vector_dot_float(reflet, n));
				level++;
			}
			//printf("%d && %d\n", y, x);
			pixel_put(d->img[0], x, y, color);
		}
	}
	printf("done\n");
}

void	display(t_data *d)
{
	(void)d;
	// int		x;
	// int		y;
	// t_vec	b;
	// t_vec	dir;
	// t_ray	ray;

	// ray.o = ft_memalloc(sizeof(t_vec));
	// ray.d = ft_memalloc(sizeof(t_vec));
	// y = -1;
	// while (++y < WINDOW_Y)
	// {
	// 	x = -1;
	// 	while (++x < WINDOW_X)
	// 	{
	// 		b.x = x - (WINDOW_X / 2);
	// 		b.y = y - (WINDOW_Y / 2);
	// 		b.z = d->cam->f;
	// 		dir.x = b.x - d->cam->origine->x;
	// 		dir.y = b.y - d->cam->origine->y;
	// 		dir.z = b.z - d->cam->origine->z;
	// 		ray.o->x = d->cam->origine->x;
	// 		ray.o->y = d->cam->origine->y;
	// 		ray.o->z = d->cam->origine->z;
	// 		ray.d->x = x;
	// 		ray.d->y = y;
	// 		ray.d->z = 1.0f;
	// 		int k = -1;
	// 		double f = 0;
	// 		//double f2 = 0;
	// 		while (d->objet[++k])
	// 		{
	// 			if (d->objet[k]->type == 1)
	// 				f = findinter_sphere(&ray, d->objet[k]);
	// 			// if (d->objet[k]->type == 2)
 //    //                 f = findinter_cylinder(&ray, d->objet[k]);
	// 			if (f)
	// 			{
	// 				// if (!f2 || f > f2)
	// 				// {
	// 				// 	f2 = f;
	// 					pixel_put(d->img[0], x, y, d->objet[k]->color);
	// 				//}
	// 			}
	// 		}
	// 	}
	// }
}

int		expose(t_data *d)
{
	if (d->img)
	put_all_image(d);
	return (0);
}

void		rtv1(t_data data)
{
	data.n = 0;
	data.ptr = mlx_init();
	data.win = mlx_new_window(data.ptr, WINDOW_X, WINDOW_Y, "rtv1");
	init(&data);
	display2(&data);
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

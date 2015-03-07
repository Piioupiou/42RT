/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 23:34:58 by pgallois          #+#    #+#             */
/*   Updated: 2015/02/28 06:10:42 by pgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

int collidObject(t_data *d, float *t, t_ray *ray)
{
	int k;
	int current;

	current = -1;
	k = -1;
	while (d->objet[++k])
	{
		if (d->objet[k]->type == 1 && hitSphere(ray, d->objet[k], t) == 1)
		{
			current = k;
			//ft_putendl("HIT !!");
		}
		//else if(type == 2 1& hitPlane(ray, d->objet[k], t) == 1)	// plan
		//current = k
	}
	return (current);
}

void lambertFunctionColor(t_data *d, int j, int currentObject, t_ray lightRay, t_vec *n)
{
	float lambert;

	lambert = vector_dot(lightRay.dir, n) * d->coef;
	d->color->r += (lambert * d->objet[j]->color->r
			* d->objet[currentObject]->color->r)
		* d->objet[j]->intensity;
	d->color->g += (lambert * d->objet[j]->color->g
			* d->objet[currentObject]->color->g)
		* d->objet[j]->intensity;
	d->color->b += (lambert * d->objet[j]->color->b
			* d->objet[currentObject]->color->b)
		* d->objet[j]->intensity;
}

t_vec *calcul_light_shadow(t_data *d, float *t, t_vec *newStart, int currentObject)
{
	int j = -1;
	t_ray 	lightRay;
	t_vec *n;

	// la normale au point d'intersection
	if ((n = normalObject(d, currentObject, newStart)) == NULL)
		return NULL;
	while (d->objet[++j])
	{
		if (d->objet[j]->type == 10)
		{
			t_vec *dist = vector_sub(d->objet[j]->ori, newStart);
			if (vector_dot(n, dist) <= 0.0f ||
					((*t = sqrtf(vector_dot(dist, dist))) <= 0.0f))
				continue ;
			lightRay.start = newStart;
			lightRay.dir = vector_dot_float((1 / *t), dist);
			// calcul des ombres 
			if (collidObject(d, t, &lightRay) == -1)
				lambertFunctionColor(d, j, currentObject, lightRay, n);
		}
	}
	return (n);
}

t_vec *normalObject(t_data *d, int currentObject, t_vec *newStart)
{
	t_vec *n = vector_sub(newStart, d->objet[currentObject]->ori);
	float temp = vector_dot(n, n);
	if (temp == 0.0f)
		return (NULL);
	temp = 1.0f / sqrtf(temp); 
	n = vector_dot_float(temp, n);
	return (n);
}

void calcul_next_iteration(t_data *d, t_ray *ray, t_vec *n, t_vec *newStart, int *level)
{
	float reflet;

	reflet = 2.0f * vector_dot(ray->dir, n);
	d->coef *= 0.5f;
	ray->start = newStart;
	ray->dir = vector_sub(ray->dir, vector_dot_float(reflet, n));
	level++;
}

t_ray	setray(t_data *d, t_ray *ray, int x, int y)
{
	t_vec	*tmp1;
	t_vec	*tmp2;
	t_vec	*tmp3;
	t_vec	*tmp4;
	ray->start = d->cam->origine;
	tmp1 = vector_dot_float(d->cam->xIndent * (float)x, d->cam->vecRight);
	tmp2 = vector_dot_float(d->cam->yIndent * (float)y, d->cam->vecUp);
	tmp3 = vector_sub(tmp1, tmp2);
	tmp4 = vector_add(d->cam->vecUpLeft, tmp3);
	ray->dir = vector_sub(tmp4, d->cam->origine);
	//ray->dir = vector_sub(vector_add(d->cam->vecUpLeft, vector_sub(vector_dot_float((d->cam->xIndent * (float)x), d->cam->vecRight), vector_dot_float((d->cam->yIndent * (float)y), d->cam->vecUp))), d->cam->origine);
	ray->dir = normalize(ray->dir);
	return (*ray);
}

void display(t_data *d)
{
	int		x;
	int		y;
	int currentObject;
	t_vec *n;

	t_ray	ray;
	for (y = 0; y < WINDOW_Y; y++)
	{
		for (x = 0; x < WINDOW_X; x++)
		{
			d->coef = 1.0f;
			int level = 0;
			d->color = createColorRgb(0, 0, 0);
			ray = setray(d, &ray, x, y);
			//ft_putstr("HG : ");
			//printVec(d->cam->vecUpLeft);
			//ft_putstr("rayDir : ");
			//printVec(ray.dir);
			//ft_putstr("raystart : ");
			//printVec(ray.start);
			//ray.start = ft_vec((float)x + d->cam->origine->x, (float)y + d->cam->origine->y, (float)-1000.0f);
			//ray.dir = ft_vec(0.0, 0.0, 1.0f);
			while ((d->coef > 0) && (level < 10))
			{
				// ray length
				float t = 1000000.0f;
				//collider object
				currentObject = collidObject(d, &t, &ray);
				if (currentObject == -1)
					break;
			pixel_put(d->img[0], x, y, d->objet[1]->color);
			break;	
			t_vec *newStart = vector_add(ray.start, vector_dot_float(t, ray.dir));
				// calcul de la valeur d'éclairement au point 
				if ((n = calcul_light_shadow(d, &t, newStart, currentObject)) == NULL)
					break ;
				// on itére sur la prochaine reflexion
				calcul_next_iteration(d, &ray, n, newStart, &level);
			}
		}
	}
	printf("xIndent : %f, yIndent : %f", d->cam->xIndent, d->cam->yIndent);
	printf("done\n");
}

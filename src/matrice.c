/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/30 17:43:36 by pgallois          #+#    #+#             */
/*   Updated: 2015/03/31 17:48:35 by pgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

/*
 *		 ( 1,   0   ,    0    )
 *	Rx = ( 0, cos(a), -sin(a) )
 *		 ( 0, sin(a), cos(a)  )
 */
/*
   float Rx[3][3];
   Rx[0][0] = 1.0f;
   Rx[0][1] = 0.0f;
   Rx[0][2] = 0.0f;
   Rx[1][0] = 0.0f;
   Rx[1][1] = cos(alpha);
   Rx[1][2] = -sin(alpha);
   Rx[2][0] = 0.0f;
   Rx[2][1] = sin(alpha);
   Rx[2][2] = cos(alpha);
   */

void	rotate_vec_axe(t_vec *v, t_vec *axe)
{
	rotate_x(&v->x, &v->y, &v->z, axe->x);
	rotate_y(&v->x, &v->y, &v->z, axe->y);
	rotate_z(&v->x, &v->y, &v->z, axe->z);
}

void	rotate_x(float *x, float *y, float *z, float alpha)
{
	float cosin, sinus, nvy , nvz;

	cosin = cos((alpha * M_PI) / 180);
	sinus = sin((alpha * M_PI) / 180);
	nvy = (*y * cosin) - (*z * (sinus));
	nvz = (*y * sinus) + (*z * cosin);
	*y = nvy;
	*z = nvz;
	return ;
}

void	rotate_y(float *x, float *y, float *z, float alpha)
{
	float cosin, sinus, nvx , nvz;

	cosin = cos((alpha * M_PI) / 180);
	sinus = sin((alpha * M_PI) / 180);
	nvx = (*x * cosin) + (*z * sinus);
	nvz = (*x * (-sinus)) + (*z * cosin);
	*z = nvz;
	*x = nvx;
	return ;
}

void	rotate_z(float *x, float *y, float *z, float alpha)
{
	float cosin, sinus, nvy , nvx;

	cosin = cos((alpha * M_PI) / 180);
	sinus = sin((alpha * M_PI) / 180);
	nvx = (*x * cosin) + (*y * (-sinus));
	nvy = (*x * sinus) + (*y * cosin);
	*x = nvx;
	*y = nvy;
	return ;
}

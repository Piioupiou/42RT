/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrosnie <acrosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/06 20:18:32 by acrosnie          #+#    #+#             */
/*   Updated: 2015/03/07 17:38:25 by pgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"
#include <stdlib.h>

int hitSphere(t_ray *r, t_objet *s, float *t)
{
	//float tloin;
	float OK,CK2;
	//t_vec	*intersect,*intersect_loin;
	//t_vec	*tmpNormal;
	t_vec	*OC;
	OC = vector_sub(s->ori, r->start);

	OK = vector_dot(OC, r->dir);
	CK2 = GetSquareLength(OC) - OK*OK;
	printf("OK = %f, CK2 = %f\n", OK, CK2);
	if( (0< CK2) && CK2 < (s->radius * s->radius) )
	{
		*t = getMagnitude(r->dir) * (OK - (float)sqrt((s->radius*s->radius) - CK2));

		if( *t<0.00001f) return 0;
		//intersect = _Rayon.Origine + CCoord3d((_Rayon.VectDir.x)*t,(_Rayon.VectDir.y)*t,(_Rayon.VectDir.z)*t);

		//tmpNormal = CVect3d(Centre,intersect);

		return 1;
	}
	else
		return 0;

	/*	float b, c;
		float delta;
		float t1, t2;

		t_vec *rayOrg;
		rayOrg = vector_sub(r->start, s->ori);// ray in space of the sphere

		b = vector_dot(rayOrg, r->dir);
		c = GetSquareLength(rayOrg) - (s->radius * s->radius);

		delta = ((b*b) - c);
		printf("b = %f, c = %f, delta = %f\n", b, c, delta);
		if (delta<0.0f)
		return 0; // pas d'intersection

		if (delta!=0)
		{
		delta = sqrtf(delta);
		t1 = (-b + delta); 
		t2 = (-b - delta); 

		if (t1<t2) 
	 *t = t1;
	 else
	 *t = t2;
	 }

	 else 
	 *t = (-b);
	//	printf("t = %f\n", *t);
	return 1;
	*/
	// intersection rayon/sphere
	/*	t_vec *dist = vector_sub(s->ori, r->start); 
		float B = vector_dot(r->dir, dist);
		float D = B * B - vector_dot(dist, dist) + s->radius * s->radius; 
		if (D < 0.0f) 
		return (0); 
		float t0 = B - sqrtf(D); 
		float t1 = B + sqrtf(D);
		int retvalue = 0;  
		if ((t0 > 0.00001f) && (t0 < *t)) 
		{
	 *t = t0;
	 retvalue = 1; 
	 } 
	 if ((t1 > 0.00001f) && (t1 < *t)) 
	 {
	 *t = t1; 
	 retvalue = 1; 
	 }
	 return retvalue;*/
}

int		findinter_cylinder(t_ray *fray, t_objet *cylinder)
{
	(void) cylinder;
	(void) fray;
	return (0);
}

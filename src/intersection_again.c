/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_again.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrosnie <acrosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/21 08:57:42 by acrosnie          #+#    #+#             */
/*   Updated: 2015/05/21 08:57:43 by acrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

int		hit_cylinder2(float *tab, t_vec **vect, t_objet *p, float *t)
{
	tab[0] = tab[3] * tab[10] * tab[10] + tab[4] *
		tab[11] * tab[11] + tab[5] * tab[12] * tab[12];
	tab[1] = 2 * tab[3] * tab[10] * tab[13] + 2 * tab[4] *
		tab[11] * tab[14] + 2 * tab[5] * tab[12] * tab[15];
	tab[2] = tab[3] * tab[13] * tab[13] + tab[4] * tab[14]
		* tab[14] + tab[5] * tab[15] * tab[15] - p->radius;
	if (tab[0] == 0)
		tab[9] = -(tab[2] / tab[1]);
	else
	{
		if ((tab[6] = tab[1] * tab[1] - 4 * tab[0] * tab[2]) < 0)
			return (0);
		tab[7] = (-tab[1] - sqrt(tab[6])) / (2 * tab[0]);
		tab[8] = (-tab[1] + sqrt(tab[6])) / (2 * tab[0]);
		if (tab[7] < 0 && tab[8] < 0)
			return (0);
		if (tab[8] < tab[7])
			tab[9] = tab[8];
		else
			tab[9] = tab[7];
	}
	if (tab[9] < 1)
		return (0);
	return (normal_cylindre(tab, vect, p, t));
}

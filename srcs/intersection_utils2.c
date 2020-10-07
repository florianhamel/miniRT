/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_utils2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianhamel <florianhamel@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 12:06:54 by florianhame       #+#    #+#             */
/*   Updated: 2020/06/24 12:10:43 by florianhame      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	cy_fill_tab(t_vec tab[3], t_cy *cy, t_vec cl)
{
	tab[0].x = cy->vec_x;
	tab[0].y = cy->vec_y;
	tab[0].z = cy->vec_z;
	tab[1].x = cl.x;
	tab[1].y = cl.y;
	tab[1].z = cl.z;
	tab[2].x = cy->x;
	tab[2].y = cy->y;
	tab[2].z = cy->z;
}

double	cy_roots(t_vec tab[3], t_vec ray, t_cy *cy, t_vec cl)
{
	double	a;
	double	b;
	double	c;
	double	delta;
	t_root	t;

	a = dot_p(cross_p(ray, tab[0]), cross_p(ray, tab[0]));
	b = 2 * (dot_p(cross_p(ray, tab[0]), cross_p(tab[1], tab[0])) -
	dot_p(cross_p(ray, tab[0]), cross_p(tab[2], tab[0])));
	c = dot_p(cross_p(tab[2], tab[0]), cross_p(tab[2], tab[0])) +
	dot_p(cross_p(tab[1], tab[0]), cross_p(tab[1], tab[0])) -
	2 * dot_p(cross_p(tab[1], tab[0]), cross_p(tab[2], tab[0])) - pow((cy->diam / 2), 2);
	delta = pow(b, 2) - (4 * a * c);
	if (delta < 0)
		return (-1);
	if (delta == 0 && (-b / (2 * a)) > 0)
		return (-b / (2 * a));
	t.t1 = fmin((-b - sqrt(delta)) / (2 * a), (-b + sqrt(delta)) / (2 * a));
	t.t2 = fmax((-b - sqrt(delta)) / (2 * a), (-b + sqrt(delta)) / (2 * a));
	return (cy_best_root(t, cy, cl, ray));
}

double	cy_best_root(t_root t, t_cy *cy, t_vec cl, t_vec ray)
{
	t_vec	p;
	double	po_sqr;

	po_sqr = 0;
	p.x = 0;
	p.y = 0;
	p.z = 0;
	if (t.t1 > 0)
	{
		p.x = cl.x + (t.t1 * ray.x);
		p.y = cl.y + (t.t1 * ray.y);
		p.z = cl.z + (t.t1 * ray.z);
		po_sqr = pow(p.x - cy->x, 2) + pow(p.y - cy->y, 2) + pow(p.z - cy->z, 2);
		if (sqrt(fmax(0, po_sqr - pow(cy->diam / 2, 2))) <= cy->height / 2)
			return (t.t1);
	}
	if (t.t2 > 0)
	{
		p.x = cl.x + (t.t2 * ray.x);
		p.y = cl.y + (t.t2 * ray.y);
		p.z = cl.z + (t.t2 * ray.z);
		po_sqr = pow(p.x - cy->x, 2) + pow(p.y - cy->y, 2) + pow(p.z - cy->z, 2);
		if (sqrt(fmax(0, po_sqr - pow(cy->diam / 2, 2))) <= cy->height / 2)
			return (t.t2);
	}
	return (-1);
}
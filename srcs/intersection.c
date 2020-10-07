/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianhamel <florianhamel@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 16:20:25 by florianhame       #+#    #+#             */
/*   Updated: 2020/06/24 12:11:18 by florianhame      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"
#include <stdio.h>

double	pl_intersection(t_vec ray, t_pl *pl, t_vec cl)
{
	long double	a;
	long double	b;
	long double	d;
	t_vec	normal;

	normal.x = pl->vec_x;
	normal.y = pl->vec_y;
	normal.z = pl->vec_z;
	normalize(&normal);
	d = -((normal.x * pl->x) + (normal.y * pl->y) + (normal.z * pl->z));
	a = (normal.x * ray.x) + (normal.y * ray.y) + (normal.z * ray.z);
	b = (normal.x * cl.x) + (normal.y * cl.y) + (normal.z * cl.z) + d;
	if (-b / a > 0)
		return (-b / a);
	return (-1);
} 

double	sp_intersection(t_vec ray, t_sp *sp, t_vec cl)
{
	double	a;
	double	b;
	double	c;
	double	delta;

	a = pow(ray.x, 2) + pow(ray.y, 2) + pow(ray.z, 2);
	b = 2 * ((ray.x * (cl.x - sp->x)) + (ray.y * (cl.y - sp->y)) +
	(ray.z * (cl.z - sp->z)));
	c = pow(cl.x - sp->x, 2) + pow(cl.y - sp->y, 2) +
	pow(cl.z - sp->z, 2) - pow(sp->diam / 2, 2);
	delta = pow(b, 2) - (4 * a * c);
	return (sp_roots(a, b, delta));
}

double	sq_intersection(t_vec ray, t_sq *sq, t_vec cl)
{
	t_vec	n;
	t_vec	m;
	double	a_p;
	double	b_p;
	double	half_c;

	half_c = sq->height / 2;
	n.x = sq->vec_x;
	n.y = sq->vec_y;
	n.z = sq->vec_z;
	normalize(&n);
	a_p = (n.x * ray.x) + (n.y * ray.y) + (n.z * ray.z);
	b_p = (n.x * cl.x) + (n.y * cl.y) + (n.z * cl.z) -
	((n.x * sq->x) + (n.y * sq->y) + (n.z * sq->z));
	m.x = cl.x + ((-b_p / a_p) * ray.x);
	m.y = cl.y + ((-b_p / a_p) * ray.y);
	m.z = cl.z + ((-b_p / a_p) * ray.z);
	if (sq_base(n, m, sq) && (-b_p / a_p) > 0)
		return (-b_p / a_p);
	return (-1);
}

double	cy_intersection(t_vec ray, t_cy *cy, t_vec cl)
{
	t_vec	tab[3];

	cy_fill_tab(tab, cy, cl);
	normalize(&tab[0]);
	return (cy_roots(tab, ray, cy, cl));
}

double	tr_intersection(t_vec ray, t_tr *tr, t_vec cl)
{
	t_vec	tab[3];
	t_vec	n;
	double	ret;
	t_vec	p;
	t_vec	ap;

	tr_init_vertices(tab, tr);
	n = cross_p(tab[0], tab[1]);
	normalize(&n);
	if ((ret = tr_plan(ray, tr, cl, n)) <= 0)
		return (-1);
	p.x = cl.x + (ret * ray.x);
	p.y = cl.y + (ret * ray.y);
	p.z = cl.z + (ret * ray.z);
	ap.x = p.x - tr->x_a;
	ap.y = p.y - tr->y_a;
	ap.z = p.z - tr->z_a;
	if (tr_barycenter(tab, ap, ret) > 0)
		return (ret);
	return (-1);
}
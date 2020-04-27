/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianhamel <florianhamel@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 16:20:25 by florianhame       #+#    #+#             */
/*   Updated: 2020/04/26 12:13:17 by florianhame      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"
#include <stdio.h>

long double	any_intersection(t_data *data, t_vec lgt_vec, t_vec cl, t_obj ref)
{
	t_obj		obj;
	long double	t;

	init_obj(&obj);
	obj.ptr = data->pl;
	while (obj.ptr != NULL)
	{
		if (obj.ptr != ref.ptr && (t = pl_intersection(lgt_vec, (t_pl *)(obj.ptr), cl)) > 0)
			return (t);
		obj.ptr = ((t_pl *)(obj.ptr))->next;
	}
	obj.ptr = data->sp;
	while (obj.ptr != NULL)
	{
		if (obj.ptr != ref.ptr && (t = sp_intersection(lgt_vec, (t_sp *)(obj.ptr), cl)) > 0)
			return (t);
		obj.ptr = ((t_sp *)(obj.ptr))->next;
	}
	obj.ptr = data->sq;
	while (obj.ptr != NULL )
	{
		if (obj.ptr != ref.ptr && (t = sq_intersection(lgt_vec, (t_sq *)(obj.ptr), cl)) > 0)
			return (t);
		obj.ptr = ((t_sq *)(obj.ptr))->next;
	}
	obj.ptr = data->cy;
	while (obj.ptr != NULL)
	{
		if (obj.ptr != ref.ptr && (t = cy_intersection(lgt_vec, (t_cy *)(obj.ptr), cl)) > 0)
			return (t);
		obj.ptr = ((t_cy *)(obj.ptr))->next;
	}
	obj.ptr = data->tr;
	while (obj.ptr != NULL)
	{
		if (obj.ptr != ref.ptr && (t = tr_intersection(lgt_vec, (t_tr *)(obj.ptr), cl)) > 0)
			return (t);
		obj.ptr = ((t_tr *)(obj.ptr))->next;
	}
	return (0);
}

int		lgt_intersection(t_obj obj, t_lgt *lgt, t_data *data)
{
	t_vec		lgt_vec;
	long double	len_vec;
	t_vec		cl;
	long double	t;

	lgt_vec.x = lgt->x - obj.x;
	lgt_vec.y = lgt->y - obj.y;
	lgt_vec.z = lgt->z - obj.z;
	len_vec = sqrt(pow(lgt_vec.x, 2) + pow(lgt_vec.y, 2) + pow(lgt_vec.z, 2));
	normalize(&lgt_vec);
	cl.x = obj.x;
	cl.y = obj.y;
	cl.z = obj.z;
	t = any_intersection(data, lgt_vec, cl, obj);
	if (t == 0)
		return (0);
	if (t < len_vec)
		return (1);
	return (0);
}

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
	t_vec	p;
	t_vec	ap;
	t_vec	bp;
	double	d;
	double	a;
	double	b;
	double	s;
	double	t;

	tab[0].x = tr->x_b - tr->x_a;
	tab[0].y = tr->y_b - tr->y_a;
	tab[0].z = tr->z_b - tr->z_a;
	// normalize(&tab[0]);
	tab[1].x = tr->x_c - tr->x_a;
	tab[1].y = tr->y_c - tr->y_a;
	tab[1].z = tr->z_c - tr->z_a;
	// normalize(&tab[1]);
	tab[2].x = tr->x_c - tr->x_b;
	tab[2].y = tr->y_c - tr->y_b;
	tab[2].z = tr->z_c - tr->z_b;
	// normalize(&tab[2]);
	n = cross_p(tab[0], tab[1]);
	normalize(&n);
	d = -((n.x * tr->x_a) + (n.y * tr->y_a) + (n.z * tr->z_a));
	a = (n.x * ray.x) + (n.y * ray.y) + (n.z * ray.z);
	b = (n.x * cl.x) + (n.y * cl.y) + (n.z * cl.z) + d;
	if (-b / a <= 0)
		return (-1);
	p.x = cl.x + ((-b / a) * ray.x);
	p.y = cl.y + ((-b / a) * ray.y);
	p.z = cl.z + ((-b / a) * ray.z);
	ap.x = p.x - tr->x_a;
	ap.y = p.y - tr->y_a;
	ap.z = p.z - tr->z_a;
	bp.x = p.x - tr->x_b;
	bp.y = p.y - tr->y_b;
	bp.z = p.z - tr->z_b;
	// normalize(&ap);
	// normalize(&bp);
	s = (dot_p(tab[0], tab[1]) * dot_p(ap, tab[1]) - (dot_p(tab[1], tab[1]) * dot_p(ap, tab[0]))) /
	(dot_p(tab[0], tab[1]) * dot_p(tab[0], tab[1]) - (dot_p(tab[0], tab[0]) * dot_p(tab[1], tab[1])));
	t = (dot_p(tab[0], tab[1]) * dot_p(ap, tab[0]) - (dot_p(tab[0], tab[0]) * dot_p(ap, tab[1]))) /
	(dot_p(tab[0], tab[1]) * dot_p(tab[0], tab[1]) - (dot_p(tab[0], tab[0]) * dot_p(tab[1], tab[1])));
	if (s >= 0 && t >= 0 && s + t <= 1 && (-b / a) > 0)
		return (-b / a);
	return (-1);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianhamel <florianhamel@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 16:57:47 by florianhame       #+#    #+#             */
/*   Updated: 2020/04/25 22:44:03 by florianhame      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"
#include <stdio.h>

double	sp_roots(double a, double b, double delta)
{
	double	root_1;
	double	root_2;

	root_1 = -1;
	root_2 = -1;
	if (delta < 0)
		return (-1);
	if (delta == 0)
	{
		root_1 = -b / (2 * a);
		if (root_1 >= 1)
			return (root_1);
		return (-1);
	}
	root_1 = ((-b - sqrt(delta)) / (2 * a));
	root_2 = ((-b + sqrt(delta)) / (2 * a));
	if (root_1 > 0 && root_2 > 0)
		return (fmin(root_1, root_2));
	if (root_1 > 0 || root_2 > 0)
		return (fmax(root_1, root_2));
	return (-1);
}

int		sq_base(t_vec n, t_vec m, t_sq *sq)
{
	t_vec	x;
	t_vec	u;
	t_vec	v;

	x.x = 0;
	x.y = 0;
	x.z = -1;
	if (n.x == 0 && n.y == 0 && n.z == -1)
	{
		u.x = 1;
		u.y = 0;
		u.z = 0;
		v.x = 0;
		v.y = 1;
		v.z = 0;
	}
	else
	{
		v = cross_p(x, n);
		u = cross_p(v, n);
		normalize(&v);
		normalize(&u);
	}
	return (sq_corners(u, v, m, sq));
}

int		sq_corners(t_vec u, t_vec v, t_vec m, t_sq *sq)
{
	t_vec	a;
	t_vec	b;
	t_vec	d;
	double	half_c;

	half_c = sq->height / 2;
	a.x = sq->x + (u.x * (-half_c)) + (v.x * half_c);
	a.y = sq->y + (u.y * (-half_c)) + (v.y * half_c);
	a.z = sq->z + (u.z * (-half_c)) + (v.z * half_c);
	b.x = sq->x + (u.x * half_c) + (v.x * half_c);
	b.y = sq->y + (u.y * half_c) + (v.y * half_c);
	b.z = sq->z + (u.z * half_c) + (v.z * half_c);
	d.x = sq->x + (u.x * (-half_c)) + (v.x * (-half_c));
	d.y = sq->y + (u.y * (-half_c)) + (v.y * (-half_c));
	d.z = sq->z + (u.z * (-half_c)) + (v.z * (-half_c));
	return (sq_final(a, b, d, m));
}

int		sq_final(t_vec a, t_vec b, t_vec d, t_vec m)
{
	t_vec	ab;
	t_vec	ad;
	t_vec	am;

	ab.x = b.x - a.x;
	ab.y = b.y - a.y;
	ab.z = b.z - a.z;
	ad.x = d.x - a.x;
	ad.y = d.y - a.y;
	ad.z = d.z - a.z;
	am.x = m.x - a.x;
	am.y = m.y - a.y;
	am.z = m.z - a.z;
	if ((0 <= dot_p(am, ab)) && (dot_p(am, ab) <= dot_p(ab, ab)) &&
	(0 <= dot_p(am, ad)) && dot_p(am, ad) <= dot_p(ad, ad))
		return (1);
	return (0);
}

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
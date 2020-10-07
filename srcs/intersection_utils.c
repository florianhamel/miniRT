/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianhamel <florianhamel@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 16:57:47 by florianhame       #+#    #+#             */
/*   Updated: 2020/06/24 12:07:51 by florianhame      ###   ########.fr       */
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
		if (root_1 > 0)
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

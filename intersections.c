/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianhamel <florianhamel@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 16:20:25 by florianhame       #+#    #+#             */
/*   Updated: 2020/04/12 19:59:18 by florianhame      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"
#include <stdio.h>

// double	any_intersection(t_vec vec, )

double	pl_intersection(t_vec cam_ray, t_pl *pl, t_cam *cam)
{
	double	a;
	double	b;
	double	d;
	t_vec	normal;

	normal.x = pl->vec_x;
	normal.y = pl->vec_y;
	normal.z = pl->vec_z;
	normalize(&normal);
	d = -((normal.x * pl->x) + (normal.y * pl->y) + (normal.z * pl->z));
	a = (normal.x * cam_ray.x) + (normal.y * cam_ray.y) + (normal.z * cam_ray.z);
	b = (normal.x * cam->x) + (normal.y * cam->y) + (normal.z * cam->z) + d;
	if (-b / a >= 1)
		return (-b / a);
	return (-1);
} 

double	sp_intersection(t_vec cam_ray, t_sp *sp, t_cam *cam)
{
	double	a;
	double	b;
	double	c;
	double	delta;
	double	root;

	a = pow(cam_ray.x, 2) + pow(cam_ray.y, 2) + pow(cam_ray.z, 2);
	b = 2 * ((cam_ray.x * (cam->x - sp->x)) + (cam_ray.y * (cam->y - sp->y)) +
	(cam_ray.z * (cam->z - sp->z)));
	c = pow(cam->x - sp->x, 2) + pow(cam->y - sp->y, 2) +
	pow(cam->z - sp->z, 2) - pow(sp->diam / 2, 2);
	delta = pow(b, 2) - (4 * a * c);
	return (sp_roots(a, b, c, delta));
}

double	sq_intersection(t_vec cam_ray, t_sq *sq, t_cam *cam)
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
	a_p = (n.x * cam_ray.x) + (n.y * cam_ray.y) + (n.z * cam_ray.z);
	b_p = (n.x * cam->x) + (n.y * cam->y) + (n.z * cam->z) -
	((n.x * sq->x) + (n.y * sq->y) + (n.z * sq->z));
	m.x = cam->x + ((-b_p / a_p) * cam_ray.x);
	m.y = cam->y + ((-b_p / a_p) * cam_ray.y);
	m.z = cam->z + ((-b_p / a_p) * cam_ray.z);
	if (sq_base(n, m, sq))
		return (-b_p / a_p);
	return (-1);
}

double	cy_intersection(t_vec cam_ray, t_cy *cy, t_cam *cam)
{
	t_vec	tab[3];

	cy_fill_tab(tab, cy, cam);
	normalize(&tab[0]);
	return (cy_roots(tab, cam_ray, cy, cam));
}

double	tr_intersection(t_vec cam_ray, t_tr *tr, t_cam *cam)
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
	a = (n.x * cam_ray.x) + (n.y * cam_ray.y) + (n.z * cam_ray.z);
	b = (n.x * cam->x) + (n.y * cam->y) + (n.z * cam->z) + d;
	if (-b / a < 1)
		return (-1);
	p.x = cam->x + ((-b / a) * cam_ray.x);
	p.y = cam->y + ((-b / a) * cam_ray.y);
	p.z = cam->z + ((-b / a) * cam_ray.z);
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
	if (s >= 0 && t >= 0 && s + t <= 1)
		return (-b / a);
	return (-1);
}
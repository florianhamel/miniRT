/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_utils3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianhamel <florianhamel@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 12:10:50 by florianhame       #+#    #+#             */
/*   Updated: 2020/06/24 12:11:15 by florianhame      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	tr_init_vertices(t_vec tab[3], t_tr *tr)
{
	tab[0].x = tr->x_b - tr->x_a;
	tab[0].y = tr->y_b - tr->y_a;
	tab[0].z = tr->z_b - tr->z_a;
	tab[1].x = tr->x_c - tr->x_a;
	tab[1].y = tr->y_c - tr->y_a;
	tab[1].z = tr->z_c - tr->z_a;
	tab[2].x = tr->x_c - tr->x_b;
	tab[2].y = tr->y_c - tr->y_b;
	tab[2].z = tr->z_c - tr->z_b;
}

double	tr_plan(t_vec ray, t_tr *tr, t_vec cl, t_vec n)
{
	double d;
	double a;
	double b;

	d = -((n.x * tr->x_a) + (n.y * tr->y_a) + (n.z * tr->z_a));
	a = (n.x * ray.x) + (n.y * ray.y) + (n.z * ray.z);
	b = (n.x * cl.x) + (n.y * cl.y) + (n.z * cl.z) + d;
	if (-b / a <= 0)
		return (-1);
	return (-b / a);
}

double	tr_barycenter(t_vec tab[3], t_vec ap, double ret)
{
	double	s;
	double	t;

	s = (dot_p(tab[0], tab[1]) * dot_p(ap, tab[1]) - (dot_p(tab[1], tab[1]) * dot_p(ap, tab[0]))) /
	(dot_p(tab[0], tab[1]) * dot_p(tab[0], tab[1]) - (dot_p(tab[0], tab[0]) * dot_p(tab[1], tab[1])));
	t = (dot_p(tab[0], tab[1]) * dot_p(ap, tab[0]) - (dot_p(tab[0], tab[0]) * dot_p(ap, tab[1]))) /
	(dot_p(tab[0], tab[1]) * dot_p(tab[0], tab[1]) - (dot_p(tab[0], tab[0]) * dot_p(tab[1], tab[1])));
	if (s >= 0 && t >= 0 && s + t <= 1 && ret > 0)
		return (ret);
	return (-1);
}

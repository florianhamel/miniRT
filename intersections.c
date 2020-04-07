/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianhamel <florianhamel@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 16:20:25 by florianhame       #+#    #+#             */
/*   Updated: 2020/04/07 17:45:17 by florianhame      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"
#include <stdio.h>

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
	root = get_root(a, b, c, delta);
	return (root);
}


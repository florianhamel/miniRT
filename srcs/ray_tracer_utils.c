/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracer_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianhamel <florianhamel@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 11:23:10 by florianhame       #+#    #+#             */
/*   Updated: 2020/04/26 12:00:45 by florianhame      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	normalize(t_vec *vec)
{
	double	len;

	len = sqrt(pow(vec->x, 2) + pow(vec->y, 2) + pow(vec->z, 2));
	vec->x /= len;
	vec->y /= len;
	vec->z /= len;
}

double	dot_p(t_vec a, t_vec b)
{
	double	dot_p;

	dot_p = (a.x * b.x) + (a.y * b.y) +
	(a.z * b.z);
	return (dot_p);
}

t_vec	cross_p(t_vec a, t_vec b)
{
	t_vec	c;

	c.x = (a.y * b.z) - (a.z * b.y);
	c.y = (a.z * b.x) - (a.x * b.z);
	c.z = (a.x * b.y) - (a.y * b.x);
	return (c);
}

void	init_obj(t_obj *obj)
{
	obj->id = -1;
	obj->x = 0;
	obj->y = 0;
	obj->z = 0;
	obj->len = INFINITY;
	obj->ptr = NULL;
}

void	fill_obj(t_data *data, t_obj *obj, double t, t_vec cam_ray)
{
	obj->x = data->c->x + (t * cam_ray.x);
	obj->y = data->c->y + (t * cam_ray.y);
	obj->z = data->c->z + (t * cam_ray.z);
	obj->len = sqrt(pow(obj->x - data->c->x, 2) +
	pow(obj->y - data->c->y, 2) +
	pow(obj->z - data->c->z, 2));
}
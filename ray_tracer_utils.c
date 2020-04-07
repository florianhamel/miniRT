/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracer_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianhamel <florianhamel@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 11:23:10 by florianhame       #+#    #+#             */
/*   Updated: 2020/04/07 19:06:48 by florianhame      ###   ########.fr       */
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

double	dot_product(t_vec vec_1, t_vec vec_2)
{
	double	dot_product;

	dot_product = (vec_1.x * vec_2.x) + (vec_1.y * vec_2.y) +
	(vec_1.z * vec_2.z);
	return (dot_product);
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
	obj->x = data->cam->x + (t * cam_ray.x);
	obj->y = data->cam->y + (t * cam_ray.y);
	obj->z = data->cam->z + (t * cam_ray.z);
	obj->len = sqrt(pow(obj->x - data->cam->x, 2) +
	pow(obj->y - data->cam->y, 2) +
	pow(obj->z - data->cam->z, 2));
}
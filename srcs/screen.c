/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianhamel <florianhamel@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 11:09:39 by florianhame       #+#    #+#             */
/*   Updated: 2020/06/22 11:10:54 by florianhame      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

t_vec	get_film(t_data *data)
{
	t_vec	cam_dir;
	t_vec	film;

	cam_dir.x = data->c->vec_x;
	cam_dir.y = data->c->vec_y;
	cam_dir.z = data->c->vec_z;
	normalize(&cam_dir);
	film.x = data->c->x + cam_dir.x;
	film.y = data->c->y + cam_dir.y;
	film.z = data->c->z + cam_dir.z;
	return (film);
}

t_vec	get_cam_ray(t_data *data, t_vec pix_cam, t_mtx4 m)
{
	t_vec	pix_pos;
	t_vec	cam_ray;

	pix_pos = mtx4_p(m, pix_cam);
	cam_ray.x = pix_pos.x - data->c->x;
	cam_ray.y = pix_pos.y - data->c->y;
	cam_ray.z = pix_pos.z - data->c->z;
	normalize(&cam_ray);
	// printf("x = %lf | y = %lf | z = %lf\n", cam_ray.x, cam_ray.y, cam_ray.z);
	return (cam_ray);
}

void	get_pix_cam(t_data *data, t_vec *pix_cam, t_pxl pxl)
{
	pix_cam->x = get_x_cam(data, pxl.x);
	pix_cam->y = get_y_cam(data, pxl.y);
	pix_cam->z = -1;
}

double	get_y_cam(t_data *data, int y)
{
	double	y_ndc;
	double	y_screen;
	double	ratio;
	double	y_cam;

	y_ndc = (y + 0.5) / data->res->y;
	y_screen = 1 - (2 * y_ndc); 
	ratio = (data->res->y > data->res->x ? (data->res->y / (double)data->res->x) : 1);
	y_cam = y_screen * ratio * tan(data->c->fov * (M_PI / 180) / 2);
	return (y_cam);
}

double	get_x_cam(t_data *data, int x)
{
	double	x_ndc;
	double	x_screen;
	double	ratio;
	double	x_cam;

	x_ndc = (x + 0.5) / data->res->x;
	x_screen = (2 * x_ndc) - 1; 
	ratio = (data->res->x > data->res->y ? (data->res->x / (double)data->res->y) : 1);
	x_cam = x_screen * ratio * tan(data->c->fov * (M_PI / 180) / 2);
	return (x_cam);
}
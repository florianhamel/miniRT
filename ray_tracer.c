/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianhamel <florianhamel@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 10:12:44 by florianhame       #+#    #+#             */
/*   Updated: 2020/04/07 23:02:08 by florianhame      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"
#include <stdio.h>

int	ray_tracer(t_data *data)
{
	int	**pix;
	int	y;
	int	x;

	y = 0;
	x = 0;
	if (!(pix = init_tab_pix(data->res->y, data->res->x)))
		return (-1);
	while (y < data->res->y)
	{
		x = 0;
		while (x < data->res->x)
		{
			pix[y][x] = get_pix(data, y, x);
			x++;
		}
		y++;
	}
	print_scene(data, pix);
	return (0);
}

int	**init_tab_pix(int res_y, int res_x)
{
	int	**pix;
	int	y;
	int	x;

	y = 0;
	x = 0;
	if (!(pix = (int **)malloc(sizeof(int *) * res_y)))
		return (NULL);		
	while (y < res_y)
	{
		x = 0;
		if (!(pix[y] = (int *)malloc(sizeof(int) * res_x)))
			return (NULL);
		while (x < res_x)
		{
			pix[y][x] = 0;
			x++;
		}
		y++;
	}
	return (pix);
}

int		get_pix(t_data *data, int y, int x)
{
	t_vec	cam_ray;
	t_vec	film;
	t_obj	obj;

	film = get_film(data);
	cam_ray = get_cam_ray(data, film, y, x);
	obj = closest_obj(data, cam_ray);
	return (color_obj(obj, data));
}

int		color_obj(t_obj obj, t_data *data)
{
	int		back_color;
	double	ratio;

	back_color = 0;
	ratio = fmax(0, f_ratio(obj, data));
	if (obj.id == 4)
		return (color_pl(obj, ratio));
	if (obj.id == 5)
		return (color_sp(obj, ratio));
	if (obj.id == 6)
		return (color_sq(obj, ratio));
	if (obj.id == 7)
		return (color_cy(obj, ratio));
	if (obj.id == 8)
		return (color_tr(obj, ratio));
	return (back_color);
}

double	f_ratio(t_obj obj, t_data *data)
{
	// if (obj.id == 4)
	// 	return (f_ratio_pl(obj, data));
	if (obj.id == 5)
		return (f_ratio_sp(obj, data));
	// if (obj.id == 6)
	// 	return (f_ratio_sq(obj, data));
	// if (obj.id == 7)
	// 	return (f_ratio_cy(obj, data));
	// if (obj.id == 8)
	// 	return (f_ratio_tr(obj, data));
	return (0);
}

double	f_ratio_sp(t_obj obj, t_data *data)
{
	t_vec	normal;
	t_vec	vec;
	double	f_ratio;

	normal.x = obj.x - ((t_sp *)(obj.ptr))->x;
	normal.y = obj.y - ((t_sp *)(obj.ptr))->y;
	normal.z = obj.z - ((t_sp *)(obj.ptr))->z;
	normalize(&normal);
	vec.x = data->lgt->x - obj.x;
	vec.y = data->lgt->y - obj.y;
	vec.z = data->lgt->z - obj.z;
	normalize(&vec);
	f_ratio = dot_product(normal, vec);
	return (f_ratio);
}

t_vec	get_film(t_data *data)
{
	t_vec	cam_dir;
	t_vec	film;

	cam_dir.x = data->cam->vec_x;
	cam_dir.y = data->cam->vec_y;
	cam_dir.z = data->cam->vec_z;
	normalize(&cam_dir);
	film.x = data->cam->x + cam_dir.x;
	film.y = data->cam->y + cam_dir.y;
	film.z = data->cam->z + cam_dir.z;
	return (film);
}

t_vec	get_cam_ray(t_data *data, t_vec film, int y, int x)
{
	double	x_cam;
	double	y_cam;
	t_vec	cam_ray;

	x_cam = get_x_cam(data, film, x);
	y_cam = get_y_cam(data, film, y);
	cam_ray.x = x_cam - data->cam->x;
	cam_ray.y = y_cam - data->cam->y;
	cam_ray.z = film.z - data->cam->z;
	normalize(&cam_ray);
	// printf("x = %lf\ny = %lf\nz = %lf\n", x_cam, y_cam, film.z);
	// printf("cam_ray.x = %lf\ncam_ray.y = %lf\ncam_ray.z = %lf\n\n", cam_ray.x, cam_ray.y, cam_ray.z);
	return (cam_ray);
}

double	get_y_cam(t_data *data, t_vec film, int y)
{
	double	y_ndc;
	double	y_screen;
	double	ratio;
	double	y_cam;

	y_ndc = (y + 0.5) / data->res->y;
	y_screen = 1 - (2 * y_ndc); 
	ratio = (data->res->y > data->res->x ? (data->res->y / data->res->x) : 1);
	y_cam = y_screen * ratio * tan(data->cam->fov * (M_PI / 180) / 2);
	y_cam += film.y;
	return (y_cam);
}

double	get_x_cam(t_data *data, t_vec film, int x)
{
	double	x_ndc;
	double	x_screen;
	double	ratio;
	double	x_cam;

	x_ndc = (x + 0.5) / data->res->y;
	x_screen = (2 * x_ndc) - 1; 
	ratio = (data->res->x > data->res->y ? data->res->x / data->res->y : 1);
	x_cam = x_screen * ratio * tan(data->cam->fov * (M_PI / 180) / 2);
	x_cam += film.x;
	return (x_cam);
}
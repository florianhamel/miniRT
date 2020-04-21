/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianhamel <florianhamel@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 10:12:44 by florianhame       #+#    #+#             */
/*   Updated: 2020/04/14 00:55:59 by florianhame      ###   ########.fr       */
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

	back_color = 16776960;
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
	t_vec	pix;
	t_vec	cam_ray;
	t_mtx4	m;

	pix.x = get_x_cam(data, film, x);
	pix.y = get_y_cam(data, film, y);
	pix.z = -1;
	m = mtx4_world(data, film);
	pix = mtx4_p(m, pix);
	cam_ray.x = pix.x - data->cam->x;
	cam_ray.y = pix.y - data->cam->y;
	cam_ray.z = pix.z - data->cam->z;
	normalize(&cam_ray);
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
	ratio = (data->res->y > data->res->x ? (data->res->y / (double)data->res->x) : 1);
	y_cam = y_screen * ratio * tan(data->cam->fov * (M_PI / 180) / 2);
	return (y_cam);
}

double	get_x_cam(t_data *data, t_vec film, int x)
{
	double	x_ndc;
	double	x_screen;
	double	ratio;
	double	x_cam;
	t_mtx4	m;

	x_ndc = (x + 0.5) / data->res->x;
	x_screen = (2 * x_ndc) - 1; 
	ratio = (data->res->x > data->res->y ? (data->res->x / (double)data->res->y) : 1);
	x_cam = x_screen * ratio * tan(data->cam->fov * (M_PI / 180) / 2);
	return (x_cam);
}

t_mtx4	mtx4_world(t_data *data, t_vec film)
{
	t_mtx4	m;
	t_vec	e;

	m.c.x = data->cam->x;
	m.c.y = data->cam->y;
	m.c.z = data->cam->z;
	m.f.x = data->cam->x - film.x;
	m.f.y = data->cam->y - film.y;
	m.f.z = data->cam->z - film.z;
	normalize(&(m.f));
	if (data->cam->vec_x != 0 && fabs(data->cam->vec_y) != 1 && data->cam->vec_z != 0)
	{
		e.x = 0;
		e.y = 1;
		e.z = 0;
	}
	else
	{
		e.x = 0;
		e.y = 0;
		e.z = -1;
	}
	m.r = cross_p(e, m.f);
	m.u = cross_p(m.f, m.r);
	return (m);
}

t_vec	mtx4_p(t_mtx4 m, t_vec p)
{
	t_vec	pix;

	pix.x = m.c.x + (p.z * m.f.x) + (p.y * m.u.x) + (p.x * m.r.x);
	pix.y = m.c.y + (p.z * m.f.y) + (p.y * m.u.y) + (p.x * m.r.y);
	pix.z = m.c.z + (p.z * m.f.z) + (p.y * m.u.z) + (p.x * m.r.z);
	return (pix);
}
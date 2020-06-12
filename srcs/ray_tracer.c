/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianhamel <florianhamel@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 10:12:44 by florianhame       #+#    #+#             */
/*   Updated: 2020/06/10 15:06:04 by florianhame      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"
#include "ft_printf.h"
#include <stdio.h>

int	ray_tracer(t_data *data)
{
	int			**pix;
	t_vec		film;
	t_mtx4		m;
	t_pxl		pxl;

	pxl.x = 0;
	pxl.y = 0;
	data->res->x = sl_res_x(data);
	film = get_film(data);
	m = mtx4_world(data, film);
	if (!(pix = init_tab_pix(data->res->y, data->res->x)))
		return (-1);
	while (pxl.y < data->res->y)
	{
		pxl.x = 0;
		while (pxl.x < data->res->x)
		{
			pix[pxl.y][pxl.x] = get_pix(data, pxl, m);
			pxl.x++;
		}
		pxl.y++;
	}
	print_scene(data, pix);
	return (0);
}

int	sl_res_x(t_data *data)
{
	int	new_res;

	new_res = data->res->x;
	if (data->res->x % 64 != 0)
		new_res = new_res - (new_res % 64) + 64;
	return (new_res);
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

int		get_pix(t_data *data, t_pxl pxl, t_mtx4 m)
{
	t_vec	cam_ray;
	t_vec	pix_cam;
	t_obj	obj;

	get_pix_cam(data, &pix_cam, pxl);
	cam_ray = get_cam_ray(data, pix_cam, m);
	obj = closest_obj(data, cam_ray);
	// printf("%d\n", obj.id);
	return (color_obj(data, obj));
}

void	init_col(t_col *col, t_data *data)
{
	col->r = data->amb->r * data->amb->power;
	col->g = data->amb->g * data->amb->power;
	col->b = data->amb->b * data->amb->power;
	col->nb_lgts = 1;
}

double	get_len_lgt(t_obj obj, t_lgt *lgt)
{
	t_vec	lgt_vec;

	lgt_vec.x = obj.x - lgt->x;
	lgt_vec.y = obj.y - lgt->y;
	lgt_vec.z = obj.z - lgt->z;
	return (sqrt(pow(lgt_vec.x, 2) + pow(lgt_vec.y, 2) + pow(lgt_vec.z, 2)));
}

int		color_obj(t_data *data, t_obj obj)
{
	int		back_color;
	t_lgt	*lgt;
	double	ratio;
	t_col	col;
	double	len_lgt;

	// back_color = 16776960;
	back_color = 0;
	lgt = data->lgt;
	ratio = 0;
	init_col(&col, data);
	while (lgt != NULL)
	{
		if (!lgt_intersection(obj, lgt, data))
		{
			len_lgt = get_len_lgt(obj, lgt);
			// ratio += fmax(0, f_ratio(obj, lgt, data->c)) * lgt->power;
			ratio = fmax(0, f_ratio(obj, lgt, data->c));
			col.r += lgt->r * lgt->power * ratio;
			col.g += lgt->g * lgt->power * ratio;
			col.b += lgt->b * lgt->power * ratio;
		}
		lgt = lgt->next;
	}
	col.r = (int)fmin(255, col.r);
	col.g = (int)fmin(255, col.g);
	col.b = (int)fmin(255, col.b);
	if (obj.id == 4)
		return (color_pl(obj, ratio, col));
	if (obj.id == 5)
		return (color_sp(obj, ratio, col));
	if (obj.id == 6)
		return (color_sq(obj, ratio, col));
	if (obj.id == 7)
		return (color_cy(obj, ratio, col));
	if (obj.id == 8)
		return (color_tr(obj, ratio, col));
	return (back_color);
}

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

t_mtx4	mtx4_world(t_data *data, t_vec film)
{
	t_mtx4	m;
	t_vec	e;

	m.c.x = data->c->x;
	m.c.y = data->c->y;
	m.c.z = data->c->z;
	m.f.x = data->c->x - film.x;
	m.f.y = data->c->y - film.y;
	m.f.z = data->c->z - film.z;
	normalize(&(m.f));
	if (data->c->vec_x == 0 && fabs(data->c->vec_y) == 1 && data->c->vec_z == 0)
	{
		e.x = 0;
		e.y = 0;
		e.z = -1;
	}
	else
	{
		e.x = 0;
		e.y = 1;
		e.z = 0;
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
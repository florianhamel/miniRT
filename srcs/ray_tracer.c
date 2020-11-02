/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 10:12:44 by florianhame       #+#    #+#             */
/*   Updated: 2020/11/01 12:33:02 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int	ray_tracer(t_data *data)
{
	int			**pix;
	t_vec		film;
	t_mtx4		m;
	t_pxl		pxl;

	pxl.x = 0;
	pxl.y = 0;
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

int	get_pix(t_data *data, t_pxl pxl, t_mtx4 m)
{
	t_vec	cam_ray;
	t_vec	pix_cam;
	t_obj	obj;

	get_pix_cam(data, &pix_cam, pxl);
	cam_ray = get_cam_ray(data, pix_cam, m);
	obj = closest_obj(data, cam_ray);
	return (color_obj(data, obj));
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

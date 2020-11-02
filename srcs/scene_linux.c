/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_linux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 10:54:58 by florianhame       #+#    #+#             */
/*   Updated: 2020/11/01 12:28:27 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

t_obj	closest_obj(t_data *data, t_vec cam_ray)
{
	t_vec	cl;
	t_obj	obj;
	t_obj	tmp;

	cl.x = data->c->x;
	cl.y = data->c->y;
	cl.z = data->c->z;
	init_obj(&obj);
	if ((tmp = closest_pl(data, cam_ray, cl)).len < obj.len && tmp.len > 0)
		obj = tmp;
	if ((tmp = closest_sp(data, cam_ray, cl)).len < obj.len && tmp.len > 0)
		obj = tmp;
	if ((tmp = closest_sq(data, cam_ray, cl)).len < obj.len && tmp.len > 0)
		obj = tmp;
	if ((tmp = closest_cy(data, cam_ray, cl)).len < obj.len && tmp.len > 0)
		obj = tmp;
	if ((tmp = closest_tr(data, cam_ray, cl)).len < obj.len && tmp.len > 0)
		obj = tmp;
	return (obj);
}

void	init_scene(t_infos *infos, t_data *data)
{
	infos->mlx = mlx_init();
	if (!data->save)
		infos->win = mlx_new_window(infos->mlx, data->res->x,
		data->res->y, "Scene");
	infos->img_ptr = mlx_new_image(infos->mlx, data->res->x, data->res->y);
	infos->img_addr = mlx_get_data_addr(infos->img_ptr,
	&(infos->bpp), &(infos->sl), &(infos->end));
	infos->data = data;
	infos->bpp = infos->bpp / 8;
	infos->x = 0;
	infos->y = 0;
}

void	fill_img(t_infos *infos, t_data *data, int **pix)
{
	int	i;

	i = 0;
	while (i < (4 * data->res->x / infos->bpp) * data->res->y)
	{
		infos->x = 0;
		while (infos->x < data->res->x)
		{
			*(int *)(&(infos->img_addr)[i * infos->bpp]) =
			pix[infos->y][infos->x];
			infos->x++;
			i++;
		}
		infos->y++;
	}
}

void	print_scene(t_data *data, int **pix)
{
	t_infos	infos;

	init_scene(&infos, data);
	fill_img(&infos, data, pix);
	if (data->save)
		write_bmp(&infos);
	else
	{
		mlx_put_image_to_window(infos.mlx, infos.win, infos.img_ptr, 0, 0);
		mlx_hook(infos.win, VISI_NOTIFY, VISI_CHANGE_MASK, visible, &infos);
		mlx_hook(infos.win, DESTROY_NOTIFY, STRUCT_NOTIFY_MASK, cross, &infos);
		mlx_hook(infos.win, KEY_PRESS, KEY_PRESS_MASK, events, &infos);
		mlx_loop(infos.mlx);
	}
}

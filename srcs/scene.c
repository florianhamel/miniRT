/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianhamel <florianhamel@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 10:54:58 by florianhame       #+#    #+#             */
/*   Updated: 2020/10/21 18:31:51 by florianhame      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"
#include "mlx.h"

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

int	events(int keycode, void *infos_ptr)
{
	t_infos	*infos;

	infos = (t_infos *)infos_ptr;
	if (keycode == 53)
	{
		mlx_destroy_window(infos->mlx, infos->win);
		exit(0);
	}
	if (keycode == 123)
	{
		infos->data->c = infos->data->c->prev;
		mlx_destroy_window(infos->mlx, infos->win);
		ray_tracer(infos->data);
	}
	if (keycode == 124)
	{
		infos->data->c = infos->data->c->next;
		mlx_destroy_window(infos->mlx, infos->win);
		ray_tracer(infos->data);
	}
	return (0);
}

void	init_scene(t_infos *infos, t_data *data)
{
	infos->mlx = mlx_init();
	infos->win = mlx_new_window(infos->mlx, data->res->x, data->res->y, "Scene");
	infos->img_ptr = mlx_new_image(infos->mlx, data->res->x, data->res->y);
	infos->img_addr = mlx_get_data_addr(infos->img_ptr,
	&(infos->bpp), &(infos->sl), &(infos->end));
	infos->data = data;
	infos->bpp = infos->bpp / 8;
	infos->x = 0;
	infos->y = 0;
}

void	print_scene(t_data *data, int **pix)
{
	t_infos	infos;
	int		i;

	init_scene(&infos, data);
	i = 0;
	while (i < (infos.sl / infos.bpp) * data->res->y)
	{
		infos.x = 0;
		while (infos.x < data->res->x)
		{	
			*(int *)(&(infos.img_addr)[i * infos.bpp]) = pix[infos.y][infos.x];
			infos.x++;
			i++;
		}
		infos.y++;
	}
	if (data->save == 1)
		write_bmp(&infos);
	else
	{
		mlx_put_image_to_window(infos.mlx, infos.win, infos.img_ptr, 0, 0);
		mlx_hook(infos.win, 2, 0, events, &infos);
		mlx_loop(infos.mlx);
	}
}
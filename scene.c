/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianhamel <florianhamel@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 14:01:38 by florianhame       #+#    #+#             */
/*   Updated: 2020/04/15 14:28:47 by florianhame      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"
#include "mlx.h"
#include <stdio.h>

t_obj	closest_obj(t_data *data, t_vec cam_ray)
{
	t_obj	obj;
	t_obj	tmp;

	init_obj(&obj);
	if ((tmp = closest_pl(data, cam_ray)).len < obj.len)
	 	obj = tmp;
	if ((tmp = closest_sp(data, cam_ray)).len < obj.len)
		obj = tmp;
	if ((tmp = closest_sq(data, cam_ray)).len < obj.len)
		obj = tmp;
	if ((tmp = closest_cy(data, cam_ray)).len < obj.len)
		obj = tmp;
	if ((tmp = closest_tr(data, cam_ray)).len < obj.len)
		obj = tmp;
	return (obj);
}

t_obj	closest_pl(t_data *data, t_vec cam_ray)
{
	t_pl	*pl;
	t_obj	obj;
	t_obj	tmp;
	double	t;

	pl = data->pl;
	init_obj(&obj);
	init_obj(&tmp);
	t = -1;
	while (pl != NULL)
	{
		t = pl_intersection(cam_ray, pl, data->cam);
		if (t != -1)
		{
			tmp.id = 4;
			fill_obj(data, &tmp, t, cam_ray);
			tmp.ptr = pl;
			if (tmp.len < obj.len)
				obj = tmp;
		}
		pl = pl->next;
	}
	return (obj);
}

t_obj	closest_sp(t_data *data, t_vec cam_ray)
{
	t_sp	*sp;
	t_obj	obj;
	t_obj	tmp;
	double	t;

	sp = data->sp;
	init_obj(&obj);
	init_obj(&tmp);
	t = -1;
	while (sp != NULL)
	{
		t = sp_intersection(cam_ray, sp, data->cam);
		if (t != -1)
		{
			tmp.id = 5;
			fill_obj(data, &tmp, t, cam_ray);
			tmp.ptr = sp;
			if (tmp.len < obj.len)
				obj = tmp;
		}
		sp = sp->next;
	}
	return (obj);
}

t_obj	closest_sq(t_data *data, t_vec cam_ray)
{
	t_sq	*sq;
	t_obj	obj;
	t_obj	tmp;
	double	t;

	sq = data->sq;
	init_obj(&obj);
	init_obj(&tmp);
	t = -1;
	while (sq != NULL)
	{
		t = sq_intersection(cam_ray, sq, data->cam);
		if (t != -1)
		{
			tmp.id = 6;
			fill_obj(data, &tmp, t, cam_ray);
			tmp.ptr = sq;
			if (tmp.len < obj.len)
				obj = tmp;
		}
		sq = sq->next;
	}
	return (obj);
}

t_obj	closest_cy(t_data *data, t_vec cam_ray)
{
	t_cy	*cy;
	t_obj	obj;
	t_obj	tmp;
	double	t;

	cy = data->cy;
	init_obj(&obj);
	init_obj(&tmp);
	t = -1;
	while (cy != NULL)
	{
		t = cy_intersection(cam_ray, cy, data->cam);
		if (t != -1)
		{
			tmp.id = 7;
			fill_obj(data, &tmp, t, cam_ray);
			tmp.ptr = cy;
			if (tmp.len < obj.len)
				obj = tmp;
		}
		cy = cy->next;
	}
	return (obj);
}

t_obj	closest_tr(t_data *data, t_vec cam_ray)
{
	t_tr	*tr;
	t_obj	obj;
	t_obj	tmp;
	double	t;

	tr = data->tr;
	init_obj(&obj);
	init_obj(&tmp);
	t = -1;
	while (tr != NULL)
	{
		t = tr_intersection(cam_ray, tr, data->cam);
		if (t != -1)
		{
			tmp.id = 8;
			fill_obj(data, &tmp, t, cam_ray);
			tmp.ptr = tr;
			if (tmp.len < obj.len)
				obj = tmp;
		}
		tr = tr->next;
	}
	return (obj);
}

int	test(int keycode, void *win)
{
	t_win	*w;

	w = (t_win *)win;
	if (keycode == 53)
	{
		mlx_destroy_window(w->mlx, w->win);
		exit(0);
	}
	return (0);
}

void	print_scene(t_data *data, int **pix)
{
	void	*mlx_ptr;
	void	*mlx_win;
	void	*img_ptr;
	char	*img_addr;
	int		bpp;
	int		sl;
	int		end;
	int		i;
	int		y;
	int		x;
	t_win	w;

	mlx_ptr = mlx_init();
	mlx_win = mlx_new_window(mlx_ptr, data->res->x, data->res->y, "Plan");
	w.mlx = mlx_ptr;
	w.win = mlx_win;
	img_ptr = mlx_new_image(mlx_ptr, data->res->x, data->res->y);
	img_addr = mlx_get_data_addr(img_ptr, &bpp, &sl, &end);
	bpp = bpp / 8;
	printf("bpp = %d\nsl = %d\nsl / bpp = %d\n", bpp, sl, sl / bpp);
	y = 0;
	x = 0;
	// i = 0;
	// while (i < (sl / bpp) * data->res->y && y < data->res->y)
	// {
	// 	*(int*)(&img_addr[i * bpp]) = pix[y][x];
	// 	if (i % (sl / bpp) > data->res->x)
	// 	{
	// 		x = 0;
	// 		y++;
	// 	}
	// 	else
	// 		x++;
	// 	i++;
	// }
	// mlx_put_image_to_window(mlx_ptr, mlx_win, img_ptr, 0, 0);
	while (y < data->res->y)
	{
		x = 0;
		while (x < data->res->x)
		{
			mlx_pixel_put();
			x++;
		}
	}
	mlx_hook(mlx_win, 2, 0, test, &w);
	mlx_loop_hook(mlx_ptr, &test, &w);
	mlx_loop(mlx_ptr);
}

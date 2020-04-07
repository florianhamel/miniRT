/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianhamel <florianhamel@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 14:01:38 by florianhame       #+#    #+#             */
/*   Updated: 2020/04/07 18:35:04 by florianhame      ###   ########.fr       */
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
	// if ((tmp = closest_pl(data, obj, cam_ray)).len < obj.len)
	// 	obj = tmp;
	if ((tmp = closest_sp(data, cam_ray)).len < obj.len)
		obj = tmp;
	// else if ((tmp = closest_sq(data, obj, cam_ray)).len < obj.len)
	// 	obj = tmp;
	// else if ((tmp = closest_cy(data, obj, cam_ray)).len < obj.len)
	// 	obj = tmp;37
	// else if ((tmp = closest_tr(data, obj, cam_ray)).len < obj.len)
	// 	obj = tmp;
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

	mlx_ptr = mlx_init();
	mlx_win = mlx_new_window(mlx_ptr, data->res->x, data->res->y, "Plan");
	img_ptr = mlx_new_image(mlx_ptr, data->res->x, data->res->y);
	img_addr = mlx_get_data_addr(img_ptr, &bpp, &sl, &end);
	i = 0;
	bpp = bpp / 8;
	// printf("sl = %d\n", sl);
	// printf("bpp = %d\n", bpp);
	// printf("sl / bpp = %d\n", sl / bpp);
	while (i < (sl / bpp) * data->res->y)
	{
		*(int*)(&img_addr[i * bpp]) = pix[i / data->res->y][i % data->res->x];
		i++;
	}
	mlx_put_image_to_window(mlx_ptr, mlx_win, img_ptr, 0, 0);
	mlx_loop(mlx_ptr);
}

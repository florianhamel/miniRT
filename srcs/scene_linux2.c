/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_linux2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 10:11:55 by fhamel            #+#    #+#             */
/*   Updated: 2020/11/01 10:12:32 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int		visible(void *infos_ptr)
{
	t_infos *infos;

	infos = (t_infos *)infos_ptr;
	mlx_put_image_to_window(infos->mlx, infos->win, infos->img_ptr, 0, 0);
	return (0);
}

int		events(int keycode, void *infos_ptr)
{
	t_infos	*infos;

	infos = (t_infos *)infos_ptr;
	if (keycode == ESCAPE_WIN)
	{
		mlx_destroy_window(infos->mlx, infos->win);
		exit(0);
	}
	if (keycode == PREV_SCENE)
	{
		mlx_destroy_window(infos->mlx, infos->win);
		mlx_destroy_display(infos->mlx);
		infos->data->c = infos->data->c->prev;
		ray_tracer(infos->data);
	}
	if (keycode == NEXT_SCENE)
	{
		mlx_destroy_window(infos->mlx, infos->win);
		mlx_destroy_display(infos->mlx);
		infos->data->c = infos->data->c->next;
		ray_tracer(infos->data);
	}
	return (0);
}

int		cross(void *infos_ptr)
{
	t_infos	*infos;

	infos = (t_infos *)infos_ptr;
	mlx_destroy_window(infos->mlx, infos->win);
	exit(0);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objs_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 14:01:38 by florianhame       #+#    #+#             */
/*   Updated: 2020/10/28 09:02:23 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

t_obj	closest_pl(t_data *data, t_vec cam_ray, t_vec cl)
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
		t = pl_intersection(cam_ray, pl, cl);
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

t_obj	closest_sp(t_data *data, t_vec cam_ray, t_vec cl)
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
		t = sp_intersection(cam_ray, sp, cl);
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

t_obj	closest_sq(t_data *data, t_vec cam_ray, t_vec cl)
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
		t = sq_intersection(cam_ray, sq, cl);
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

t_obj	closest_cy(t_data *data, t_vec cam_ray, t_vec cl)
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
		t = cy_intersection(cam_ray, cy, cl);
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

t_obj	closest_tr(t_data *data, t_vec cam_ray, t_vec cl)
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
		t = tr_intersection(cam_ray, tr, cl);
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

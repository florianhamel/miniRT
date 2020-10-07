/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_intersection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianhamel <florianhamel@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 12:04:34 by florianhame       #+#    #+#             */
/*   Updated: 2020/08/15 18:03:32 by florianhame      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"
#include <stdio.h>

int		same_point(t_vec lgt_vec, t_vec cl, t_obj ref, double t)
{
	t_vec tmp;

	normalize(&lgt_vec);
	tmp.x = cl.x + t * lgt_vec.x;
	tmp.y = cl.y + t * lgt_vec.y;
	tmp.z = cl.z + t * lgt_vec.z;
	if (tmp.x - SAME_POINT < ref.x && ref.x < tmp.x + SAME_POINT &&
	tmp.y - SAME_POINT < ref.y && ref.y < tmp.y + SAME_POINT &&
	tmp.z - SAME_POINT < ref.z && ref.z < tmp.z + SAME_POINT)
		return (1);
	return (0);
}

long double	any_intersection(t_data *data, t_vec lgt_vec, t_vec cl, t_obj ref)
{
	t_obj		obj;
	long double	t;

	init_obj(&obj);
	obj.ptr = data->pl;
	if ((t = pl_block(obj, lgt_vec, cl, ref)) > 0)
		return (t);
	obj.ptr = data->sp;
	if ((t = sp_block(obj, lgt_vec, cl, ref)) > 0)
		return (t);
	obj.ptr = data->sq;
	if ((t = sq_block(obj, lgt_vec, cl, ref)) > 0)
		return (t);
	obj.ptr = data->cy;
	if ((t = cy_block(obj, lgt_vec, cl, ref)) > 0)
		return (t);
	obj.ptr = data->tr;
	if ((t = tr_block(obj, lgt_vec, cl, ref)) > 0)
		return (t);
	return (0);
}

int		lgt_intersection(t_obj obj, t_lgt *lgt, t_data *data)
{
	t_vec		lgt_vec;
	t_vec		cl;
	long double	t;

	lgt_vec.x = obj.x - lgt->x;
	lgt_vec.y = obj.y - lgt->y;
	lgt_vec.z = obj.z - lgt->z;
	// lgt_vec.x = lgt->x - obj.x;
	// lgt_vec.y = lgt->y - obj.y;
	// lgt_vec.z = lgt->z - obj.z;
	cl.x = lgt->x;
	cl.y = lgt->y;
	cl.z = lgt->z;
	// cl.x = obj.x;
	// cl.y = obj.y;
	// cl.z = obj.z;
	t = any_intersection(data, lgt_vec, cl, obj);
	if (t == 0)
		return (0);
	return (t);
}

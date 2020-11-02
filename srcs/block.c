/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 11:52:49 by florianhame       #+#    #+#             */
/*   Updated: 2020/11/02 10:39:22 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

long double	pl_block(t_obj obj, t_vec lgt_vec, t_vec cl, t_obj ref)
{
	long double	t;
	long double	len_vec;

	len_vec = sqrt(pow(lgt_vec.x, 2) + pow(lgt_vec.y, 2) + pow(lgt_vec.z, 2));
	normalize(&lgt_vec);
	while (obj.ptr != NULL)
	{
		if (obj.ptr != ref.ptr && (t = pl_intersection(lgt_vec,
		(t_pl *)(obj.ptr), cl)) > 0
		&& t < len_vec)
			return (t);
		obj.ptr = ((t_pl *)(obj.ptr))->next;
	}
	return (0);
}

long double	sp_block(t_obj obj, t_vec lgt_vec, t_vec cl, t_obj ref)
{
	long double	t;
	long double	len_vec;

	len_vec = sqrt(pow(lgt_vec.x, 2) + pow(lgt_vec.y, 2) + pow(lgt_vec.z, 2));
	normalize(&lgt_vec);
	while (obj.ptr != NULL)
	{
		if (obj.ptr != ref.ptr && (t = sp_intersection(lgt_vec,
		(t_sp *)(obj.ptr), cl)) > 0
		&& t < len_vec)
			return (t);
		obj.ptr = ((t_sp *)(obj.ptr))->next;
	}
	return (0);
}

long double	sq_block(t_obj obj, t_vec lgt_vec, t_vec cl, t_obj ref)
{
	long double	t;
	long double	len_vec;

	len_vec = sqrt(pow(lgt_vec.x, 2) + pow(lgt_vec.y, 2) + pow(lgt_vec.z, 2));
	normalize(&lgt_vec);
	while (obj.ptr != NULL)
	{
		if (obj.ptr != ref.ptr && (t = sq_intersection(lgt_vec,
		(t_sq *)(obj.ptr), cl)) > 0
		&& t < len_vec)
			return (t);
		obj.ptr = ((t_sq *)(obj.ptr))->next;
	}
	return (0);
}

long double	cy_block(t_obj obj, t_vec lgt_vec, t_vec cl, t_obj ref)
{
	long double	t;
	long double	len_vec;

	len_vec = sqrt(pow(lgt_vec.x, 2) + pow(lgt_vec.y, 2) + pow(lgt_vec.z, 2));
	normalize(&lgt_vec);
	while (obj.ptr != NULL)
	{
		if ((t = cy_intersection(lgt_vec, (t_cy *)(obj.ptr), cl)) > 0 &&
		t < len_vec && !same_point(lgt_vec, cl, ref, t))
			return (t);
		obj.ptr = ((t_cy *)(obj.ptr))->next;
	}
	return (0);
}

long double	tr_block(t_obj obj, t_vec lgt_vec, t_vec cl, t_obj ref)
{
	long double	t;
	long double	len_vec;

	len_vec = sqrt(pow(lgt_vec.x, 2) + pow(lgt_vec.y, 2) + pow(lgt_vec.z, 2));
	normalize(&lgt_vec);
	while (obj.ptr != NULL)
	{
		if (obj.ptr != ref.ptr && (t = tr_intersection(lgt_vec,
		(t_tr *)(obj.ptr), cl)) > 0
		&& t < len_vec)
			return (t);
		obj.ptr = ((t_tr *)(obj.ptr))->next;
	}
	return (0);
}

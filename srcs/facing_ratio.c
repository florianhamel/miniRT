/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   facing_ratio.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 16:23:40 by florianhame       #+#    #+#             */
/*   Updated: 2020/10/28 14:50:18 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

double	f_ratio_pl(t_obj obj, t_lgt *lgt, t_cam *c)
{
	t_vec	vec;
	t_vec	n;

	vec.x = lgt->x - obj.x;
	vec.y = lgt->y - obj.y;
	vec.z = lgt->z - obj.z;
	normalize(&vec);
	n.x = -((t_pl *)(obj.ptr))->vec_x;
	n.y = -((t_pl *)(obj.ptr))->vec_y;
	n.z = -((t_pl *)(obj.ptr))->vec_z;
	normalize(&n);
	n = get_right_n(n, c, obj);
	return (dot_p(n, vec));
}

double	f_ratio_sp(t_obj obj, t_lgt *lgt, t_cam *c)
{
	t_vec	vec;
	t_vec	n;

	vec.x = lgt->x - obj.x;
	vec.y = lgt->y - obj.y;
	vec.z = lgt->z - obj.z;
	normalize(&vec);
	n.x = obj.x - ((t_sp *)(obj.ptr))->x;
	n.y = obj.y - ((t_sp *)(obj.ptr))->y;
	n.z = obj.z - ((t_sp *)(obj.ptr))->z;
	normalize(&n);
	n = get_right_n(n, c, obj);
	return (dot_p(n, vec));
}

double	f_ratio_sq(t_obj obj, t_lgt *lgt, t_cam *c)
{
	t_vec	vec;
	t_vec	n;

	vec.x = lgt->x - obj.x;
	vec.y = lgt->y - obj.y;
	vec.z = lgt->z - obj.z;
	normalize(&vec);
	n.x = -((t_sq *)(obj.ptr))->vec_x;
	n.y = -((t_sq *)(obj.ptr))->vec_y;
	n.z = -((t_sq *)(obj.ptr))->vec_z;
	normalize(&n);
	n = get_right_n(n, c, obj);
	return (dot_p(n, vec));
}

double	f_ratio_cy(t_obj obj, t_lgt *lgt, t_cam *c)
{
	t_vec	vec;
	t_vec	op;
	double	t;
	t_vec	u;
	t_vec	n;

	vec.x = lgt->x - obj.x;
	vec.y = lgt->y - obj.y;
	vec.z = lgt->z - obj.z;
	normalize(&vec);
	op.x = obj.x - ((t_cy *)(obj.ptr))->x;
	op.y = obj.y - ((t_cy *)(obj.ptr))->y;
	op.z = obj.z - ((t_cy *)(obj.ptr))->z;
	t = sqrt(fmax(0, pow(sqrt(pow(op.x, 2) + pow(op.y, 2) +
	pow(op.z, 2)), 2) - pow(((t_cy *)(obj.ptr))->diam / 2, 2)));
	u.x = ((t_cy *)(obj.ptr))->vec_x;
	u.y = ((t_cy *)(obj.ptr))->vec_y;
	u.z = ((t_cy *)(obj.ptr))->vec_z;
	normalize(&u);
	normalize(&op);
	n = get_right_n(get_n(u, op, obj, t), c, obj);
	return (dot_p(n, vec));
}

double	f_ratio_tr(t_obj obj, t_lgt *lgt, t_cam *c)
{
	t_vec	vec;
	t_vec	ab;
	t_vec	ac;
	t_vec	n;

	vec.x = lgt->x - obj.x;
	vec.y = lgt->y - obj.y;
	vec.z = lgt->z - obj.z;
	normalize(&vec);
	ab.x = ((t_tr *)(obj.ptr))->x_b - ((t_tr *)(obj.ptr))->x_a;
	ab.y = ((t_tr *)(obj.ptr))->y_b - ((t_tr *)(obj.ptr))->y_a;
	ab.z = ((t_tr *)(obj.ptr))->z_b - ((t_tr *)(obj.ptr))->z_a;
	ac.x = ((t_tr *)(obj.ptr))->x_c - ((t_tr *)(obj.ptr))->x_a;
	ac.y = ((t_tr *)(obj.ptr))->y_c - ((t_tr *)(obj.ptr))->y_a;
	ac.z = ((t_tr *)(obj.ptr))->z_c - ((t_tr *)(obj.ptr))->z_a;
	n = cross_p(ab, ac);
	normalize(&n);
	n = get_right_n(n, c, obj);
	return (dot_p(n, vec));
}

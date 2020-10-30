/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   facing_ratio2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 12:17:33 by florianhame       #+#    #+#             */
/*   Updated: 2020/10/28 15:02:47 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

double	f_ratio(t_obj obj, t_lgt *lgt, t_cam *c)
{
	if (obj.id == 4)
		return (f_ratio_pl(obj, lgt, c));
	if (obj.id == 5)
		return (f_ratio_sp(obj, lgt, c));
	if (obj.id == 6)
		return (f_ratio_sq(obj, lgt, c));
	if (obj.id == 7)
		return (f_ratio_cy(obj, lgt, c));
	if (obj.id == 8)
		return (f_ratio_tr(obj, lgt, c));
	return (0);
}

t_vec	get_n(t_vec u, t_vec op, t_obj obj, double t)
{
	t_vec	n;

	n.x = obj.x - (((t_cy *)(obj.ptr))->x + (dot_p(op, u) > 0 ?
	(t * u.x) : -(t * u.x)));
	n.y = obj.y - (((t_cy *)(obj.ptr))->y + (dot_p(op, u) > 0 ?
	(t * u.y) : -(t * u.y)));
	n.z = obj.z - (((t_cy *)(obj.ptr))->z + (dot_p(op, u) > 0 ?
	(t * u.z) : -(t * u.z)));
	normalize(&n);
	return (n);
}

t_vec	get_right_n(t_vec n, t_cam *c, t_obj obj)
{
	t_vec	c_vec;

	c_vec.x = c->x - obj.x;
	c_vec.y = c->y - obj.y;
	c_vec.z = c->z - obj.z;
	if (dot_p(n, c_vec) < 0)
	{
		n.x = -n.x;
		n.y = -n.y;
		n.z = -n.z;
	}
	return (n);
}

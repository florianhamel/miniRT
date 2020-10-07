/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianhamel <florianhamel@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 11:12:14 by florianhame       #+#    #+#             */
/*   Updated: 2020/10/06 19:01:10 by florianhame      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

t_mtx4	mtx4_world(t_data *data, t_vec film)
{
	t_mtx4	m;
	t_vec	e;

	m.c.x = data->c->x;
	m.c.y = data->c->y;
	m.c.z = data->c->z;
	m.f.x = data->c->x - film.x;
	m.f.y = data->c->y - film.y;
	m.f.z = data->c->z - film.z;
	normalize(&(m.f));
	if (data->c->vec_x == 0 && fabs(data->c->vec_y) == 1 && data->c->vec_z == 0)
	{
		e.x = 0;
		e.y = 0;
		e.z = -1;
	}
	else
	{
		e.x = 0;
		e.y = 1;
		e.z = 0;
	}
	m.r = cross_p(e, m.f);
	m.u = cross_p(m.f, m.r);
	return (m);
}

t_vec	mtx4_p(t_mtx4 m, t_vec p)
{
	t_vec	pix;

	pix.x = m.c.x + (p.z * m.f.x) + (p.y * m.u.x) + (p.x * m.r.x);
	pix.y = m.c.y + (p.z * m.f.y) + (p.y * m.u.y) + (p.x * m.r.y);
	pix.z = m.c.z + (p.z * m.f.z) + (p.y * m.u.z) + (p.x * m.r.z);
	return (pix);
}

int	sl_res_x(t_data *data)
{
	int	new_res;

	new_res = data->res->x;
	if (data->res->x % 64 != 0)
		new_res = new_res - (new_res % 64) + 64;
	return (new_res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   facing_ratio2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianhamel <florianhamel@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 12:17:33 by florianhame       #+#    #+#             */
/*   Updated: 2020/05/26 12:34:28 by florianhame      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

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
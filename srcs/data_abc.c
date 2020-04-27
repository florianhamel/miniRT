/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_abc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianhamel <florianhamel@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 16:40:39 by florianhame       #+#    #+#             */
/*   Updated: 2020/04/25 22:41:33 by florianhame      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	get_abc_amb(t_amb *obj, char *line)
{
	obj->r = get_abc(0, line);
	obj->g = get_abc(1, line);
	obj->b = get_abc(2, line);
}

void	get_abc_cam(int type, t_cam *obj, char *line)
{
	if (type == 0)
	{
		obj->x = get_abc(0, line);
		obj->y = get_abc(1, line);
		obj->z = get_abc(2, line);
	}
	if (type == 1)
	{
		obj->vec_x = get_abc(0, line);
		obj->vec_y = get_abc(1, line);
		obj->vec_z = get_abc(2, line);
	}
}

void	get_abc_lgt(int type, t_lgt *obj, char *line)
{
	if (type == 0)
	{
		obj->x = get_abc(0, line);
		obj->y = get_abc(1, line);
		obj->z = get_abc(2, line);
	}
	if (type == 2)
	{
		obj->r = get_abc(0, line);
		obj->g = get_abc(1, line);
		obj->b = get_abc(2, line);
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_abc2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianhamel <florianhamel@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 16:41:24 by florianhame       #+#    #+#             */
/*   Updated: 2020/04/26 00:19:56 by florianhame      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"
#include "ft_printf.h"

void	get_abc_pl(int type, t_pl *obj, char *line)
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
	if (type == 2)
	{
		obj->r = get_abc(0, line);
		obj->g = get_abc(1, line);
		obj->b = get_abc(2, line);
	}
}

void	get_abc_sp(int type, t_sp *obj, char *line)
{
	if (type == 0)
	{
		// ft_printf("test: %lf\n", get_abc(0, line));
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

void	get_abc_sq(int type, t_sq *obj, char *line)
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
	if (type == 2)
	{
		obj->r = get_abc(0, line);
		obj->g = get_abc(1, line);
		obj->b = get_abc(2, line);
	}
}

void	get_abc_cy(int type, t_cy *obj, char *line)
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
	if (type == 2)
	{
		obj->r = get_abc(0, line);
		obj->g = get_abc(1, line);
		obj->b = get_abc(2, line);
	}
}

void	get_abc_tr(int type, t_tr *obj, char *line)
{
	if (type == 2)
	{
		obj->r = get_abc(0, line);
		obj->g = get_abc(1, line);
		obj->b = get_abc(2, line);
	}
	if (type == 3)
	{
		obj->x_a = get_abc(0, line);
		obj->y_a = get_abc(1, line);
		obj->z_a = get_abc(2, line);
	}
	if (type == 4)
	{
		obj->x_b = get_abc(0, line);
		obj->y_b = get_abc(1, line);
		obj->z_b = get_abc(2, line);
	}
	if (type == 5)
	{
		obj->x_c = get_abc(0, line);
		obj->y_c = get_abc(1, line);
		obj->z_c = get_abc(2, line);
	}
}
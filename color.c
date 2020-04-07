/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianhamel <florianhamel@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 22:27:04 by florianhame       #+#    #+#             */
/*   Updated: 2020/04/07 23:06:06 by florianhame      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"
#include <stdio.h>

int	color_pl(t_obj obj, double ratio)
{
	int	color;
	int	r;
	int	g;
	int	b;

	color = 0;
	r = ((t_pl *)(obj.ptr))->r * ratio;
	g = ((t_pl *)(obj.ptr))->g * ratio;
	b = ((t_pl *)(obj.ptr))->b * ratio;
	color += ((r / 16) * pow(16, 5)) + ((r % 16) * pow(16, 4));
	color += ((g / 16) * pow(16, 3)) + ((g % 16) * pow(16, 2));
	color += ((b / 16) * pow(16, 1)) + ((b % 16) * pow(16, 0));
	return (color);
}

int	color_sp(t_obj obj, double ratio)
{
	int	color;
	int	r;
	int	g;
	int	b;

	color = 0;
	r = ((t_sp *)(obj.ptr))->r * ratio;
	g = ((t_sp *)(obj.ptr))->g * ratio;
	b = ((t_sp *)(obj.ptr))->b * ratio;
	color += ((r / 16) * pow(16, 5)) + ((r % 16) * pow(16, 4));
	color += ((g / 16) * pow(16, 3)) + ((g % 16) * pow(16, 2));
	color += ((b / 16) * pow(16, 1)) + ((b % 16) * pow(16, 0));
	return (color);
}

int	color_sq(t_obj obj, double ratio)
{
	int	color;
	int	r;
	int	g;
	int	b;

	color = 0;
	r = ((t_sq *)(obj.ptr))->r * ratio;
	g = ((t_sq *)(obj.ptr))->g * ratio;
	b = ((t_sq *)(obj.ptr))->b * ratio;
	color += ((r / 16) * pow(16, 5)) + ((r % 16) * pow(16, 4));
	color += ((g / 16) * pow(16, 3)) + ((g % 16) * pow(16, 2));
	color += ((b / 16) * pow(16, 1)) + ((b % 16) * pow(16, 0));
	return (color);
}

int	color_cy(t_data *data, t_obj obj, double ratio)
{
	int	color;
	int	r;
	int	g;
	int	b;

	color = 0;
	r = ((t_cy *)(obj.ptr))->r * ratio;
	g = ((t_cy *)(obj.ptr))->g * ratio;
	b = ((t_cy *)(obj.ptr))->b * ratio;
	color += ((r / 16) * pow(16, 5)) + ((r % 16) * pow(16, 4));
	color += ((g / 16) * pow(16, 3)) + ((g % 16) * pow(16, 2));
	color += ((b / 16) * pow(16, 1)) + ((b % 16) * pow(16, 0));
	return (color);
}

int	color_tr(t_obj obj, double ratio)
{
	int	color;
	int	r;
	int	g;
	int	b;

	color = 0;
	r = ((t_tr *)(obj.ptr))->r * ratio;
	g = ((t_tr *)(obj.ptr))->g * ratio;
	b = ((t_tr *)(obj.ptr))->b * ratio;
	color += ((r / 16) * pow(16, 5)) + ((r % 16) * pow(16, 4));
	color += ((g / 16) * pow(16, 3)) + ((g % 16) * pow(16, 2));
	color += ((b / 16) * pow(16, 1)) + ((b % 16) * pow(16, 0));
	return (color);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianhamel <florianhamel@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 22:27:04 by florianhame       #+#    #+#             */
/*   Updated: 2020/04/26 00:52:01 by florianhame      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"
#include <stdio.h>

int	color_pl(t_data *data, t_obj obj, double ratio)
{
	int	color;
	int	r;
	int	g;
	int	b;

	color = 0;
	r = fmin(255, ((t_pl *)(obj.ptr))->r * (data->amb->power + ratio));
	g = fmin(255, ((t_pl *)(obj.ptr))->g * (data->amb->power + ratio));
	b = fmin(255, ((t_pl *)(obj.ptr))->b * (data->amb->power + ratio));
	color += ((r / 16) * pow(16, 5)) + ((r % 16) * pow(16, 4));
	color += ((g / 16) * pow(16, 3)) + ((g % 16) * pow(16, 2));
	color += ((b / 16) * pow(16, 1)) + ((b % 16) * pow(16, 0));
	return (color);
}

int	color_sp(t_data *data, t_obj obj, double ratio)
{
	int		color;
	int		r;
	int		g;
	int		b;

	color = 0;
	r = fmin(255, ((t_sp *)(obj.ptr))->r * (data->amb->power + ratio));
	g = fmin(255, ((t_sp *)(obj.ptr))->g * (data->amb->power + ratio));
	b = fmin(255, ((t_sp *)(obj.ptr))->b * (data->amb->power + ratio));
	
	color += ((r / 16) * pow(16, 5)) + ((r % 16) * pow(16, 4));
	color += ((g / 16) * pow(16, 3)) + ((g % 16) * pow(16, 2));
	color += ((b / 16) * pow(16, 1)) + ((b % 16) * pow(16, 0));
	return (color);
}

int	color_sq(t_data *data, t_obj obj, double ratio)
{
	int	color;
	int	r;
	int	g;
	int	b;

	color = 0;
	r = fmin(255, ((t_sq *)(obj.ptr))->r * (data->amb->power + ratio));
	g = fmin(255, ((t_sq *)(obj.ptr))->g * (data->amb->power + ratio));
	b = fmin(255, ((t_sq *)(obj.ptr))->b * (data->amb->power + ratio));
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

	// printf("%lf\n", ratio);
	color = 0;
	r = fmin(255, ((t_cy *)(obj.ptr))->r * (data->amb->power + ratio));
	g = fmin(255, ((t_cy *)(obj.ptr))->g * (data->amb->power + ratio));
	b = fmin(255, ((t_cy *)(obj.ptr))->b * (data->amb->power + ratio));
	color += ((r / 16) * pow(16, 5)) + ((r % 16) * pow(16, 4));
	color += ((g / 16) * pow(16, 3)) + ((g % 16) * pow(16, 2));
	color += ((b / 16) * pow(16, 1)) + ((b % 16) * pow(16, 0));
	return (color);
}

int	color_tr(t_data *data, t_obj obj, double ratio)
{
	int	color;
	int	r;
	int	g;
	int	b;

	color = 0;
	r = fmin(255, ((t_tr *)(obj.ptr))->r * (data->amb->power + ratio));
	g = fmin(255, ((t_tr *)(obj.ptr))->g * (data->amb->power + ratio));
	b = fmin(255, ((t_tr *)(obj.ptr))->b * (data->amb->power + ratio));
	color += ((r / 16) * pow(16, 5)) + ((r % 16) * pow(16, 4));
	color += ((g / 16) * pow(16, 3)) + ((g % 16) * pow(16, 2));
	color += ((b / 16) * pow(16, 1)) + ((b % 16) * pow(16, 0));
	return (color);
}
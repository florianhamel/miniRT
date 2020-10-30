/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflexion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 22:27:04 by florianhame       #+#    #+#             */
/*   Updated: 2020/10/27 23:39:16 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int	color_pl(t_obj obj, double ratio, t_col col)
{
	int	color;
	int	r;
	int	g;
	int	b;

	ratio = (int)ratio;
	color = 0;
	r = fmin((((t_pl *)(obj.ptr))->r), col.r);
	g = fmin((((t_pl *)(obj.ptr))->g), col.g);
	b = fmin((((t_pl *)(obj.ptr))->b), col.b);
	color += (int)((r / 16) * pow(16, 5)) + ((r % 16) * pow(16, 4));
	color += (int)((g / 16) * pow(16, 3)) + ((g % 16) * pow(16, 2));
	color += (int)((b / 16) * pow(16, 1)) + ((b % 16) * pow(16, 0));
	return (color);
}

int	color_sp(t_obj obj, double ratio, t_col col)
{
	int		color;
	int		r;
	int		g;
	int		b;

	ratio = (int)ratio;
	color = 0;
	r = fmin((((t_sp *)(obj.ptr))->r), col.r);
	g = fmin((((t_sp *)(obj.ptr))->g), col.g);
	b = fmin((((t_sp *)(obj.ptr))->b), col.b);
	color += (int)((r / 16) * pow(16, 5)) + ((r % 16) * pow(16, 4));
	color += (int)((g / 16) * pow(16, 3)) + ((g % 16) * pow(16, 2));
	color += (int)((b / 16) * pow(16, 1)) + ((b % 16) * pow(16, 0));
	return (color);
}

int	color_sq(t_obj obj, double ratio, t_col col)
{
	int	color;
	int	r;
	int	g;
	int	b;

	ratio = (int)ratio;
	color = 0;
	r = fmin((((t_sq *)(obj.ptr))->r), col.r);
	g = fmin((((t_sq *)(obj.ptr))->g), col.g);
	b = fmin((((t_sq *)(obj.ptr))->b), col.b);
	color += (int)((r / 16) * pow(16, 5)) + ((r % 16) * pow(16, 4));
	color += (int)((g / 16) * pow(16, 3)) + ((g % 16) * pow(16, 2));
	color += (int)((b / 16) * pow(16, 1)) + ((b % 16) * pow(16, 0));
	return (color);
}

int	color_cy(t_obj obj, double ratio, t_col col)
{
	int	color;
	int	r;
	int	g;
	int	b;

	ratio = (int)ratio;
	color = 0;
	r = fmin((((t_cy *)(obj.ptr))->r), col.r);
	g = fmin((((t_cy *)(obj.ptr))->g), col.g);
	b = fmin((((t_cy *)(obj.ptr))->b), col.b);
	color += (int)((r / 16) * pow(16, 5)) + ((r % 16) * pow(16, 4));
	color += (int)((g / 16) * pow(16, 3)) + ((g % 16) * pow(16, 2));
	color += (int)((b / 16) * pow(16, 1)) + ((b % 16) * pow(16, 0));
	return (color);
}

int	color_tr(t_obj obj, double ratio, t_col col)
{
	int	color;
	int	r;
	int	g;
	int	b;

	ratio = (int)ratio;
	color = 0;
	r = fmin((((t_tr *)(obj.ptr))->r), col.r);
	g = fmin((((t_tr *)(obj.ptr))->g), col.g);
	b = fmin((((t_tr *)(obj.ptr))->b), col.b);
	color += (int)((r / 16) * pow(16, 5)) + ((r % 16) * pow(16, 4));
	color += (int)((g / 16) * pow(16, 3)) + ((g % 16) * pow(16, 2));
	color += (int)((b / 16) * pow(16, 1)) + ((b % 16) * pow(16, 0));
	return (color);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianhamel <florianhamel@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 11:16:05 by florianhame       #+#    #+#             */
/*   Updated: 2020/08/17 11:56:11 by florianhame      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	init_col(t_col *col, t_data *data)
{
	col->r = data->amb->r * data->amb->power;
	col->g = data->amb->g * data->amb->power;
	col->b = data->amb->b * data->amb->power;
	col->nb_lgts = 1;
}

double	get_len_lgt(t_obj obj, t_lgt *lgt)
{
	t_vec	lgt_vec;

	lgt_vec.x = obj.x - lgt->x;
	lgt_vec.y = obj.y - lgt->y;
	lgt_vec.z = obj.z - lgt->z;
	return (sqrt(pow(lgt_vec.x, 2) + pow(lgt_vec.y, 2) + pow(lgt_vec.z, 2)));
}

int		color_obj(t_data *data, t_obj obj)
{
	t_lgt	*lgt;
	double	ratio;
	t_col	col;
	double	len_lgt;

	lgt = data->lgt;
	ratio = 0;
	init_col(&col, data);
	while (lgt != NULL)
	{
		if (!lgt_intersection(obj, lgt, data))
		{
			len_lgt = get_len_lgt(obj, lgt);
			ratio = fmax(0, f_ratio(obj, lgt, data->c));
			col.r += lgt->r * lgt->power * ratio;
			col.g += lgt->g * lgt->power * ratio;
			col.b += lgt->b * lgt->power * ratio;
		}
		lgt = lgt->next;
	}
	return (color_reflexion(obj, ratio, col));	
}

int	color_reflexion(t_obj obj, double ratio, t_col col)
{
	int	back_color;

	// back_color = 16776960;
	back_color = 0;
	col.r = (int)fmin(255, col.r);
	col.g = (int)fmin(255, col.g);
	col.b = (int)fmin(255, col.b);
	if (obj.id == 4)
		return (color_pl(obj, ratio, col));
	if (obj.id == 5)
		return (color_sp(obj, ratio, col));
	if (obj.id == 6)
		return (color_sq(obj, ratio, col));
	if (obj.id == 7)
		return (color_cy(obj, ratio, col));
	if (obj.id == 8)
		return (color_tr(obj, ratio, col));
	return (back_color);
}

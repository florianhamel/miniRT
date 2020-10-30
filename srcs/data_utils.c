/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/28 20:23:19 by florianhame       #+#    #+#             */
/*   Updated: 2020/10/28 10:38:52 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"
#include "ft_printf.h"

double	floatoi(char *line)
{
	double	nb;
	double	div;
	int		i;

	nb = (double)ft_atoi(line);
	div = 0;
	i = 0;
	if (nb < 0)
		nb = -nb;
	while (('0' <= line[i] && line[i] <= '9') || line[i] == '-')
		i++;
	if (line[i++] == '.')
	{
		div = (double)pow(10, nb_len(&line[i]));
		nb += (double)ft_atoi(&line[i]) / (double)div;
	}
	if (line[0] == '-')
		return (-nb);
	return (nb);
}

double	get_abc(int coord, char *line)
{
	int	i;

	i = 0;
	if (coord == 1)
	{
		while (('0' <= line[i] && line[i] <= '9') || line[i] == '.' ||
		line[i] == '-')
			i++;
		i++;
	}
	else if (coord == 2)
	{
		while (('0' <= line[i] && line[i] <= '9') || line[i] == '.' ||
		line[i] == '-')
			i++;
		i++;
		while (('0' <= line[i] && line[i] <= '9') || line[i] == '.' ||
		line[i] == '-')
			i++;
		i++;
	}
	return (floatoi(&line[i]));
}

void	get_abc_obj(int id, int type, void *obj, char *line)
{
	if (id == 1)
		get_abc_amb((t_amb *)obj, line);
	if (id == 2)
		get_abc_cam(type, (t_cam *)obj, line);
	if (id == 3)
		get_abc_lgt(type, (t_lgt *)obj, line);
	if (id == 4)
		get_abc_pl(type, (t_pl *)obj, line);
	if (id == 5)
		get_abc_sp(type, (t_sp *)obj, line);
	if (id == 6)
		get_abc_sq(type, (t_sq *)obj, line);
	if (id == 7)
		get_abc_cy(type, (t_cy *)obj, line);
	if (id == 8)
		get_abc_tr(type, (t_tr *)obj, line);
}

void	obj_append(int id, void *obj, t_data *data)
{
	if (id == 2)
		cam_append((t_cam *)obj, data);
	if (id == 3)
		lgt_append((t_lgt *)obj, data);
	if (id == 4)
		pl_append((t_pl *)obj, data);
	if (id == 5)
		sp_append((t_sp *)obj, data);
	if (id == 6)
		sq_append((t_sq *)obj, data);
	if (id == 7)
		cy_append((t_cy *)obj, data);
	if (id == 8)
		tr_append((t_tr *)obj, data);
}

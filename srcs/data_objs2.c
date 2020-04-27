/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_objs2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianhamel <florianhamel@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 15:18:19 by florianhame       #+#    #+#             */
/*   Updated: 2020/04/26 00:18:44 by florianhame      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int	get_pl(t_data *data, char *line)
{
	t_pl	*pl;
	int		i;

	if (!(pl = (t_pl *)malloc(sizeof(t_pl))))
		return (-1);
	pl->id = 4;
	i = skip_ws(line);
	get_abc_obj(4, 0, pl, &line[i]);
	i += skip_coord(&line[i]);
	i += skip_ws(&line[i]);
	get_abc_obj(4, 1, pl, &line[i]);
	i += skip_coord(&line[i]);
	i += skip_ws(&line[i]);
	get_abc_obj(4, 2, pl, &line[i]);
	pl->next = NULL;
	obj_append(4, pl, data);
	return (0);
}

int	get_sp(t_data *data, char *line)
{
	t_sp	*sp;
	int		i;

	if (!(sp = (t_sp *)malloc(sizeof(t_sp))))
		return (-1);
	sp->id = 5;
	i = skip_ws(line);
	get_abc_obj(5, 0, sp, &line[i]);
	i += skip_coord(&line[i]);
	i += skip_ws(&line[i]);
	sp->diam = floatoi(&line[i]);
	i += skip_float(&line[i]);
	i += skip_ws(&line[i]);
	get_abc_obj(5, 2, sp, &line[i]);
	sp->next = NULL;
	obj_append(5, sp, data);
	return (0);
}

int	get_sq(t_data *data, char *line)
{
	t_sq	*sq;
	int		i;

	if (!(sq = (t_sq *)malloc(sizeof(t_sq))))
		return (-1);
	sq->id = 6;
	i = skip_ws(line);
	get_abc_obj(6, 0, sq, &line[i]);
	i += skip_coord(&line[i]);
	i += skip_ws(&line[i]);
	get_abc_obj(6, 1, sq, &line[i]);
	i += skip_coord(&line[i]);
	i += skip_ws(&line[i]);
	sq->height = floatoi(&line[i]);
	i += skip_float(&line[i]);
	i += skip_ws(&line[i]);
	get_abc_obj(6, 2, sq, &line[i]);
	sq->next = NULL;
	obj_append(6, sq, data);
	return (0);
}

int	get_cy(t_data *data, char *line)
{
	t_cy	*cy;
	int		i;

	if (!(cy = (t_cy *)malloc(sizeof(t_cy))))
		return (-1);
	cy->id = 7;
	i = skip_ws(line);
	get_abc_obj(7, 0, cy, &line[i]);
	i += skip_coord(&line[i]);
	i += skip_ws(&line[i]);
	get_abc_obj(7, 1, cy, &line[i]);
	i += skip_coord(&line[i]);
	i += skip_ws(&line[i]);
	cy->diam = floatoi(&line[i]);
	i += skip_float(&line[i]);
	i += skip_ws(&line[i]);
	cy->height = floatoi(&line[i]);
	i += skip_float(&line[i]);
	i += skip_ws(&line[i]);
	get_abc_obj(7, 2, cy, &line[i]);
	cy->next = NULL;
	obj_append(7, cy, data);
	return (0);
}

int	get_tr(t_data *data, char *line)
{
	t_tr	*tr;
	int		i;

	if (!(tr = (t_tr *)malloc(sizeof(t_tr))))
		return (-1);
	tr->id = 8;
	i = skip_ws(line);
	get_abc_obj(8, 3, tr, &line[i]);
	i += skip_coord(&line[i]);
	i += skip_ws(&line[i]);
	get_abc_obj(8, 4, tr, &line[i]);
	i += skip_coord(&line[i]);
	i += skip_ws(&line[i]);
	get_abc_obj(8, 5, tr, &line[i]);
	i += skip_coord(&line[i]);
	i += skip_ws(&line[i]);
	get_abc_obj(8, 2, tr, &line[i]);
	tr->next = NULL;
	obj_append(8, tr, data);
	return (0);
}
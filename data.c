/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianhamel <florianhamel@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/28 20:08:49 by florianhame       #+#    #+#             */
/*   Updated: 2020/04/12 17:40:16 by florianhame      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"
#include <stdio.h>

int	init_data(t_data **data)
{	
	if (!(*data = (t_data *)malloc(sizeof(t_data))))
		return (-1);
	(*data)->res = NULL;
	(*data)->amb = NULL;
	(*data)->cam = NULL;
	(*data)->lgt = NULL;
	(*data)->pl = NULL;
	(*data)->sp = NULL;
	(*data)->sq = NULL;
	(*data)->cy = NULL;
	(*data)->tr = NULL;
	return (0);
}

int	get_data(t_data *data, int type, char *line)
{
	if (type == 0 && get_res(data, &line[1]) == -1)
			return (error_function(8));
	else if (type == 1 && get_amb(data, &line[1]) == -1)
			return (error_function(8));
	else if (type == 2 && get_cam(data, &line[2]) == -1)	
			return (error_function(8));
	else if (type == 3 && get_lgt(data, &line[2]) == -1)
			return (error_function(8));
	else if (type == 4 && get_pl(data, &line[2]) == -1)
			return (error_function(8));
	else if (type == 5 && get_sp(data, &line[2]) == -1)
			return (error_function(8));	
	else if (type == 6 && get_sq(data, &line[2]) == -1)
			return (error_function(8));
	else if (type == 7 && get_cy(data, &line[2]) == -1)
			return (error_function(8));
	else if (type == 8 && get_tr(data, &line[2]) == -1)
			return (error_function(8));
	return (0);
}

int	get_res(t_data *data, char *line)
{
	t_res	*res;
	int		i;

	if (!(res = (t_res *)malloc(sizeof(t_res))))
		return (-1);
	res->id = 0;
	i = skip_ws(line);
	res->x = ft_atoi(&line[i]);
	i += skip_float(&line[i]);
	i += skip_ws(&line[i]);
	res->y = ft_atoi(&line[i]);
	data->res = res;
	return (0);
}

int	get_amb(t_data *data, char *line)
{
	t_amb	*amb;
	int		i;

	if (!(amb = (t_amb *)malloc(sizeof(t_amb))))
		return (-1);
	amb->id = 1;
	i = skip_ws(line);
	amb->power = floatoi(&line[i]);
	i += skip_float(&line[i]);
	i += skip_ws(&line[i]);
	amb->r = get_color(0, &line[i]);
	amb->g = get_color(1, &line[i]);
	amb->b = get_color(2, &line[i]);
	data->amb = amb;
	return (0);
}

int	get_cam(t_data *data, char *line)
{
	t_cam	*cam;
	t_cam	*current;
	int		i;

	if (!(cam = (t_cam *)malloc(sizeof(t_cam))))
		return (-1);
	cam->id = 2;
	i = skip_ws(line);
	cam->x = get_xyz(0, &line[i]);
	cam->y = get_xyz(1, &line[i]);
	cam->z = get_xyz(2, &line[i]);
	i += skip_coord(&line[i]);
	i += skip_ws(&line[i]);
	cam->vec_x = get_xyz(0, &line[i]);
	cam->vec_y = get_xyz(1, &line[i]);
	cam->vec_z = get_xyz(2, &line[i]);
	i += skip_coord(&line[i]);
	i += skip_ws(&line[i]);
	cam->fov = ft_atoi(&line[i]);
	cam->next = NULL;
	current = data->cam;
	if (data->cam == NULL)
		data->cam = cam;
	else
	{
		while (current->next)
			current = current->next;
		current->next = cam;
	}
	return (0);
}

int	get_lgt(t_data *data, char *line)
{
	t_lgt	*lgt;
	t_lgt	*current;
	int		i;

	if (!(lgt = (t_lgt *)malloc(sizeof(t_lgt))))
		return (-1);
	lgt->id = 3;
	i = skip_ws(line);
	lgt->x = get_xyz(0, &line[i]);
	lgt->y = get_xyz(1, &line[i]);
	lgt->z = get_xyz(2, &line[i]);
	i += skip_coord(&line[i]);
	i += skip_ws(&line[i]);
	lgt->power = floatoi(&line[i]);
	i += skip_float(&line[i]);
	i += skip_ws(&line[i]);
	lgt->r = get_color(0, &line[i]);
	lgt->g = get_color(1, &line[i]);
	lgt->b = get_color(2, &line[i]);
	lgt->next = NULL;
	current = data->lgt;
	if (!data->lgt)
		data->lgt = lgt;
	else
	{
		while (current->next)
			current = current->next;
		current->next = lgt;
	}
	return (0);
}

int	get_pl(t_data *data, char *line)
{
	t_pl	*pl;
	t_pl	*current;
	int		i;

	if (!(pl = (t_pl *)malloc(sizeof(t_pl))))
		return (-1);
	pl->id = 4;
	i = skip_ws(line);
	pl->x = get_xyz(0, &line[i]);
	pl->y = get_xyz(1, &line[i]);
	pl->z = get_xyz(2, &line[i]);
	i += skip_coord(&line[i]);
	i += skip_ws(&line[i]);
	pl->vec_x = get_xyz(0, &line[i]);
	pl->vec_y = get_xyz(1, &line[i]);
	pl->vec_z = get_xyz(2, &line[i]);
	i += skip_coord(&line[i]);
	i += skip_ws(&line[i]);
	pl->r = get_color(0, &line[i]);
	pl->g = get_color(1, &line[i]);
	pl->b = get_color(2, &line[i]);
	pl->next = NULL;
	current = data->pl;
	if (!data->pl)
		data->pl = pl;
	else
	{
		while (current->next)
			current = current->next;
		current->next = pl;
	}
	return (0);
}

int	get_sp(t_data *data, char *line)
{
	t_sp	*sp;
	t_sp	*current;
	int		i;

	if (!(sp = (t_sp *)malloc(sizeof(t_sp))))
		return (-1);
	sp->id = 5;
	i = skip_ws(line);
	sp->x = get_xyz(0, &line[i]);
	sp->y = get_xyz(1, &line[i]);
	sp->z = get_xyz(2, &line[i]);	
	i += skip_coord(&line[i]);
	i += skip_ws(&line[i]);
	sp->diam = floatoi(&line[i]);
	i += skip_float(&line[i]);
	i += skip_ws(&line[i]);
	sp->r = get_color(0, &line[i]);
	sp->g = get_color(1, &line[i]);
	sp->b = get_color(2, &line[i]);
	sp->next = NULL;
	current = data->sp;
	if (!data->sp)
		data->sp = sp;
	else
	{
		while (current->next)
			current = current->next;
		current->next = sp;
	}
	return (0);
}

int	get_sq(t_data *data, char *line)
{
	t_sq	*sq;
	t_sq	*current;
	int		i;

	if (!(sq = (t_sq *)malloc(sizeof(t_sq))))
		return (-1);
	sq->id = 6;
	i = skip_ws(line);
	sq->x = get_xyz(0, &line[i]);
	sq->y = get_xyz(1, &line[i]);
	sq->z = get_xyz(2, &line[i]);
	i += skip_coord(&line[i]);
	i += skip_ws(&line[i]);
	sq->vec_x = get_xyz(0, &line[i]);
	sq->vec_y = get_xyz(1, &line[i]);
	sq->vec_z = get_xyz(2, &line[i]);
	i += skip_coord(&line[i]);
	i += skip_ws(&line[i]);
	sq->height = floatoi(&line[i]);
	i += skip_float(&line[i]);
	i += skip_ws(&line[i]);
	sq->r = get_color(0, &line[i]);
	sq->g = get_color(1, &line[i]);
	sq->b = get_color(2, &line[i]);
	sq->next = NULL;
	current = data->sq;
	if (!data->sq)
		data->sq = sq;
	else
	{
		while (current->next)
			current = current->next;
		current->next = sq;
	}
	return (0);
}

int	get_cy(t_data *data, char *line)
{
	t_cy	*cy;
	t_cy	*current;
	int		i;

	if (!(cy = (t_cy *)malloc(sizeof(t_cy))))
		return (-1);
	cy->id = 7;
	i = skip_ws(line);
	cy->x = get_xyz(0, &line[i]);
	cy->y = get_xyz(1, &line[i]);
	cy->z = get_xyz(2, &line[i]);
	i += skip_coord(&line[i]);
	i += skip_ws(&line[i]);
	cy->vec_x = get_xyz(0, &line[i]);
	cy->vec_y = get_xyz(1, &line[i]);
	cy->vec_z = get_xyz(2, &line[i]);
	i += skip_coord(&line[i]);
	i += skip_ws(&line[i]);
	cy->diam = floatoi(&line[i]);
	i += skip_float(&line[i]);
	i += skip_ws(&line[i]);
	cy->height = floatoi(&line[i]);
	i += skip_float(&line[i]);
	i += skip_ws(&line[i]);
	cy->r = get_color(0, &line[i]);
	cy->g = get_color(1, &line[i]);
	cy->b = get_color(2, &line[i]);
	cy->next = NULL;
	current = data->cy;
	if (!data->cy)
		data->cy = cy;
	else
	{
		while (current->next)
			current = current->next;
		current->next = cy;
	}
	return (0);
}

int	get_tr(t_data *data, char *line)
{
	t_tr	*tr;
	t_tr	*current;
	int		i;

	if (!(tr = (t_tr *)malloc(sizeof(t_tr))))
		return (-1);
	tr->id = 8;
	i = skip_ws(line);
	tr->x_a = get_xyz(0, &line[i]);
	tr->y_a = get_xyz(1, &line[i]);
	tr->z_a = get_xyz(2, &line[i]);
	i += skip_coord(&line[i]);
	i += skip_ws(&line[i]);
	tr->x_b = get_xyz(0, &line[i]);
	tr->y_b = get_xyz(1, &line[i]);
	tr->z_b = get_xyz(2, &line[i]);
	i += skip_coord(&line[i]);
	i += skip_ws(&line[i]);
	tr->x_c = get_xyz(0, &line[i]);
	tr->y_c = get_xyz(1, &line[i]);
	tr->z_c = get_xyz(2, &line[i]);
	i += skip_coord(&line[i]);
	i += skip_ws(&line[i]);
	tr->r = get_color(0, &line[i]);
	tr->g = get_color(1, &line[i]);
	tr->b = get_color(2, &line[i]);
	tr->next = NULL;
	current = data->tr;
	if (!data->tr)
		data->tr = tr;
	else
	{
		while (current->next)
			current = current->next;
		current->next = tr;
	}
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_objs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 15:17:31 by florianhame       #+#    #+#             */
/*   Updated: 2020/11/01 12:31:33 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

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
	get_abc_obj(1, 2, amb, &line[i]);
	data->amb = amb;
	return (0);
}

int	get_cam(t_data *data, char *line)
{
	t_cam	*cam;
	int		i;

	if (!(cam = (t_cam *)malloc(sizeof(t_cam))))
		return (-1);
	cam->id = 2;
	i = skip_ws(line);
	get_abc_obj(2, 0, cam, &line[i]);
	i += skip_coord(&line[i]);
	i += skip_ws(&line[i]);
	get_abc_obj(2, 1, cam, &line[i]);
	i += skip_coord(&line[i]);
	i += skip_ws(&line[i]);
	cam->fov = ft_atoi(&line[i]);
	cam->next = NULL;
	obj_append(2, cam, data);
	return (0);
}

int	get_lgt(t_data *data, char *line)
{
	t_lgt	*lgt;
	int		i;

	if (!(lgt = (t_lgt *)malloc(sizeof(t_lgt))))
		return (-1);
	lgt->id = 3;
	i = skip_ws(line);
	get_abc_obj(3, 0, lgt, &line[i]);
	i += skip_coord(&line[i]);
	i += skip_ws(&line[i]);
	lgt->power = floatoi(&line[i]);
	i += skip_float(&line[i]);
	i += skip_ws(&line[i]);
	get_abc_obj(3, 2, lgt, &line[i]);
	lgt->next = NULL;
	obj_append(3, lgt, data);
	return (0);
}

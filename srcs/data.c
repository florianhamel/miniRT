/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianhamel <florianhamel@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/28 20:08:49 by florianhame       #+#    #+#             */
/*   Updated: 2020/10/12 12:10:37 by florianhame      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"
#include <stdio.h>

int		init_data(t_data **data)
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
	(*data)->save = 0;
	return (0);
}

void	free_data(t_data **data)
{
	free((*data)->res);
	free((*data)->amb);
	free((*data)->cam);
	free((*data)->c);
	free((*data)->lgt);
	free((*data)->pl);
	free((*data)->sp);
	free((*data)->sq);
	free((*data)->cy);
	free((*data)->tr);
}

int		get_data(t_data *data, int type, char *line)
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

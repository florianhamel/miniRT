/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_objs2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 15:59:08 by florianhame       #+#    #+#             */
/*   Updated: 2020/10/28 10:48:15 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int	check_pl(char *line)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	if (check_ws(&i, line) == -1)
		return (-1);
	if ((ret = check_coord(&line[i])) == -1)
		return (-1);
	i += ret;
	if (check_ws(&i, line) == -1)
		return (-1);
	if ((ret = check_vec(&line[i])) == -1)
		return (-1);
	i += ret;
	if (check_obj_color(i, line) == -1)
		return (-1);
	return (0);
}

int	check_sp(char *line)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	if (check_ws(&i, line) == -1)
		return (-1);
	if ((ret = check_coord(&line[i])) == -1)
		return (-1);
	i += ret;
	if (check_ws(&i, line) == -1)
		return (-1);
	if (line[i] == '-')
		return (-1);
	if ((ret = check_nb(&line[i])) == -1)
		return (-1);
	i += ret;
	if (check_obj_color(i, line) == -1)
		return (-1);
	return (0);
}

int	check_sq(char *line)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	if (check_ws(&i, line) == -1)
		return (-1);
	if ((ret = check_coord(&line[i])) == -1)
		return (-1);
	i += ret;
	if (check_ws(&i, line) == -1)
		return (-1);
	if ((ret = check_vec(&line[i])) == -1)
		return (-1);
	i += ret;
	if (check_ws(&i, line) == -1)
		return (-1);
	if (line[i] == '-')
		return (-1);
	if ((ret = check_nb(&line[i])) == -1)
		return (-1);
	i += ret;
	if (check_obj_color(i, line) == -1)
		return (-1);
	return (0);
}

int	check_cy(char *line)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	if (check_ws(&i, line) == -1)
		return (-1);
	if ((ret = check_coord(&line[i])) == -1)
		return (-1);
	i += ret;
	if (check_ws(&i, line) == -1)
		return (-1);
	if ((ret = check_vec(&line[i])) == -1)
		return (-1);
	i += ret;
	if (check_ws(&i, line) == -1)
		return (-1);
	if (line[i] == '-')
		return (-1);
	if ((ret = check_nb(&line[i])) == -1)
		return (-1);
	i += ret;
	if (check_cy_nb_color(i, line) == -1)
		return (-1);
	return (0);
}

int	check_tr(char *line)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	if (check_ws(&i, line) == -1)
		return (-1);
	if ((ret = check_coord(&line[i])) == -1)
		return (-1);
	i += ret;
	if (check_ws(&i, line) == -1)
		return (-1);
	if ((ret = check_coord(&line[i])) == -1)
		return (-1);
	i += ret;
	if (check_ws(&i, line) == -1)
		return (-1);
	if ((ret = check_coord(&line[i])) == -1)
		return (-1);
	i += ret;
	if (check_obj_color(i, line) == -1)
		return (-1);
	return (0);
}

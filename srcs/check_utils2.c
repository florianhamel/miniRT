/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianhamel <florianhamel@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 11:43:51 by florianhame       #+#    #+#             */
/*   Updated: 2020/05/25 15:26:59 by florianhame      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int	check_ws(int *i, char *line)
{
	if (line[*i] != 32 && line[*i] != 9)
		return (-1);
	while (line[*i] == 32 || line[*i] == 9)
		(*i)++;
	return (0);
}

int	check_obj_color(int i, char *line)
{
	int ret;

	ret = 0;
	if (check_ws(&i, line) == -1)
		return (-1);
	if ((ret = check_color(&line[i])) == -1)
		return (-1);
	i += ret;
	while (line[i] == 32 || line[i] == 9)
		i++;
	if (line[i] != '\0')
		return (-1);
	return (0);
}

int	check_l_ratio_color(int i, char *line)
{
	int ret;

	ret = 0;
	if (check_ws(&i, line) == -1)
		return (-1);;
	if (line[i] != '0' && line[i] != '1')
		return (-1);
	i++;
	if (line[i] == '.')
	{
		i++;
		if (line[i - 2] == '1' && line[i] != '0')
			return (-1);
		if (line[i] < '0' || '9' < line[i++])
			return (-1);
	}
	if (check_obj_color(i, line) == -1)
		return (-1);
	return (0);
}

int	check_cy_nb_color(int i, char *line)
{
	int ret;

	ret = 0;
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

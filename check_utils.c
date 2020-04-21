/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianhamel <florianhamel@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 19:13:56 by florianhame       #+#    #+#             */
/*   Updated: 2020/04/10 13:15:21 by florianhame      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"
#include <stdio.h>
#include <stdlib.h>

int	check_nb(char *line)
{
	int	i;
	
	i = 0;
	if (line[i] == '-')
		i++;
	if (line[i] < '0' || '9' < line[i])
		return (-1);
	while ('0' <= line[i] && line[i] <= '9')
		i++;
	if (line[i] == '.')
	{
		i++;
		if (line[i] < '0' || '9' < line[i])
			return (-1);
		while ('0' <= line[i] && line[i] <= '9')
			i++;
	}
	return (i);
}

int	check_coord(char *line)
{
	int	i;
	int	coord;
	int	ret;

	i = 0;
	coord = 0;
	ret = 0;
	while (coord < 3)
	{
		if ((ret = check_nb(&line[i])) == -1)
			return (-1);
		i += ret;
		if (coord != 2 && line[i++] != ',')
			return (-1);
		coord++;
	}
	return (i);
}

int	check_vec(char *line)
{
	int	i;
	int	ret;
	int vec;

	i = 0;
	ret = 0;
	vec = 0;
	while (vec < 3)
	{
		if (line[i] == '-')
			i++;
		if (line[i] < '0' || '1' < line[i++])
			return (-1);
		if (line[i] == '.')
		{
			i++;
			if (line[i - 2] == '1' && line[i] != '0')
				return (-1);
			else if (line[i] < '0' || '9' < line[i++])
				return (-1);
		}
		if (vec != 2 && line[i++] != ',')
			return (-1);
		vec++;
	}
	return (i);
}

int	check_color(char *line)
{
	int	i;
	int	col;
	int	ret;
	int nb;

	i = 0;
	col = 0;
	ret = 0;
	while (col < 3)
	{
		nb = ft_atoi(&line[i]);
		if (nb < 0 || 255 < nb)
			return (-1);
		while ('0' <= line[i] && line[i] <= '9')
			i++;
		if (col != 2 && line[i++] != ',')
			return (-1);
		col++;
	}
	return (i);
}

int	check_nl(t_test *test)
{
	if (!test->objs && !test->cams_lgts && !test->res_amb)
		return (-1);
	if (test->objs && (!test->pl || !test->sp || !test->sq ||
	!test->cy || !test->tr))
		return (-1);
	if (test->cams_lgts && (!test->cams || !test->lgts))
		return (-1);
	if (test->res_amb && (!test->res || !test->amb))
		return (-1);
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 23:50:57 by florianhame       #+#    #+#             */
/*   Updated: 2020/10/28 10:38:19 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int	nb_len(char *str)
{
	int	i;

	i = 0;
	while ('0' <= str[i] && str[i] <= '9')
		i++;
	return (i);
}

int	skip_ws(char *line)
{
	int	i;

	i = 0;
	while (line[i] == 32 || line[i] == 9)
		i++;
	return (i);
}

int	skip_float(char *line)
{
	int	i;

	i = 0;
	while (('0' <= line[i] && line[i] <= '9') || line[i] == '.' ||
	line[i] == '-')
		i++;
	return (i);
}

int	skip_coord(char *line)
{
	int	i;

	i = 0;
	while (('0' <= line[i] && line[i] <= '9') || line[i] == '.' ||
	line[i] == ',' || line[i] == '-')
		i++;
	return (i);
}

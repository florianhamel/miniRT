/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianhamel <florianhamel@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 23:50:57 by florianhame       #+#    #+#             */
/*   Updated: 2020/03/31 00:09:38 by florianhame      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

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
	while (('0' <= line[i] && line[i] <= '9') || line[i] == '.')
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


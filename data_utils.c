/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianhamel <florianhamel@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/28 20:23:19 by florianhame       #+#    #+#             */
/*   Updated: 2020/04/07 22:20:40 by florianhame      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"
#include <stdio.h>

int				nb_len(char *str)
{
	int	i;

	i = 0;
	while ('0' <= str[i] && str[i] <= '9')
		i++;
	return (i);
}

double			floatoi(char *line)
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

double			get_xyz(int coord, char *line)
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

int	get_color(int coord, char *line)
{
	int	i;

	i = 0;
	if (coord == 1)
	{
		while ('0' <= line[i] && line[i] <= '5')
			i++;
		i++;
	}
	else if (coord == 2)
	{
		while ('0' <= line[i] && line[i] <= '5')
			i++;
		i++;
		while ('0' <= line[i] && line[i] <= '5')
			i++;
		i++;
	}
	return (ft_atoi(&line[i]));
}

// unsigned int	get_color(char *line)
// {
// 	unsigned int	color;
// 	int				rgb;
// 	int				nb;
// 	int				i;

// 	color = 0;
// 	rgb = 0;
// 	i = 0;
// 	while (rgb < 3)
// 	{
// 		nb = ft_atoi(&line[i]);
// 		color += pow(16, (2 - rgb) * 2 + 1) * (nb / 16);
// 		color += pow(16, (2 - rgb) * 2) * (nb - (nb / 16 * 16));
// 		while ('0' <= line[i] && line[i] <= '5')
// 			i++;
// 		i++;
// 		rgb++;
// 	}
// 	return (color);
// }

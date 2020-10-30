/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_objs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 12:51:32 by florianhame       #+#    #+#             */
/*   Updated: 2020/10/28 10:57:46 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"
#include "ft_printf.h"

int	check_r(char *line)
{
	int i;
	int ret;

	i = 0;
	ret = 0;
	if (check_ws(&i, line) == -1)
		return (-1);
	if ((ret = check_nb(&line[i])) == -1)
		return (-1);
	i += ret;
	if (check_ws(&i, line) == -1)
		return (-1);
	if ((ret = check_nb(&line[i])) == -1)
		return (-1);
	i += ret;
	while (line[i] == 32 || line[i] == 9)
		i++;
	if (line[i] != '\0')
		return (-1);
	return (0);
}

int	check_a(char *line)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	if (check_ws(&i, line) == -1)
		return (-1);
	if ((ret = check_nb(&line[i])) == -1)
		return (-1);
	i += ret;
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

int	check_c(char *line)
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
	if (ft_atoi(&line[i]) < 0 || 180 < ft_atoi(&line[i]))
		return (-1);
	while ('0' <= line[i] && line[i] <= '9')
		i++;
	while (line[i] == 32 || line[i] == 9)
		i++;
	return (line[i] != '\0' ? -1 : 0);
}

int	check_l(char *line)
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
	if (check_l_ratio_color(i, line) == -1)
		return (-1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_objs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianhamel <florianhamel@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 12:51:32 by florianhame       #+#    #+#             */
/*   Updated: 2020/04/26 12:09:54 by florianhame      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"
#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

int	check_r(char *line)
{
	int i;
	int ret;

	i = 0;
	ret = 0;
	if (line[i] != 32 && line[i] != 9)
		return (-1);
	while (line[i] == 32 || line[i] == 9)
		i++;
	if ((ret = check_nb(&line[i])) == -1)
		return (-1);
	i += ret;
	if (line[i] != 32 && line[i] != 9)
		return (-1);
	while (line[i] == 32 || line[i] == 9)
		i++;
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
	if (line[i] != 32 && line[i] != 9)
		return (-1);
	while (line[i] == 32 || line[i] == 9)
		i++;
	if ((ret = check_nb(&line[i])) == -1)
		return (-1);
	i += ret;
	if (line[i] != 32 && line[i] != 9)
		return (-1);
	while (line[i] == 32 || line[i] == 9)
		i++;
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
	if (line[i] != 32 && line[i] != 9)
		return (-1);
	while (line[i] == 32 || line[i] == 9)
		i++;
	if ((ret = check_coord(&line[i])) == -1)
		return (-1);
	i += ret;
	if (line[i] != 32 && line[i] != 9)
		return (-1);
	while (line[i] == 32 || line[i] == 9)
		i++;
	if ((ret = check_vec(&line[i])) == -1)
		return (-1);
	i += ret;
	if (line[i] != 32 && line[i] != 9)
		return (-1);
	while (line[i] == 32 || line[i] == 9)
		i++;
	if (ft_atoi(&line[i]) < 0 || 180 < ft_atoi(&line[i]))
		return (-1);
	while ('0' <= line[i] && line[i] <= '9')
			i++;
	while (line[i] == 32 || line[i] == 9)
		i++;
	if (line[i] != '\0')
		return (-1);
	return (0);
}

int	check_l(char *line)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	if (line[i] != 32 && line[i] != 9)
		return (-1);
	while (line[i] == 32 || line[i] == 9)
		i++;
	if ((ret = check_coord(&line[i])) == -1)
		return (-1);
	i += ret;
	if (line[i] != 32 && line[i] != 9)
		return (-1);
	while (line[i] == 32 || line[i] == 9)
		i++;;
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
	if (line[i] != 32 && line[i] != 9)
		return (-1); 
	while (line[i] == 32 || line[i] == 9)
		i++;
	if ((ret = check_color(&line[i])) == -1)
		return (-1);
	i += ret;
	while (line[i] == 32 || line[i] == 9)
		i++;
	if (line[i] != '\0')
		return (-1);
	return (0);
}

int	check_pl(char *line)
{
	int	i;
	int	ret;
	
	i = 0;
	ret = 0;
	if (line[i] != 32 && line[i] != 9)
		return (-1);
	while (line[i] == 32 || line[i] == 9)
		i++;
	if ((ret = check_coord(&line[i])) == -1)
		return (-1);
	i += ret;
	if (line[i] != 32 && line[i] != 9)  
		return (-1);
	while (line[i] == 32 || line[i] == 9)
		i++;
	if ((ret = check_vec(&line[i])) == -1)
		return (-1);
	i += ret;
	if (line[i] != 32 && line[i] != 9)
		return (-1);
	while (line[i] == 32 || line[i] == 9)
		i++;
	if ((ret = check_color(&line[i])) == -1)
		return (-1);
	i += ret;
	while (line[i] == 32 || line[i] == 9)
		i++;
	if (line[i] != '\0')
		return (-1);
	return (0);
}

int	check_sp(char *line)
{
	int	i;
	int	ret;
	
	i = 0;
	ret = 0;
	if (line[i] != 32 && line[i] != 9)
		return (-1);
	while (line[i] == 32 || line[i] == 9)
		i++;
	if ((ret = check_coord(&line[i])) == -1)
		return (-1);
	i += ret;
	if (line[i] != 32 && line[i] != 9)
		return (-1);
	while (line[i] == 32 || line[i] == 9)
		i++;
	if (line[i] == '-')
		return (-1);
	if ((ret = check_nb(&line[i])) == -1)
		return (-1);
	i += ret;
	if (line[i] != 32 && line[i] != 9)
		return (-1);
	while (line[i] == 32 || line[i] == 9)
		i++;
	if ((ret = check_color(&line[i])) == -1)
		return (-1);
	i += ret;
	while (line[i] == 32 || line[i] == 9)
		i++;
	if (line[i] != '\0')
		return (-1);
	return (0);
}


int	check_sq(char *line)
{
	int	i;
	int	ret;
	
	i = 0;
	ret = 0;
	if (line[i] != 32 && line[i] != 9)
		return (-1);
	while (line[i] == 32 || line[i] == 9)
		i++;
	if ((ret = check_coord(&line[i])) == -1)
		return (-1);
	i += ret;
	if (line[i] != 32 && line[i] != 9)
		return (-1);
	while (line[i] == 32 || line[i] == 9)
		i++;
	if ((ret = check_vec(&line[i])) == -1)
		return (-1);
	i += ret;
	if (line[i] != 32 && line[i] != 9)
		return (-1);
	while (line[i] == 32 || line[i] == 9)
		i++;
	if (line[i] == '-')
		return (-1);
	if ((ret = check_nb(&line[i])) == -1)
		return (-1);
	i += ret;
	if (line[i] != 32 && line[i] != 9)
		return (-1);
	while (line[i] == 32 || line[i] == 9)
		i++;
	if ((ret = check_color(&line[i])) == -1)
		return (-1);
	i += ret;
	while (line[i] == 32 || line[i] == 9)
		i++;
	if (line[i] != '\0')
		return (-1);
	return (0);
}

int	check_cy(char *line)
{
	int	i;
	int	ret;
	
	i = 0;
	ret = 0;
	if (line[i] != 32 && line[i] != 9)
		return (-1);
	while (line[i] == 32 || line[i] == 9)
		i++;
	if ((ret = check_coord(&line[i])) == -1)
		return (-1);
	i += ret;
	if (line[i] != 32 && line[i] != 9)
		return (-1);
	while (line[i] == 32 || line[i] == 9)
		i++;
	if ((ret = check_vec(&line[i])) == -1)
		return (-1);
	i += ret;
	if (line[i] != 32 && line[i] != 9)
		return (-1);
	while (line[i] == 32 || line[i] == 9)
		i++;
	if (line[i] == '-')
		return (-1);
	if ((ret = check_nb(&line[i])) == -1)
		return (-1);
	i += ret;
	if (line[i] != 32 && line[i] != 9)
		return (-1);
	while (line[i] == 32 || line[i] == 9)
		i++;
	if (line[i] == '-')
		return (-1);
	if ((ret = check_nb(&line[i])) == -1)
		return (-1);
	i += ret;
	if (line[i] != 32 && line[i] != 9)
		return (-1);
	while (line[i] == 32 || line[i] == 9)
		i++;
	if ((ret = check_color(&line[i])) == -1)
		return (-1);
	i += ret;
	while (line[i] == 32 || line[i] == 9)
		i++;
	if (line[i] != '\0')
		return (-1);
	return (0);
}

int	check_tr(char *line)
{
	int	i;
	int	ret;
	
	i = 0;
	ret = 0;
	if (line[i] != 32 && line[i] != 9)
		return (-1);
	while (line[i] == 32 || line[i] == 9)
		i++;
	if ((ret = check_coord(&line[i])) == -1)
		return (-1);
	i += ret;
	if (line[i] != 32 && line[i] != 9)
		return (-1);
	while (line[i] == 32 || line[i] == 9)
		i++;
	if ((ret = check_coord(&line[i])) == -1)
		return (-1);
	i += ret;
	if (line[i] != 32 && line[i] != 9)
		return (-1);
	while (line[i] == 32 || line[i] == 9)
		i++;
	if ((ret = check_coord(&line[i])) == -1)
		return (-1);
	i += ret;
	if (line[i] != 32 && line[i] != 9)
		return (-1);
	while (line[i] == 32 || line[i] == 9)
		i++;
	if ((ret = check_color(&line[i])) == -1)
		return (-1);
	i += ret;
	while (line[i] == 32 || line[i] == 9)
		i++;
	if (line[i] != '\0')
		return (-1);
	return (0);
}
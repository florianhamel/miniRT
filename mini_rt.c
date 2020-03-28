/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianhamel <florianhamel@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/28 17:54:37 by florianhame       #+#    #+#             */
/*   Updated: 2020/03/28 19:47:12 by florianhame      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"
#include <fcntl.h>
#include <stdio.h>

int	mini_rt(char *file)
{
	int		fd;
	t_data	*data;

	fd = open("test.rt", O_RDONLY);
	if (init_data(&data) == -1)
		return (error_function(7));
	if (parsing(fd, data) == -1)
		return (-1);
	close(fd);
}

int	init_data(t_data **data)
{	
	if (!(*data = (t_data *)malloc(sizeof(t_data))))
		return (-1);
	(*data)->r = NULL;
	(*data)->a = NULL;
	(*data)->cams = NULL;
	(*data)->lgts = NULL;
	(*data)->objs = NULL;
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianhamel <florianhamel@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/28 17:54:37 by florianhame       #+#    #+#             */
/*   Updated: 2020/04/14 00:21:54 by florianhame      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"
#include <fcntl.h>
#include <unistd.h>
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
	// printf("height = %lf\n", data->cy->height);
	// printf("res x = %d\n", data->res->x);
	close(fd);
	return (0);
}

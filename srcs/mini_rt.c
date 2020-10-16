/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianhamel <florianhamel@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/28 17:54:37 by florianhame       #+#    #+#             */
/*   Updated: 2020/10/12 12:20:36 by florianhame      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	if (ac == 1)
		exit(EXIT_FAILURE);
	return (0);
}

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
	return (0);
}

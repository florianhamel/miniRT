/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 15:19:39 by fhamel            #+#    #+#             */
/*   Updated: 2020/03/10 15:24:20 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int ac, char **av)
{
	if (ac == 2)
		mini_rt(av[1]);
	else
		ft_printf("Please select a file with \".rt\" extention.");
	return (0);
}

int	mini_rt(char *file)
{
	int		fd;
	t_data	*data;

	fd = open("./file", O_RDONLY);
	init_data(data);
	if (parsing(fd, data) == -1)
		return (-1);
	close(fd);
}

void	init_data(t_data *data)
{
	data->R = NULL;
	data->A = NULL;
	data->cameras = NULL;
	data->lights = NULL;
	data->objects = NULL;
}

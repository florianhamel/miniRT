/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 15:19:39 by fhamel            #+#    #+#             */
/*   Updated: 2020/11/05 16:52:20 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int		check_save_opt(char **opt)
{
	int		i;
	char	*str;

	i = 0;
	str = "-save";
	while (opt[2][i] != '\0')
	{
		if (str[i] != opt[2][i])
			return (-1);
		i++;
	}
	return (0);
}

void	params_checker(int ac, char **av, t_data *data)
{
	int		i;

	i = 0;
	if (ac == 1)
		error_file_function(10);
	else if (ac == 2 || ac == 3)
	{
		if (ac == 3 && check_save_opt(av) == -1)
			error_file_function(12);
		else if (ac == 3)
			data->save = 1;
		if (ac == 2)
		{
			if (ft_strlen(av[1]) < 4)
				error_file_function(14);
			while (av[1][i])
				i++;
			if (av[1][i - 3] != '.' || av[1][i - 2] != 'r' ||
			av[1][i - 1] != 't')
				error_file_function(14);
		}
	}
	else
		error_file_function(11);
}

void	mini_rt(int ac, char **av)
{
	t_data	*data;
	int		fd;

	init_data(&data);
	params_checker(ac, av, data);
	if ((fd = open(av[1], O_RDONLY)) == -1)
		error_file_function(13);
	if (rt_file(fd, data) == -1)
		error_file_function(9);
	if (ray_tracer(data) == -1)
		error_file_function(9);
}

int		main(int ac, char **av)
{
	mini_rt(ac, av);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianhamel <florianhamel@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 15:19:39 by fhamel            #+#    #+#             */
/*   Updated: 2020/10/25 13:47:04 by florianhame      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"
#include <errno.h>
#include <string.h>

int	check_save_opt(char **opt)
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

int main(int ac, char **av)
{
	t_data	*data;
	int		fd;

	init_data(&data);
	if (ac == 1)
		error_function(10);
	else if (2 <= ac && ac <= 3)
	{
		if (ac == 3 && check_save_opt(av) == -1)
			error_function(12);
		else if (ac == 3)
			data->save = 1;
		if ((fd = open(av[1], O_RDONLY)) == -1)
			error_function(13);
		if (rt_file(fd, data) == -1)
			error_function(9);
		if (ray_tracer(data) == -1)
			error_function(9);
	}
	else
		error_function(11);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianhamel <florianhamel@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 15:19:39 by fhamel            #+#    #+#             */
/*   Updated: 2020/10/08 11:00:16 by florianhame      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

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
	if (2 <= ac && ac <= 3)
	{
		if (ac == 3 && check_save_opt(av) == -1)
			return (-1);
		else if (ac == 3)
			data->save = 1;
		fd = open(av[1], O_RDONLY);
		if (rt_file(fd, data) == -1)
			return (-1);
		if (ray_tracer(data) == -1)
			return (error_function(9));
	}
	return (0);
}

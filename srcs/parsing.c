/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianhamel <florianhamel@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 14:02:01 by florianhame       #+#    #+#             */
/*   Updated: 2020/04/25 23:43:08 by florianhame      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"
#include <stdio.h>

int	rt_file(int fd, t_data *data)
{
	char	*line;
	int		id;
	int		ret;

	line = NULL;
	id = -1;
	while ((ret = get_next_line(fd, &line)) > -1)
	{
		if (parsing(line) == -1)
			return (-1);
		if (line [0] != '\0' && get_data(data, get_id(line), line) == -1)
			return (-1);
		if (ret == 0)
				break ;
		free(line);
		line = NULL;
	}
	set_cam(data);
	free(line);
	if (ret == -1)
		return (error_function(1));
	return (0);
}

int	get_id(char *line)
{
	if (line[0] == 'R' && line[1] == ' ')
		return (0);
	if (line[0] == 'A' && line[1] == ' ')
		return (1);
	if (line[0] == 'c' && line[1] == ' ')
		return (2);
	if (line[0] == 'l' && line[1] == ' ')
		return (3);
	if (line[0] == 'p' && line[1] == 'l')
		return (4);
	if (line[0] == 's' && line[1] == 'p')
		return (5);
	if (line[0] == 's' && line[1] == 'q')
		return (6);
	if (line[0] == 'c' && line[1] == 'y')
		return (7);
	if (line[0] == 't' && line[1] == 'r')
		return (8);
	return (error_function(2));
}

int	check_format(int id, char *line)
{
	int	ret;

	ret = -1;
	if (id == 0)
		ret = check_r(&line[1]);
	if (id == 1)
		ret = check_a(&line[1]);
	if (id == 2)
		ret = check_c(&line[1]);
	if (id == 3)
		ret = check_l(&line[1]);
	if (id == 4)
		ret = check_pl(&line[2]);
	if (id == 5)
		ret = check_sp(&line[2]);
	if (id == 6)
		ret = check_sq(&line[2]);
	if (id == 7)
		ret = check_cy(&line[2]);
	if (id == 8)
		ret = check_tr(&line[2]);
	if (ret == -1)
		return(error_function(3));
	return (0);
}

int	error_function(int err)
{
	if (err == 0)
		printf("Error 0\nPlease select a file with \".rt\" extention.\n");
	if (err == 1)
		printf("Error 1\nGNL couldn't read the file.\n");
	if (err == 2)
		printf("Error 2\nInvalid type.\n");
	if (err == 3)
		printf("Error 3\nWrong format.\n");
	if (err == 4)
		printf("Error 4\nAt least one object is missing or separated from his block.\n");
	if (err == 5)
		printf("Error 5\nToo many resolutions or ambiant lights.\n");
	if (err == 6)
		printf("Error 6\nMissplaced object.\n");
	if (err == 7)
		printf("Error 7\nA problem was encountered while initializing the data.\n");
	if (err == 8)
		printf("Error 8\nA problem was encountered while extracting the data.\n");
	if (err == 9)
		printf("Error 9\nA problem was encountered with ray tracer.\n");
	return (-1);
}
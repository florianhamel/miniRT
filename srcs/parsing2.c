/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 17:44:41 by florianhame       #+#    #+#             */
/*   Updated: 2020/11/02 17:28:58 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int		parsing(char *line, t_test *test)
{
	int		id;

	id = -1;
	if (line[0] == '\0')
	{
		if (check_test(test) == -1)
			return (-1);
	}
	else if ((id = get_id(line)) == -1)
		return (-1);
	if (line[0] != '\0')
	{
		fill_test(id, test);
		if (check_current(id, test) == -1)
			return (-1);
		if (check_format(id, line) == -1)
			return (-1);
	}
	return (0);
}

void	set_cam(t_data *data)
{
	t_cam	*cam;

	if (data->cam == NULL)
		error_file_function(15);
	else
	{
		data->c = data->cam;
		cam = data->cam;
		while (cam->next != NULL)
			cam = cam->next;
		data->cam->prev = cam;
		cam->next = data->cam;
		cam = data->cam;
	}
}

void	error_file_function(int err)
{
	if (err == 10)
		ft_printf("Error 10\nNot enough arguments.\n");
	if (err == 11)
		ft_printf("Error 11\nToo many arguments.\n");
	if (err == 12)
		ft_printf("Error 12\nIf a third argument exists, it has to be \
\"-save\".\n");
	if (err == 13)
		ft_printf("Error 13\nThe file couldn't be opened.\n");
	if (err == 14)
		ft_printf("Error 14\nInvalid file name or no \".rt\" extension.\n");
	if (err == 15)
		ft_printf("Error 15\nThis is an empty file, nice try.\n");
	exit(err);
}

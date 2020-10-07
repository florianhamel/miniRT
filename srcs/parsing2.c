/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianhamel <florianhamel@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 17:44:41 by florianhame       #+#    #+#             */
/*   Updated: 2020/08/17 12:20:29 by florianhame      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"
#include <stdio.h>

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

	data->c = data->cam;
	cam = data->cam;
	while (cam->next != NULL)
		cam = cam->next;
	data->cam->prev = cam;
	cam->next = data->cam;
	cam = data->cam;
}
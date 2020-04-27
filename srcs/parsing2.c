/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianhamel <florianhamel@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 17:44:41 by florianhame       #+#    #+#             */
/*   Updated: 2020/04/25 15:32:02 by florianhame      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"
#include <stdio.h>

int		parsing(char *line)
{
	int		id;
	t_test	test;

	id = -1;
	init_test(&test);
	if (line[0] == '\0')
	{
		if (check_test(&test) == -1)
			return (-1);
	}
	else if ((id = get_id(line)) == -1)
		return (-1);
	if (line[0] != '\0')
	{
		fill_test(id, &test);
		if (check_current(id, &test) == -1)
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
	cam->next = data->cam;
}
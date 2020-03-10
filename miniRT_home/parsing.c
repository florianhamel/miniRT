/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianhamel <florianhamel@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 14:02:01 by florianhame       #+#    #+#             */
/*   Updated: 2020/03/10 12:14:31 by florianhame      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	parsing(int fd, t_data *data)
{
	char	*line;

	line = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		if ((type = get_type(line)) == -1)
			return (-1);

		free(line);
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianhamel <florianhamel@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 17:21:16 by florianhame       #+#    #+#             */
/*   Updated: 2020/10/07 16:03:48 by florianhame      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>


int main(int ac, char **av)
{
	t_data	*data;
	int		fd;

	if (ac > 0)
	{
		init_data(&data);
		fd = open(av[1], O_RDONLY);
		if (rt_file(fd, data) == -1)
			return (-1);
			
		// printf("id = %d\n", data->lgt->id);
		// printf("x = %lf\ny = %lf\nz = %lf\n", data->lgt->x, data->lgt->y, data->lgt->z);
		// // printf("x = %lf\ny = %lf\nz = %lf\n", data->lgt->x_p1, data->lgt->y_p1, data->lgt->z_p1);
		// // printf("x = %lf\ny = %lf\nz = %lf\n", data->lgt->x_p2, data->lgt->y_p2, data->lgt->z_p2);
		// // printf("x = %lf\ny = %lf\nz = %lf\n", data->lgt->x_p3, data->lgt->y_p3, data->lgt->z_p3);
		// // printf("vec_x = %lf\nvec_y = %lf\nvec_z = %lf\n",data->lgt->vec_x, data->lgt->vec_y, data->lgt->vec_z);
		// // printf("fov = %d\n", data->lgt->fov);
		// printf("power = %lf\n", data->lgt->power);
		// // printf("diam = %lf\n", data->lgt->diam);
		// // printf("height = %lf\n", data->lgt->height);
		// printf("r = %d\ng = %d\nb = %d\n", data->lgt->r, data->lgt->g, data->lgt->b);
		if (ray_tracer(data) == -1)
			return (error_function(9));
	}
	return (0);
}

	// t_data	*data;
	// int		fd;
	// double	prime_ray[3];
	// double	film_coord[3];

	// init_data(&data);
	// fd = open("test.rt", O_RDONLY);
	// if (parsing(fd, data) == -1)
	// 	return (-1);
	// normalize_dir_cam(data);
	// get_film_coord(data, film_coord);
	// printf("film_coord x = %lf\n", film_coord[0]);
	// printf("film_coord y = %lf\n", film_coord[1]);
	// printf("film_coord z = %lf\n", film_coord[2]);
	// printf("y = %lf\n", get_sp_y(data, 2, film_coord[1]));
	// printf("x = %lf\n", get_sp_x(data, 4, film_coord[0]));
	// get_prime_ray(data, get_sp_y(data, 2, film_coord[1]), get_sp_x(data, 4, film_coord[0]), prime_ray);
	// printf("prime_ray x = %lf\n", prime_ray[0]);
	// printf("prime_ray y = %lf\n", prime_ray[1]);
	// printf("prime_ray z = %lf\n", prime_ray[2]);
	// printf("len prime_ray = %lf\n", sqrt(pow(prime_ray[0], 2) + pow(prime_ray[1], 2) + pow(prime_ray[2], 2)));

//			----------

	// t_data	*data;

	// init_data(&data);
	// get_tr(data, " 10,20,10 			10,10,20 20,10,10 		0,0,255");
	// printf("id = %d\n", data->lgt->id);
	// // printf("x = %lf\ny = %lf\nz = %lf\n", data->lgt->x_p1, data->lgt->y_p1, data->lgt->z_p1);
	// printf("x = %lf\ny = %lf\nz = %lf\n", data->lgt->x_p1, data->lgt->y_p1, data->lgt->z_p1);
	// printf("x = %lf\ny = %lf\nz = %lf\n", data->lgt->x_p2, data->lgt->y_p2, data->lgt->z_p2);
	// printf("x = %lf\ny = %lf\nz = %lf\n", data->lgt->x_p3, data->lgt->y_p3, data->lgt->z_p3);
	// // printf("vec_x = %lf\nvec_y = %lf\nvec_z = %lf\n",data->cy->vec_x, data->lgt->vec_y, data->lgt->vec_z);
	// // printf("fov = %d\n", data->lgt->fov);
	// // printf("power = %lf\n", data->lgt->power);
	// // printf("diam = %lf\n", data->lgt->diam);
	// // printf("height = %lf\n", data->lgt->height);
	// printf("color = %d\n", data->lgt->color);
	
	// printf("\n");
	
	// get_tr(data, " 10,-20,-10.4 		-10,15.4,-20.1 -42.4,0,0.0 		0,1,42");
	// printf("id = %d\n", data->lgt->next->id);
	// printf("x = %lf\ny = %lf\nz = %lf\n", data->lgt->x_p1, data->lgt->y_p1, data->lgt->z_p1);
	// printf("x = %lf\ny = %lf\nz = %lf\n", data->lgt->x_p2, data->lgt->y_p2, data->lgt->z_p2);
	// printf("x = %lf\ny = %lf\nz = %lf\n", data->lgt->x_p3, data->lgt->y_p3, data->lgt->z_p3);
	// // printf("vec_x = %lf\nvec_y = %lf\nvec_z = %lf\n",data->cy->next->vec_x, data->lgt->next->vec_y, data->lgt->next->vec_z);
	// // printf("fov = %d\n", data->lgt->next->fov);
	// // printf("power = %lf\n", data->lgt->next->power);
	// // printf("diam = %lf\n", data->lgt->next->diam);
	// // printf("height = %lf\n", data->lgt->next->height);
	// printf("color = %d\n", data->lgt->next->color);

	// mtx4 test print
	// if (y == 0 && x == 0)
	// {
	// 	printf("film x = %lf\nfilm y = %lf\nfilm z = %lf\n\n", film.x, film.y, film.z);
	// 	printf("%lf %lf %lf %d\n", m.r.x, m.r.y, m.r.z, 0);
	// 	printf("%lf %lf %lf %d\n", m.u.x, m.u.y, m.u.z, 0);
	// 	printf("%lf %lf %lf %d\n", m.f.x, m.f.y, m.f.z, 0);
	// 	printf("%lf %lf %lf %d\n", m.c.x, m.c.y, m.c.z, 1);
	// }

// The amazing function

// unsigned int	get_color(char *line)
// {
// 	unsigned int	color;
// 	int				rgb;
// 	int				nb;
// 	int				i;

// 	color = 0;
// 	rgb = 0;
// 	i = 0;
// 	while (rgb < 3)
// 	{
// 		nb = ft_atoi(&line[i]);
// 		color += pow(16, (2 - rgb) * 2 + 1) * (nb / 16);
// 		color += pow(16, (2 - rgb) * 2) * (nb - (nb / 16 * 16));
// 		while ('0' <= line[i] && line[i] <= '5')
// 			i++;
// 		i++;
// 		rgb++;
// 	}
// 	return (color);
// }
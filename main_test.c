/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianhamel <florianhamel@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 17:21:16 by florianhame       #+#    #+#             */
/*   Updated: 2020/04/03 14:27:14 by florianhame      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>


int main()
{
	t_data	*data;
	int		fd;

	init_data(&data);
	fd = open("test.rt", O_RDONLY);
	if (parsing(fd, data) == -1)
		return (-1);
	if (ray_tracer(data) == -1)
		return (error_function(9));
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
	// printf("id = %d\n", data->tr->id);
	// // printf("x = %lf\ny = %lf\nz = %lf\n", data->tr->x_p1, data->tr->y_p1, data->tr->z_p1);
	// printf("x = %lf\ny = %lf\nz = %lf\n", data->tr->x_p1, data->tr->y_p1, data->tr->z_p1);
	// printf("x = %lf\ny = %lf\nz = %lf\n", data->tr->x_p2, data->tr->y_p2, data->tr->z_p2);
	// printf("x = %lf\ny = %lf\nz = %lf\n", data->tr->x_p3, data->tr->y_p3, data->tr->z_p3);
	// // printf("vec_x = %lf\nvec_y = %lf\nvec_z = %lf\n",data->cy->vec_x, data->tr->vec_y, data->tr->vec_z);
	// // printf("fov = %d\n", data->tr->fov);
	// // printf("power = %lf\n", data->tr->power);
	// // printf("diam = %lf\n", data->tr->diam);
	// // printf("height = %lf\n", data->tr->height);
	// printf("color = %d\n", data->tr->color);
	
	// printf("\n");
	
	// get_tr(data, " 10,-20,-10.4 		-10,15.4,-20.1 -42.4,0,0.0 		0,1,42");
	// printf("id = %d\n", data->tr->next->id);
	// printf("x = %lf\ny = %lf\nz = %lf\n", data->tr->x_p1, data->tr->y_p1, data->tr->z_p1);
	// printf("x = %lf\ny = %lf\nz = %lf\n", data->tr->x_p2, data->tr->y_p2, data->tr->z_p2);
	// printf("x = %lf\ny = %lf\nz = %lf\n", data->tr->x_p3, data->tr->y_p3, data->tr->z_p3);
	// // printf("vec_x = %lf\nvec_y = %lf\nvec_z = %lf\n",data->cy->next->vec_x, data->tr->next->vec_y, data->tr->next->vec_z);
	// // printf("fov = %d\n", data->tr->next->fov);
	// // printf("power = %lf\n", data->tr->next->power);
	// // printf("diam = %lf\n", data->tr->next->diam);
	// // printf("height = %lf\n", data->tr->next->height);
	// printf("color = %d\n", data->tr->next->color);
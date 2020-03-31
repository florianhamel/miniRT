/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianhamel <florianhamel@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 17:21:16 by florianhame       #+#    #+#             */
/*   Updated: 2020/03/31 10:28:57 by florianhame      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main()
{
	t_data	*data;

	init_data(&data);
	get_sq(data, " 0,100,40				0,1.0,-1.1	30			255,0,0");
	printf("id = %d\n", data->sq->id);
	printf("x = %lf\ny = %lf\nz = %lf\n", data->sq->x, data->sq->y, data->sq->z);
	printf("vec_x = %lf\nvec_y = %lf\nvec_z = %lf\n",data->sq->vec_x, data->sq->vec_y, data->sq->vec_z);
	// printf("fov = %d\n", data->sq->fov);
	// printf("power = %lf\n", data->sq->power);
	// printf("diam = %lf\n", data->sq->diam);
	printf("height = %lf\n", data->sq->height);
	printf("color = %d\n", data->sq->color);
	
	printf("\n");
	
	get_sq(data, " -42,-100.1,0			0.9,-0.2,1.1	12.4		255,0,255");
	printf("id = %d\n", data->sq->next->id);
	printf("x = %lf\ny = %lf\nz = %lf\n", data->sq->next->x, data->sq->next->y, data->sq->next->z);
	printf("vec_x = %lf\nvec_y = %lf\nvec_z = %lf\n",data->sq->next->vec_x, data->sq->next->vec_y, data->sq->next->vec_z);
	// printf("fov = %d\n", data->sq->next->fov);
	// printf("power = %lf\n", data->sq->next->power);
	// printf("diam = %lf\n", data->sq->next->diam);
	printf("height = %lf\n", data->sq->next->height);
	printf("color = %d\n", data->sq->next->color);

	return (0);
}
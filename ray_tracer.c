/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianhamel <florianhamel@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 15:35:02 by florianhame       #+#    #+#             */
/*   Updated: 2020/04/04 00:13:13 by florianhame      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"
#include <stdio.h>

int	**init_pix(t_data *data)
{
	int	**pix;
	int	y;

	y = 0;
	if (!(pix = (int **)malloc(sizeof(int *) * (data->res->y + 1))))
		return (NULL);
	while (y < data->res->y)
	{
		if (!(pix[y] = (int *)malloc(sizeof(int) * (data->res->x + 1))))
			return (NULL);
		y++;
	}
	return (pix);
}

int	ray_tracer(t_data *data)
{
	int		y;
	int		x;
	double	film_coord[3];
	int		**pix;

	if (!(pix = init_pix(data)))
		return (-1);
	normalize(&(data->cam->vec_x), &(data->cam->vec_y),
	&(data->cam->vec_z));
	y = 0;
	while (y < data->res->y)
	{
		x = 0;
		while (x < data->res->x)
		{
			pix[y][x] = get_pix(data, y, x);
			x++;
		}
		y++;
	}
	print_scene(pix, data);
	return (0);
}

int		get_pix(t_data *data, int pix_y, int pix_x)
{
	double	prime_ray[3];
	int		pix;

	get_prime_ray(data, pix_y, pix_x, prime_ray);
	pix = scene_intersection(data, prime_ray);
	return (pix);
}

void	get_film_coord(t_data *data, double film_coord[3])
{
	film_coord[0] = data->cam->x + data->cam->vec_x;
	film_coord[1] = data->cam->y + data->cam->vec_y;
	film_coord[2] = data->cam->z + data->cam->vec_z;
}

void	normalize(double *x, double *y, double *z)
{
	double	len;

	len = sqrt(pow(*x, 2) + pow(*y, 2) + pow(*z, 2));
	*x = *x / len;
	*y = *y / len;
	*z = *z / len;
}

double	get_sp_y(t_data *data, int pix_y, double film_y)
{
	double	screen_space_y;

	if (data->res->x >= data->res->y)
	{
		screen_space_y = (1 - 2 * ((pix_y + 0.5) / (double)data->res->y)) * 
		tan((data->cam->fov * M_PI / (double)180) / 2);
	}
	else
	{
		screen_space_y = (1 - 2 * ((pix_y + 0.5) / (double)data->res->y)) *
		(data->res->y / (double)data->res->x) *
		tan((data->cam->fov * M_PI / (double)180) / 2);
	}
	return (film_y + screen_space_y);
}

double	get_sp_x(t_data *data, int pix_x, double film_x)
{
	double	screen_space_x;

	if (data->res->x >= data->res->y)
	{
		screen_space_x = (2 * ((pix_x + 0.5) / (double)data->res->x) - 1) *
		(data->res->x / (double)data->res->y) * 
		tan((data->cam->fov * M_PI / (double)180) / 2);
	}
	else
	{
		screen_space_x = (2 * ((pix_x + 0.5) / (double)data->res->x) - 1) *
		tan((data->cam->fov * M_PI / (double)180) / 2);
	}
	return (film_x + screen_space_x);
}

void	get_prime_ray(t_data *data, double pix_y, double pix_x,
		double prime_ray[3])
{
	double	y;
	double	x;
	double	film_coord[3];
	double	len;

	get_film_coord(data, film_coord);
	y = get_sp_y(data, pix_y, film_coord[1]);
	x = get_sp_x(data, pix_x, film_coord[0]);
	len = sqrt(pow((x - data->cam->x), 2) +
	pow(y - data->cam->y, 2) +
	pow(data->cam->vec_z, 2));
	prime_ray[0] = (x - data->cam->x) / len;
	prime_ray[1] = (y - data->cam->y) / len;
	prime_ray[2] = data->cam->vec_z / len;
}

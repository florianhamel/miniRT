/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianhamel <florianhamel@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 10:59:25 by florianhame       #+#    #+#             */
/*   Updated: 2020/04/06 23:43:57 by florianhame      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"
#include "minilibx_mms_20191207_beta/mlx.h"
#include <stdio.h>

int		scene_intersect(t_data *data, double prime_ray[3])
{
	double	pix;
	double	lambda;
	double	intersect[3];
	double	f_ratio;

	pix = 3984756;
	lambda = -1;
	if ((lambda = sp_intersect(data, prime_ray)) != -1)
	{
		pix = 0;
		intersect[0] = data->cam->x + (lambda * prime_ray[0]);
		intersect[1] = data->cam->y + (lambda * prime_ray[1]);
		intersect[2] = data->cam->z + (lambda * prime_ray[2]);
		f_ratio = sp_f_ratio(data, intersect);
		if (f_ratio > 0)
			pix = f_ratio * (double)657930;
	}
	return ((int)pix);
}

double	sp_intersect(t_data *data, double prime_ray[3])
{
	double	a;
	double	b;
	double	c;
	double	delta;

	a = pow(prime_ray[0], 2) + pow(prime_ray[1], 2) + pow(prime_ray[2], 2);
	b = 2 * ((data->cam->x * prime_ray[0]) + (data->cam->y * prime_ray[1]) +
	(data->cam->z * prime_ray[2])) - 2 * ((data->sp->x * prime_ray[0]) + 
	(data->sp->y * prime_ray[1]) + (data->sp->z * prime_ray[2]));
	c = (pow(data->cam->x, 2) + pow(data->cam->y, 2) + pow(data->cam->z, 2)) + 
	(-2 * ((data->cam->x * data->sp->x) + (data->cam->y * data->sp->y)) +
	(data->cam->z * data->sp->z)) +
	pow(data->sp->x, 2) + pow(data->sp->y, 2) + pow(data->sp->z, 2) - pow(data->sp->diam / 2, 2);
	delta = pow(b, 2) - (4 * a * c);
	if (delta < 0)
		return (-1);
	if (delta == 0 && (-b / (2 * a)) > 0)
		return (-b / (2 * a));
	if (((-b + sqrt(delta)) / (2 * a) < 0) && ((-b - sqrt(delta)) / (2 * a) < 0))
		return (-1);
	if ((-b + sqrt(delta)) / (2 * a) > 0 && (-b - sqrt(delta)) / (2 * a) > 0)
		return (fmin((-b + sqrt(delta)) / (2 * a), (-b - sqrt(delta) / (2 * a))));
	return (fmax((-b + sqrt(delta)) / (2 * a), (-b - sqrt(delta) / (2 * a))));
}

double	sp_f_ratio(t_data *data, double intersect[3])
{
	double	f_ratio;
	double	vec[3];
	double	normal[3];

	f_ratio = 0;
	vec[0] = intersect[0] - data->lgt->x;
	vec[1] = intersect[1] - data->lgt->y;
	vec[2] = intersect[2] - data->lgt->z;
	normalize(&vec[0], &vec[1], &vec[2]);
	normal[0] = data->sp->x - intersect[0];
	normal[1] = data->sp->y - intersect[1]; 
	normal[2] = data->sp->z - intersect[2];
	normalize(&normal[0], &normal[1], &normal[2]);
	f_ratio = dot_product(normal, vec);
	return (f_ratio);
}

void	print_scene(int **pix, t_data *data)
{
	void	*mlx_ptr;
	void	*mlx_win;
	void	*img_ptr;
	char	*img_addr;
	int		bpp;
	int		sl;
	int		end;
	int		i;

	mlx_ptr = mlx_init();
	mlx_win = mlx_new_window(mlx_ptr, data->res->x, data->res->y, "Plan");
	img_ptr = mlx_new_image(mlx_ptr, data->res->x, data->res->y);
	img_addr = mlx_get_data_addr(img_ptr, &bpp, &sl, &end);
	i = 0;
	bpp = bpp / 8;
	// printf("sl = %d\n", sl);
	// printf("bpp = %d\n", bpp);
	// printf("sl / bpp = %d\n", sl / bpp);
	while (i < (sl / bpp) * data->res->y)
	{
		*(int*)(&img_addr[i * bpp]) = pix[i / data->res->y][i % data->res->x];
		i++;
	}
	mlx_put_image_to_window(mlx_ptr, mlx_win, img_ptr, 0, 0);
	mlx_loop(mlx_ptr);
}
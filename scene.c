/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianhamel <florianhamel@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 10:59:25 by florianhame       #+#    #+#             */
/*   Updated: 2020/04/06 11:29:13 by florianhame      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"
#include "minilibx_mms_20191207_beta/mlx.h"
#include <stdio.h>

int		scene_intersect(t_data *data, double prime_ray[3])
{
	int		pix;
	double	lambda;
	double	intersec[3];
	double	lgt_coef;

	pix = 0;
	if ((lambda = sp_intersect(data, prime_ray)) != -1)
		pix = data->sp->color;
	intersec[0] = data->cam->x + (lambda * prime_ray[0]);
	intersec[1] = data->cam->y + (lambda * prime_ray[1]);
	intersec[2] = data->cam->z + (lambda * prime_ray[2]);
	lgt_coef = get_lgt_coef(data, intersec);
	return (pix * lgt_coef);
}

double	get_lgt_coef(t_data *data, double intersec[3])
{
	double	shadow_ray[3];
	double	len;

	shadow_ray[0] = data->lgt->x - intersec[0];
	shadow_ray[1] = data->lgt->y - intersec[1];
	shadow_ray[2] = data->lgt->z - intersec[2];
	len = sqrt(pow(shadow_ray[0], 2) + pow(shadow_ray[1], 2) + pow(shadow_ray[2], 2));
	normalize(&shadow_ray[0], &shadow_ray[1], &shadow_ray[2]);
	if (sp_intersection(data, shadow_ray) == -1)
		return ((data->lgt->power / pow(len, 2)) + data->amb->power);
	return (data->amb->power);
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
	c = data->cam->x + data->cam->y + data->cam->z - 2 *
	((data->cam->x * data->sp->x) + (data->cam->y * data->sp->y) +
	(data->cam->z * data->sp->z)) + pow(data->sp->x, 2) +
	pow(data->sp->y, 2) + pow(data->sp->z, 2) - pow(data->sp->diam / 2, 2);
	delta = pow(b, 2) - (4 * a * c);
	if (delta < 0)
		return (-1);
	if (delta == 0)
		return (-b / (2 * a));
	return (fmax((-b - sqrt(delta)) / (2 * a), (b - sqrt(delta) / (2 * a))));
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
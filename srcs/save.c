/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianhamel <florianhamel@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 13:43:58 by florianhame       #+#    #+#             */
/*   Updated: 2020/10/07 15:33:19 by florianhame      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt.h"

void	write_img(t_bmp bmp, t_infos *infos)
{
	int				i;
	unsigned char	alpha;

	i = (infos->sl / infos->bpp) * infos->data->res->y - 1;
	alpha = 255;
	while (i >= 0)
	{
		write(bmp.fd, &(infos->img_addr)[i * infos->bpp], 3);
		write(bmp.fd, &alpha, 1);
		i--;
	}
}

void	write_bmp(t_infos *infos)
{
	t_bmp	bmp;

	bmp.fd = open("img.bmp", O_WRONLY | O_CREAT | O_TRUNC);
	bmp.zero = 0;
	bmp.size = 54 + (4 * infos->data->res->x * infos->data->res->y);
	bmp.offset = 54;
	bmp.headersize = 40;
	bmp.planes = 1;
	bmp.bpp = 32;
	write(bmp.fd, "BM", 2);
	write(bmp.fd, &(bmp.size), sizeof(int));
	write(bmp.fd, &(bmp.zero), sizeof(int));
	write(bmp.fd, &(bmp.offset), sizeof(int));
	write(bmp.fd, &(bmp.headersize), sizeof(int));
	write(bmp.fd, &(infos->data->res->x), sizeof(int));
	write(bmp.fd, &(infos->data->res->y), sizeof(int));
	write(bmp.fd, &(bmp.planes), sizeof(short int));
	write(bmp.fd, &(bmp.bpp), sizeof(short int));
	write(bmp.fd, &(bmp.zero), sizeof(int));
	write(bmp.fd, &(bmp.zero), sizeof(int));
	write(bmp.fd, &(bmp.zero), sizeof(int));
	write(bmp.fd, &(bmp.zero), sizeof(int));
	write(bmp.fd, &(bmp.zero), sizeof(int));
	write(bmp.fd, &(bmp.zero), sizeof(int));
	write_img(bmp, infos);
}

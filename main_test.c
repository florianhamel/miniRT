/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianhamel <florianhamel@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 17:21:16 by florianhame       #+#    #+#             */
/*   Updated: 2020/03/28 18:17:16 by florianhame      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main()
{
	int fd;
	int	ret;
	t_data *data;

	ret = init_data(&data);
	printf("[ret]: %d\n", ret);
	printf("%p\n", data->r);
	printf("%p\n", data->a);
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianhamel <florianhamel@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 00:08:58 by florianhame       #+#    #+#             */
/*   Updated: 2020/04/04 00:10:38 by florianhame      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"
#include <stdio.h>

int	main()
{
	double	x = 10;
	double	y = -3;
	double	z = -5.4;
	normalize(&x, &y, &z);
	return (0);
}
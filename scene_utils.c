/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianhamel <florianhamel@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 12:17:48 by florianhame       #+#    #+#             */
/*   Updated: 2020/04/06 14:04:37 by florianhame      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"
#include <stdio.h>

double	dot_product(double normal[3], double vec[3])
{
	double	dot_product;

	dot_product = (normal[0] * vec[0]) + (normal[1] * vec[1]) + (normal[2] * vec[2]);
	return (dot_product);
}
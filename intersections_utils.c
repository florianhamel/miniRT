/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianhamel <florianhamel@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 16:57:47 by florianhame       #+#    #+#             */
/*   Updated: 2020/04/07 19:10:06 by florianhame      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"
#include <stdio.h>

double	get_root(double a, double b, double c, double delta)
{
	double	root_1;
	double	root_2;

	root_1 = -1;
	root_2 = -1;
	if (delta < 0)
		return (-1);
	if (delta == 0)
	{
		root_1 = -b / (2 * a);
		if (root_1 >= 1)
			return (root_1);
		return (-1);
	}
	root_1 = (-b - sqrt(delta)) / (2 * a);
	root_2 = (-b + sqrt(delta)) / (2 * a);
	if (root_1 >= 1 && root_2 >= 1)
		return (fmin(root_1, root_2));
	if (root_1 >= 1 || root_2 >= 1)
		return (fmax(root_1, root_2));
	return (-1);
}
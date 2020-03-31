/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianhamel <florianhamel@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 17:02:13 by florianhame       #+#    #+#             */
/*   Updated: 2020/03/29 12:25:22 by florianhame      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"
#include <stdio.h>

void	init_test(t_test *test)
{
	test->objs = 0;
	test->cams_lgts = 0;
	test->res_amb = 0;
	test->res = 0;
	test->amb = 0;
	test->cams = 0;
	test->lgts = 0;
	test->pl = 0;
	test->sp = 0;
	test->sq = 0;
	test->cy = 0;
	test->tr = 0;
}

void	fill_test(int type, t_test *test)
{
	if (type == 0 || type == 1)
		test->res_amb = 2;
	else if (type == 2 || type == 3)
		test->cams_lgts = 2;
	else
		test->objs = 2;
	if (type == 0)
		test->res++;
	else if (type == 1)
		test->amb++;
	else if (type == 2)
		test->cams++;
	else if (type == 3)
		test->lgts++;
	else if (type == 4)
		test->pl++;
	else if (type == 5)
		test->sp++;
	else if (type == 6)
		test->sq++;
	else if (type == 7)
		test->cy++;
	else
		test->tr++;
}

int		check_test(t_test *test)
{
	if (test->res_amb && (!test->res || !test->amb))
		return (error_function(4));
	if (test->cams_lgts && (!test->cams || !test->lgts))
		return (error_function(4));
	if (test->objs && (!test->pl || !test->sp || !test->sq ||
	!test->cy || !test->tr))
		return (error_function(4));
	if (test->objs == 2)
		test->objs = 1;
	if (test->cams_lgts == 2)
		test->cams_lgts = 1;
	if (test->res_amb == 2)
		test->res_amb = 1;
	return (0);
}

int		check_current(int type, t_test *test)
{
	if (test->res_amb == 2 && (type == 2 || type == 3 ||
	type == 4 || type == 5 || type == 6 || type == 7 || type == 8))
		return (error_function(5));
	if (test->res_amb == 2 && ((type == 0 && test->res > 1) || (type == 1 && test->amb > 1)))
		return (error_function(5));
	if (test->cams_lgts == 2 && (type == 0 || type == 1 ||
	type == 4 || type == 5 || type == 6 || type == 7 || type == 8))
		return (error_function(6));
	if (test->objs == 2 && (type == 0 || type == 1 ||
	type == 2 || type == 3))
		return (error_function(6));
	return (0);
}

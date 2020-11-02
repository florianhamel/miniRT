/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 17:02:13 by florianhame       #+#    #+#             */
/*   Updated: 2020/10/30 16:24:00 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

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

void	fill_test(int id, t_test *test)
{
	if (id == 0 || id == 1)
		test->res_amb = 2;
	else if (id == 2 || id == 3)
		test->cams_lgts = 2;
	else
		test->objs = 2;
	if (id == 0)
		test->res++;
	else if (id == 1)
		test->amb++;
	else if (id == 2)
		test->cams++;
	else if (id == 3)
		test->lgts++;
	else if (id == 4)
		test->pl++;
	else if (id == 5)
		test->sp++;
	else if (id == 6)
		test->sq++;
	else if (id == 7)
		test->cy++;
	else
		test->tr++;
}

int		check_test(t_test *test)
{
	if (test->res_amb && (!test->res || !test->amb))
		error_function(4);
	if (test->cams_lgts && (!test->cams || !test->lgts))
		error_function(4);
	if (test->objs && (!test->pl || !test->sp || !test->sq ||
	!test->cy || !test->tr))
		error_function(4);
	if (test->objs == 2)
		test->objs = 1;
	if (test->cams_lgts == 2)
		test->cams_lgts = 1;
	if (test->res_amb == 2)
		test->res_amb = 1;
	return (0);
}

int		check_current(int id, t_test *test)
{
	if (test->res_amb == 2 && (id == 2 || id == 3 ||
	id == 4 || id == 5 || id == 6 || id == 7 || id == 8))
		error_function(5);
	if (test->res_amb == 2 && ((id == 0 && test->res > 1) ||
	(id == 1 && test->amb > 1)))
		error_function(5);
	if (test->cams_lgts == 2 && (id == 0 || id == 1 ||
	id == 4 || id == 5 || id == 6 || id == 7 || id == 8))
		error_function(6);
	if (test->objs == 2 && (id == 0 || id == 1 ||
	id == 2 || id == 3))
		error_function(6);
	return (0);
}

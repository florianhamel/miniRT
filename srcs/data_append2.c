/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_append2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianhamel <florianhamel@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 18:12:04 by florianhame       #+#    #+#             */
/*   Updated: 2020/04/25 18:12:13 by florianhame      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	pl_append(t_pl *obj, t_data *data)
{
	t_pl	*current;

	current = data->pl;
	if (data->pl == NULL)
		data->pl = obj;
	else
	{
		while (current->next)
			current = current->next;
		current->next = obj;
	}
}

void	sp_append(t_sp *obj, t_data *data)
{
	t_sp	*current;

	current = data->sp;
	if (data->sp == NULL)
		data->sp = obj;
	else
	{
		while (current->next)
			current = current->next;
		current->next = obj;
	}
}

void	sq_append(t_sq *obj, t_data *data)
{
	t_sq	*current;

	current = data->sq;
	if (data->sq == NULL)
		data->sq = obj;
	else
	{
		while (current->next)
			current = current->next;
		current->next = obj;
	}
}

void	cy_append(t_cy *obj, t_data *data)
{
	t_cy	*current;

	current = data->cy;
	if (data->cy == NULL)
		data->cy = obj;
	else
	{
		while (current->next)
			current = current->next;
		current->next = obj;
	}
}

void	tr_append(t_tr *obj, t_data *data)
{
	t_tr	*current;

	current = data->tr;
	if (data->tr == NULL)
		data->tr = obj;
	else
	{
		while (current->next)
			current = current->next;
		current->next = obj;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_append.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 18:11:17 by florianhame       #+#    #+#             */
/*   Updated: 2020/10/28 10:42:32 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	cam_append(t_cam *obj, t_data *data)
{
	t_cam	*current;

	current = data->cam;
	if (data->cam == NULL)
		data->cam = obj;
	else
	{
		while (current->next)
			current = current->next;
		obj->prev = current;
		current->next = obj;
	}
}

void	lgt_append(t_lgt *obj, t_data *data)
{
	t_lgt	*current;

	current = data->lgt;
	if (data->lgt == NULL)
		data->lgt = obj;
	else
	{
		while (current->next)
			current = current->next;
		current->next = obj;
	}
}

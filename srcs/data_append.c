/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_append.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianhamel <florianhamel@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 18:11:17 by florianhame       #+#    #+#             */
/*   Updated: 2020/04/25 18:11:47 by florianhame      ###   ########.fr       */
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
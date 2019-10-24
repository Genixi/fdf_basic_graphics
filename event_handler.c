/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 19:34:57 by equiana           #+#    #+#             */
/*   Updated: 2019/10/24 13:29:26 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>
#include <stdlib.h>
int ft_deal_key(int key, void *param)
{
	void *tmp;

	tmp = param;
	if (key == ESC)
		exit (0);
	else if (key == ARROW_UP || key == ARROW_DOWN
			|| key == ARROW_LEFT || key == ARROW_RIGHT)
		ft_move(key, param);
	free(tmp);
	return (0);
}

void ft_move(int key, t_param *param)
{
	if (key == ARROW_UP)
		param->y_delta -= DELTA;
	else if(key == ARROW_DOWN)
		param->y_delta += DELTA;
	else if(key == ARROW_LEFT)
		param->x_delta -= DELTA;
	else
		param->x_delta += DELTA;
	ft_render_map(param);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 19:34:57 by equiana           #+#    #+#             */
/*   Updated: 2019/10/25 13:32:49 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>
int ft_deal_key(int key, void *param)
{
	t_param *tmp;

	tmp = (t_param*)param;
	if (key == ESC)
		exit (0);
	else if (key == ARROW_UP || key == ARROW_DOWN
			|| key == ARROW_LEFT || key == ARROW_RIGHT)
		ft_arrow_move(key, tmp);
	else if (key == ZOOM_IN || key == ZOOM_OUT)
		ft_zoom_move(key, tmp);
	else if (key == INCL_LESS || key == INCL_MORE)
		ft_incline_move(key, tmp);
	return (0);
}

void ft_arrow_move(int key, t_param *param)
{
	if (key == ARROW_UP)
		param->y_delta -= 10;
	else if(key == ARROW_DOWN)
		param->y_delta += 10;
	else if(key == ARROW_LEFT)
		param->x_delta -= 10;
	else
		param->x_delta += 10;
	ft_render_map(param->map, param);
}

void ft_zoom_move(int key, t_param *param)
{
	if (key == ZOOM_IN)
		param->zoom += 1;
	else if (key == ZOOM_OUT)
		param->zoom -= 1;
	if (param->zoom < 1)
		param->zoom = 1;
	ft_render_map(param->map, param);
}

void ft_incline_move(int key, t_param *param)
{
	if (key == INCL_LESS)
		param->angle -= 0.1;
	else if (key == INCL_MORE)
		param->angle += 0.1;
	if (param-> angle < 1)
		param->angle = 1;
	if (param->angle > 10)
		param->angle = 10;
	ft_render_map(param->map, param);
}

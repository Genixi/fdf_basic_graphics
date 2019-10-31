/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 19:34:57 by equiana           #+#    #+#             */
/*   Updated: 2019/10/31 17:28:59 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>

int		ft_deal_key(int key, void *param)
{
	t_param *tmp;

	tmp = (t_param*)param;
	if (key == ESC)
		exit(0);
	else if (key == ARROW_UP || key == ARROW_DOWN
			|| key == ARROW_LEFT || key == ARROW_RIGHT)
		ft_arrow_move(key, tmp);
	else if (key == ZOOM_IN || key == ZOOM_OUT)
		ft_zoom_move(key, tmp);
	else if (key == ISO || key == PAR)
		ft_project_move(key, tmp);
	else if (key == ROTATE_X1 || key == ROTATE_X2 || key == ROTATE_Y1
			|| key == ROTATE_Y2 || key == ROTATE_Z1 || key == ROTATE_Z2)
		ft_rotate_move(key, tmp);
	return (0);
}

void	ft_arrow_move(int key, t_param *param)
{
	if (key == ARROW_UP)
		param->y_delta -= 10;
	else if (key == ARROW_DOWN)
		param->y_delta += 10;
	else if (key == ARROW_LEFT)
		param->x_delta -= 10;
	else
		param->x_delta += 10;
	ft_render_map(param->map, param);
}

void	ft_zoom_move(int key, t_param *param)
{
	if (key == ZOOM_IN || key == MOUSE_UP)
		param->zoom += 1;
	else if (key == ZOOM_OUT || key == MOUSE_DOWN)
		param->zoom -= 1;
	if (param->zoom < 1)
		param->zoom = 1;
	ft_render_map(param->map, param);
}

void	ft_rotate_move(int key, t_param *param)
{
	if (key == ROTATE_X2)
		param->x_angle += 0.05;
	else if (key == ROTATE_X1)
		param->x_angle -= 0.05;
	else if (key == ROTATE_Y1)
		param->y_angle += 0.05;
	else if (key == ROTATE_Y2)
		param->y_angle -= 0.05;
	else if (key == ROTATE_Z1)
		param->z_angle += 0.05;
	else if (key == ROTATE_Z2)
		param->z_angle -= 0.05;
	ft_render_map(param->map, param);
}

void	ft_project_move(int key, t_param *param)
{
	if (key == ISO && param->proj == 'P')
	{
		param->x_angle = 0;
		param->y_angle = 0;
		param->z_angle = 0;
		param->proj = 'I';
	}
	else if (key == PAR && param->proj == 'I')
	{
		param->x_angle = 0;
		param->y_angle = 0;
		param->z_angle = 0;
		param->proj = 'P';
	}
	ft_render_map(param->map, param);
}

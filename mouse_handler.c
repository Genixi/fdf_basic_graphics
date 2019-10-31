/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 13:25:02 by equiana           #+#    #+#             */
/*   Updated: 2019/10/31 16:33:12 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>

int	ft_deal_mouse(int key, int x, int y, void *param)
{
	t_param *tmp;

	x = 0;
	y = 0;
	tmp = (t_param*)param;
	if (key == MOUSE_UP || key == MOUSE_DOWN)
		ft_zoom_move(key, tmp);
	if (key == MOUSE_LEFT)
		tmp->mouse = 1;
	return (0);
}

int	ft_mouse_click(int key, int x, int y, void *param)
{
	t_param *tmp;

	x = 0;
	y = 0;
	key = 0;
	tmp = (t_param*)param;
	tmp->mouse = 0;
	return (0);
}

int	ft_mouse_move(int x, int y, void *param)
{
	int		x_prev;
	int		y_prev;
	t_param	*tmp;

	tmp = (t_param*)param;
	x_prev = tmp->x_mouse;
	y_prev = tmp->y_mouse;
	tmp->x_mouse = x;
	tmp->y_mouse = y;
	if (tmp->mouse == 1)
	{
		tmp->y_angle += (x - x_prev) * 0.002;
		tmp->x_angle += (y - y_prev) * 0.002;
		ft_render_map(tmp->map, tmp);
	}
	return (0);
}

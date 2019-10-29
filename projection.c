/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 12:26:28 by equiana           #+#    #+#             */
/*   Updated: 2019/10/29 21:58:27 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>
#include <math.h>

void ft_iso_apply(int *x, int *y, int z)
{
	int x_prev;
	int y_prev;
	
	x_prev = *x;
	y_prev = *y;

	*x = (x_prev - y_prev) * cos(0.523599);
	*y = -z + (x_prev + y_prev) * sin(0.523599);
}

void	ft_rotate(int *x, int *y, int *z, t_param *param)
{
	int x_prev;
	int y_prev;
	int z_prev;

	y_prev = *y;
	z_prev = *z;
	*y = y_prev * cos(param->x_angle) + z_prev * sin(param->x_angle);
	*z = -y_prev * sin(param->x_angle) + z_prev * cos(param->x_angle);
	x_prev = *x;
	z_prev = *z;
	*x = x_prev * cos(param->y_angle) + z_prev * sin(param->y_angle);
	*z = -x_prev * sin(param->y_angle) + z_prev * cos(param->y_angle);
	x_prev = *x;
	y_prev = *y;
	*x = x_prev * cos(param->z_angle) - y_prev * sin(param->z_angle);
	*y = x_prev * sin(param->z_angle) + y_prev * cos(param->z_angle);
}

t_point ft_proj_apply(t_point point, t_param *param)
{
	point.x *= param->zoom;
	point.y *= param->zoom;
	point.h *= param->zoom / param->angle;
	ft_rotate(&point.x, &point.y, &point.h, param);
	if (param->proj == 'I')
		ft_iso_apply(&point.x, &point.y, point.h);
	point.x += WIDTH / 2 + param->x_delta;
	point.y += HEIGHT * 0.4 + param->y_delta;
	return(point);
}

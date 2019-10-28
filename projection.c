/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 12:26:28 by equiana           #+#    #+#             */
/*   Updated: 2019/10/28 16:53:11 by equiana          ###   ########.fr       */
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

void	ft_rotate_x(int *y, int *z, double x_angle)
{
	int y_prev;
	int z_prev;

	y_prev = *y;
	z_prev = *z;
	*y = y_prev * cos(x_angle) + z_prev * sin(x_angle);
	*z = -y_prev * sin(x_angle) + z_prev * cos(x_angle); 	
}

void ft_rotate_y(int *x, int *z, double y_angle)
{
	int x_prev;
	int z_prev;

	x_prev = *x;
	z_prev = *z;
	*x = x_prev * cos(y_angle) + z_prev * sin(y_angle);
	*z = -x_prev * sin(y_angle) + z_prev * cos(y_angle);
}

void ft_rotate_z(int *x, int *y, double z_angle)
{
	int x_prev;
	int y_prev;

	x_prev = *x;
	y_prev = *y;
	*x = x_prev * cos(z_angle) - y_prev * sin(z_angle);
	*y = x_prev * sin(z_angle) + y_prev * cos(z_angle);
}

t_point ft_proj_apply(t_point point, t_param *param)
{
	point.x *= param->zoom;
	point.y *= param->zoom;
	point.h *= param->zoom / param->angle;
	ft_rotate_x(&point.y, &point.h, param->x_angle);
	ft_rotate_y(&point.x, &point.h, param->y_angle);
	ft_rotate_z(&point.x, &point.y, param->z_angle);	
	if (param->proj == 'I')
		ft_iso_apply(&point.x, &point.y, point.h);
	point.x += WIDTH / 2 + param->x_delta;
	point.y += HEIGHT * 0.4 + param->y_delta;
	return(point);
}

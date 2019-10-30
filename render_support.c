/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_support.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 22:40:33 by equiana           #+#    #+#             */
/*   Updated: 2019/10/30 23:01:04 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>
#include <math.h>

int		get_light(int start, int end, double mix)
{
	return ((int)((1 - mix) * start + mix * end));
}

int		get_color(t_point current, t_point p0, t_point p1, t_step delta)
{
	int		r;
	int		g;
	int		b;
	int		color;
	double	mix;

	if (current.color == p1.color)
		return (current.color);
	if (delta.x > delta.y)
		mix = get_mix(p0.x, p1.x, current.x);
	else
		mix = get_mix(p0.y, p1.y, current.y);
	r = (get_light((p0.color >> 16) & 0xFF,
						(p1.color >> 16) & 0xFF, mix) << 16);
	g = (get_light((p0.color >> 8) & 0xFF, (p1.color >> 8) & 0xFF, mix) << 8);
	b = get_light(p0.color & 0xFF, p1.color & 0xFF, mix);
	color = (r | g | b);
	return (color);
}

void	ft_iso_apply(int *x, int *y, int z)
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

t_point	ft_proj_apply(t_point point, t_param *param)
{
	point.x *= param->zoom;
	point.y *= param->zoom;
	point.h *= param->zoom / param->angle;
	ft_rotate(&point.x, &point.y, &point.h, param);
	if (param->proj == 'I')
		ft_iso_apply(&point.x, &point.y, point.h);
	point.x += WIDTH / 2 + param->x_delta;
	point.y += HEIGHT * 0.4 + param->y_delta;
	return (point);
}

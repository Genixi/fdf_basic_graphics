/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 14:39:18 by equiana           #+#    #+#             */
/*   Updated: 2019/10/29 21:05:22 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int get_default_color(int h_min, int h_max, int h)
{
	double tmp;

	tmp = get_mix(h_min, h_max, h);
	if (h < 0)
		return (STEELBLUE);
	else if (h < 10)
		return (TAN);
	else if (h < 25)
		return (SANDYBROWN);
	else if (h < 50)
		return (SIENNA);
	else
		return (BROWN);
}

int get_light(int start, int end, double mix)
{
	return ((int)((1 - mix) * start + mix * end));
}

int get_color(t_point current, t_point p0, t_point p1, t_step delta)
{
	int red;
	int green;
	int blue;
	double mix;

	if (current.color == p1.color)
		return (current.color);
	if (delta.x > delta.y)
		mix = get_mix(p0.x, p1.x, current.x);
	else
		mix = get_mix(p0.y, p1.y, current.y);
	red = get_light((p0.color >> 16) & 0xFF, (p1.color >> 16) & 0xFF, mix);
	green = get_light((p0.color >> 8) & 0xFF, (p1.color >> 8) & 0xFF, mix);
	blue = get_light(p0.color & 0xFF, p1.color & 0xFF, mix);
	return ((red << 16) | (green << 8) | blue);
}

double get_mix(int start, int end, int current)
{
	double place;
	double distance;

	place = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (place / distance));
}

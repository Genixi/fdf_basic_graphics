/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 12:26:28 by equiana           #+#    #+#             */
/*   Updated: 2019/10/26 16:51:18 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>
#include <math.h>

void ft_iso(double *x, double *y, double z)
{
	double x_prev;
	double y_prev;
	
	x_prev = *x;
	y_prev = *y;

	*x = (x_prev - y_prev) * cos(0.523599);
	*y = -z + (x_prev + y_prev) * sin(0.523599);
}

void ft_iso_apply(t_list **lst)
{
	t_list *tmp;
	t_point *point;

	tmp = *lst;
	while(tmp)
	{
		point = (t_point*)(tmp->content);
		ft_iso(&(point->x), &(point->y), point->h); 
		tmp = tmp->next;
	}
}

void ft_par(double *x, double *y, double z)
{
	int x_prev;
	int y_prev;

	x_prev = *x;
	y_prev = *y;

	*x = (x_prev * cos(0.523599) + (y_prev + z) / sin(0.523599)) / 2;
	*y = (-x_prev * cos(0.523599) + (y_prev + z) / sin(0.523599)) / 2;
} 

void ft_par_apply(t_list **lst)
{
	t_list *tmp;
	t_point *point;

	tmp = *lst;
	while(tmp)
	{
		point = (t_point*)(tmp->content);
		ft_par(&(point->x), &(point->y), point->h);
		tmp = tmp->next;
	}
}

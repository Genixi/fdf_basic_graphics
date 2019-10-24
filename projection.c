/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 12:26:28 by equiana           #+#    #+#             */
/*   Updated: 2019/10/24 13:44:50 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>
#include <math.h>

void ft_iso(int *x, int *y, int z)
{
	int x_prev;
	int y_prev;
	
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

void ft_parallel(t_list **lst)
{
	/*
	 * как конвертировать список испорченный изопроекцией?
	 */
	t_list *tmp;

	tmp = *lst;
}



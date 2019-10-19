/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 18:03:35 by equiana           #+#    #+#             */
/*   Updated: 2019/10/19 17:20:14 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"
#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>
void ft_bresenham(t_param *param, t_point p0, t_point p1)
{
	t_point	tmp;
	t_point step;
	int x;
	int y;
	int error;
	
	printf("start drawing\n");
	x = p0.x;
	y = p0.y;
	error = 0;
	step.x = (p0.x < p1.x) ? 1 : -1;
	step.y = (p0.y < p1.y) ? 1 : -1;
	//deltax
	tmp.x = abs(p1.x - p0.x);
	//deltay
	tmp.y = abs(p1.y - p0.y);
	//deltaerr
	tmp.h = tmp.x - tmp.y;
	while (x != p1.x || y != p1.y)
	{
		mlx_pixel_put(param->mlx_ptr, param->win_ptr, x + WIDTH / 2, (y + HEIGHT / 2) / V_ANGLE, 0x000FFFFFF);
		if ((error = tmp.h * 2) > -tmp.y)
		{
			tmp.h -= tmp.y;
			x = x + step.x;
		}
		if (error < tmp.x)
		{
			tmp.y += tmp.x;
			y = y + step.y;
		}
	}
}

void ft_render(t_list *map)
{
	t_param *param;
	t_list *tmp;
	t_point p0;
	t_point p1;

	printf("check reader 0\n");
	param = NULL;
	param->mlx_ptr = mlx_init();
	printf("check render 1\n");
	param->win_ptr = mlx_new_window(param->mlx_ptr, WIDTH, HEIGHT, "fdf");
	printf("check render 2\n");
	mlx_key_hook(param->win_ptr, ft_deal_key, (void *)0); 
	
	printf("check reader 3\n");
	tmp = map;
	while (tmp && tmp->next)
	{
		p1 = *(t_point*)(tmp->next->content);
		p0 = *(t_point*)(tmp->content);
		ft_bresenham(param, p0, p1);
		tmp = tmp->next;
	}
	
	mlx_loop(param->mlx_ptr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 18:03:35 by equiana           #+#    #+#             */
/*   Updated: 2019/10/23 17:47:40 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"
#include <mlx.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
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

void ft_bresenham(t_param *param, t_point p0, t_point p1, t_window window)
{
	t_point	tmp;
	t_point step;
	int x;
	int y;
	int error;
	int count;

	count = 0;
	x = p0.x;
	y = p0.y;
	error = 0;
	//sign
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
	//	printf("iteration: %d", count);
	//	printf(" x0: %d, y0: %d, x1: %d, y1: %d, x = %d, y = %d\n", p0.x, p0.y, p1.x, p1.y, x, y);
	//	mlx_pixel_put(param->mlx_ptr, param->win_ptr, x + WIDTH / 2, y + HEIGHT / 2, 0x000FFFFFF);
		mlx_pixel_put(param->mlx_ptr, param->win_ptr, x + window.l_delta, y + window.h_delta, 0x000FFFFFF);
		if ((error = tmp.h * 2) > -tmp.y)
		{
			tmp.h -= tmp.y;
			x = x + step.x;
		}
		if (error < tmp.x)
		{
			tmp.h += tmp.x;
			y = y + step.y;
		}
		count++;
	}
}

void ft_render(t_list *map)
{
	t_param param;
	t_window window;
	t_list *tmp;
	t_point p00;
	t_point p01;
	//указатели идущие на строчку назад
	t_list *ttmp;
	t_point p10;
	t_point p11;

	//apply iso projection
	tmp = map;
	ft_iso_apply(&map);

	//define map size
	tmp = ft_lstlast(map);
	window.n_rows = ((t_point*)(tmp->content))->line;
	window.n_cols = ((t_point*)(tmp->content))->x;
	window.l_delta = WIDTH / 2 - window.n_cols / 2;
	window.h_delta = HEIGHT / 2 - window.n_rows / 2;

	param.mlx_ptr = mlx_init();
	param.win_ptr = mlx_new_window(param.mlx_ptr, WIDTH, HEIGHT, "fdf");
	mlx_key_hook(param.win_ptr, ft_deal_key, (void *)0); 
	
	tmp = map;
	ttmp = tmp;
	//не рисует последний элемент
	//не работает если в строке 1 элемент
	while (tmp && tmp->next)
	{
		p01 = *(t_point*)(tmp->next->content);
		p00 = *(t_point*)(tmp->content);
		if (p00.line == p01.line)
			ft_bresenham(&param, p00, p01, window);
	//	if (p00.x == 0)
	//		ttmp = tmp;
	//второй указатель стоит пока первый проходит первую линию
		if (ttmp->next && p00.line != 0)
		{
			p11 = *(t_point*)(ttmp->next->content);
			p10 = *(t_point*)(ttmp->content);
			if(p11.line == p10.line)
			{
				ft_bresenham(&param, p11, p01, window);
				ft_bresenham(&param, p10, p00, window);
			}
			ttmp = ttmp->next;
		}
		tmp = tmp->next;
	}	
	mlx_loop(param.mlx_ptr);
}

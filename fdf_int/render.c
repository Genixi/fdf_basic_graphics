/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 18:03:35 by equiana           #+#    #+#             */
/*   Updated: 2019/10/26 16:38:35 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"
#include <mlx.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

void ft_render_map(t_list *map, t_param *param)
{
	t_window window;
	t_list *tmp;
	t_point p00;
	t_point p01;
	//указатели идущие на строчку назад
	t_list *ttmp;
	t_point p10;
	t_point p11;

	
	//define map size
	tmp = ft_lstlast(map);
	window.n_rows = ((t_point*)(tmp->content))->line;
	window.n_cols = ((t_point*)(tmp->content))->x;
	window.l_delta = WIDTH / 2 - window.n_cols / 2;
	window.h_delta = HEIGHT / 2 - window.n_rows / 2;

	if (param->mlx_ptr && param->win_ptr)
		mlx_clear_window((void*)(param->mlx_ptr), (void*)(param->win_ptr));
	ft_menu(param->mlx_ptr, param->win_ptr);
	tmp = map;
	ttmp = tmp;
	//не рисует последний элемент
	//не работает если в строке 1 элемент
	while (tmp && tmp->next)
	{
		p01 = *(t_point*)(tmp->next->content);
		p00 = *(t_point*)(tmp->content);
		if (p00.line == p01.line)
			ft_bresenham(param, p00, p01, window);
	//второй указатель стоит пока первый проходит первую линию
		if (ttmp->next && p00.line != 0)
		{
			p11 = *(t_point*)(ttmp->next->content);
			p10 = *(t_point*)(ttmp->content);
			if(p11.line == p10.line)
			{
				
				ft_bresenham(param, p11, p01, window);
				ft_bresenham(param, p10, p00, window);
			}
			ttmp = ttmp->next;
		}
		tmp = tmp->next;
	}	
}

void ft_bresenham(t_param *param, t_point p0, t_point p1, t_window window)
{
	t_step	tmp;
	t_step step;
	int x;
	int y;
	int error;
	int x_adj;
	int y_adj;

	x_adj = window.l_delta + param->x_delta;
	y_adj = window.h_delta / 4 + param->y_delta;
	x = p0.x * param->zoom;
	y = p0.y * param->zoom;
	error = 0;
	//sign
	step.x = ((p0.x * param->zoom < p1.x * param->zoom) ? 1 : -1);
	step.y = ((p0.y * param->zoom < p1.y * param->zoom) ? 1 : -1);
	//deltax
	tmp.x = (abs(p1.x * param->zoom - p0.x * param->zoom));
	//deltay
	tmp.y = (abs(p1.y * param->zoom - p0.y * param->zoom));
	//deltaerr
	tmp.h = tmp.x - tmp.y;
	while (x != (p1.x * param->zoom) || y != (p1.y * param->zoom))
	{
		mlx_pixel_put(param->mlx_ptr, param->win_ptr, x + x_adj, (y + y_adj) / param->angle, 0x000FFFFFF);
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
	}
}

void ft_render(t_list *map)
{
	t_param param;
	t_list *tmp;

	//iso projection by defalut
	tmp = map;
	ft_iso_apply(&map);

	param.mlx_ptr = mlx_init();
	param.win_ptr = mlx_new_window(param.mlx_ptr, WIDTH, HEIGHT, "fdf");
	param.x_delta = 0;
	param.y_delta = 0;
	param.zoom = 1;
	param.angle = 1;
	param.proj = 0;
	param.map = map;
	mlx_key_hook(param.win_ptr, ft_deal_key, (void *)(&param)); 
	ft_render_map(map, &param);
	
	mlx_loop(param.mlx_ptr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 18:03:35 by equiana           #+#    #+#             */
/*   Updated: 2019/10/31 00:12:27 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"
#include <mlx.h>
#include <math.h>

int		set_color(int h)
{
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

void	ft_render_map(t_list *map, t_param *param)
{
	t_list	*tmp;
	t_point	p01;
	t_list	*ttmp;
	t_point	p11;

	if (param->mlx_ptr && param->win_ptr)
		mlx_clear_window((void*)(param->mlx_ptr), (void*)(param->win_ptr));
	ft_menu(param->mlx_ptr, param->win_ptr);
	tmp = map;
	ttmp = tmp;
	while (tmp && tmp->next)
	{
		p01 = *(t_point*)(tmp->next->content);
		if ((*(t_point*)(tmp->content)).line == p01.line)
			ft_bresenham(param, (*(t_point*)(tmp->content)), p01);
		if (ttmp->next && (*(t_point*)(tmp->content)).line != 0)
		{
			p11 = *(t_point*)(ttmp->next->content);
			if((*(t_point*)(ttmp->content)).line == p11.line)
			{				
				ft_bresenham(param, p11, p01);
				ft_bresenham(param, (*(t_point*)(ttmp->content)), (*(t_point*)(tmp->content)));
			}
			ttmp = ttmp->next;
		}
		tmp = tmp->next;
	}	
}

void ft_bresenham(t_param *param, t_point p0, t_point p1)
{
	t_step	tmp;
	t_step step;
	t_point color_step;
	int x;
	int y;
	int error;

	p0 = ft_proj_apply(p0, param);
	p1 = ft_proj_apply(p1, param);

	color_step = p0;
	x = p0.x;
	y = p0.y;
	error = 0;
	step.x = ((p0.x < p1.x) ? 1 : -1);
	step.y = ((p0.y < p1.y) ? 1 : -1);
	tmp.x = abs(p1.x - p0.x);
	tmp.y = abs(p1.y- p0.y);
	tmp.h = tmp.x - tmp.y;
	while (x != p1.x || y != p1.y)
	{
		mlx_pixel_put(param->mlx_ptr, param->win_ptr, x, y, get_color(color_step, p0, p1, tmp));
		if ((error = tmp.h * 2) > -tmp.y)
		{
			tmp.h -= tmp.y;
			x = x + step.x;
			color_step.x = x;
		}
		if (error < tmp.x)
		{
			tmp.h += tmp.x;
			y = y + step.y;
			color_step.y = y;
		}
	}
}

void ft_render(t_list *map)
{
	t_param param;
	t_list *tmp;

	tmp = map;
	param.mlx_ptr = mlx_init();
	param.win_ptr = mlx_new_window(param.mlx_ptr, WIDTH, HEIGHT, "fdf");
	param.x_delta = 0;
	param.y_delta = 0;
	param.zoom = 1;
	param.angle = 1;
	param.proj = 'P';
	param.x_angle = 0;
	param.y_angle = 0;
	param.z_angle = 0;
	param.h_min = COLOR_MIN;
	param.h_max = COLOR_MAX;
	param.mouse = 0;
	param.x_mouse = 0;
	param.y_mouse = 0;
	param.map = map;
	mlx_hook(param.win_ptr, 2, 0, ft_deal_key, (void*)(&param));
	mlx_hook(param.win_ptr, 4, 0, ft_deal_mouse, (void*)(&param)); 
	mlx_hook(param.win_ptr, 5, 0, ft_mouse_click, (void*)(&param));
	mlx_hook(param.win_ptr, 6, 0, ft_mouse_move, (void*)(&param));
	ft_render_map(map, &param);
	mlx_loop(param.mlx_ptr);
}

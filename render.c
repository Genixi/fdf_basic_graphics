/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 18:03:35 by equiana           #+#    #+#             */
/*   Updated: 2019/10/18 20:06:37 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"
#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>
void ft_bresenham(t_point p0, t_point p1)
{
	int x0;
	int 

}

void ft_render(t_list *map)
{
	void *mlx_ptr;
	void *win_ptr;
	t_list *tmp;
	int h;
	int x;
	int y;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, WIDTH, HEIGHT, "fdf");
	mlx_key_hook(win_ptr, ft_deal_key, (void *)0); 
	
	tmp = map;
	while (tmp)
	{
		h = ((t_point*)(tmp->content))->h;
		x = ((t_point*)(tmp->content))->x;
		y = ((t_point*)(tmp->content))->y;
		mlx_pixel_put(mlx_ptr, win_ptr, x + WIDTH / 2,  (y + HEIGHT / 2) / V_ANGLE, 0x000FFFFFF);
		tmp = tmp->next;
	}
	
	mlx_loop(mlx_ptr);
}

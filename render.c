/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 18:03:35 by equiana           #+#    #+#             */
/*   Updated: 2019/10/17 21:25:09 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"
#include <mlx.h>
#include <stdio.h>
//called when one presses a key inside open window
int ft_deal_key(int key, void *param)
{
	if (key == ESC)
		exit (0);
	ft_putchar('X');
	//to handle zoom in
	//to handle amplifier
	//to handle arrow keys
	// mlx_pixel_put(mlx_ptr, win_ptr, );
	return (0);
}

void ft_render(t_list *map)
{
	void *mlx_ptr;
	void *win_ptr;
	t_list *tmp;
	int h;
	int x;
	int y;

	//OPEN WINDOW
	//connection login to the graphical server
	mlx_ptr = mlx_init();
	//open window
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "fdf");
	//managing keys, second param - pointer to function, last param not used
	mlx_key_hook(win_ptr, deal_key, (void *)0); 
	
	//DISPLAY POINTS AND LINES
	//display point
	tmp = map;
	while (tmp)
	{
		h = ((t_point*)(tmp->content))->h;
		x = ((t_point*)(tmp->content))->x;
		y = ((t_pint*)(tmp->content))->y;
		mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xFFFFFF);
		tmp = tmp->next;
	}
	
	//listen end managing vents
	mlx_loop(mlx_ptr);
}

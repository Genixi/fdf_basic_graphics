/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 11:19:47 by equiana           #+#    #+#             */
/*   Updated: 2019/10/24 12:19:08 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>

void ft_menu(void *mlx, void *win)
{
	int line;

	line = 0;
//	mlx_string_put(mlx, win, 65, line = 20, 0x000FFFFFF, "How to use");
  	mlx_string_put(mlx, win, 15, line += 35, 0x000FFFFFF, "Zoom: scroll or +/-");
	mlx_string_put(mlx, win, 15, line += 30, 0x000FFFFFF, "Move: Arrows");
	mlx_string_put(mlx, win, 15, line += 30, 0x000FFFFFF, "Flatten: </>");
	mlx_string_put(mlx, win, 15, line += 30, 0x000FFFFFF, "Rotate: Press & Move");
	mlx_string_put(mlx, win, 15, line += 30, 0x000FFFFFF, "Rotate:");
	mlx_string_put(mlx, win, 57, line += 25, 0x000FFFFFF, "X-Axis - 2/8");
	mlx_string_put(mlx, win, 57, line += 25, 0x000FFFFFF, "Y - Axis - 4/6");
	mlx_string_put(mlx, win, 57, line += 25, 0x000FFFFFF, "Z-Axis - 1(3)/7(9)");
	mlx_string_put(mlx, win, 15, line += 30, 0x000FFFFFF, "Projection");
	mlx_string_put(mlx, win, 57, line += 25, 0x000FFFFFF, "ISO: I Key");
	mlx_string_put(mlx, win, 57, line += 25, 0x000FFFFFF, "Parallel: P Key");	
}

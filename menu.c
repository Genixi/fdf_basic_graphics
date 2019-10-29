/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 11:19:47 by equiana           #+#    #+#             */
/*   Updated: 2019/10/29 21:38:42 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>

void ft_menu(void *mlx, void *win)
{
	int line;

	line = 0;
	mlx_string_put(mlx, win, 15, line += 30, 0x000FFFFFF, "Move: Arrows");
  	mlx_string_put(mlx, win, 15, line += 30, 0x000FFFFFF, "Projection: I / P");
	mlx_string_put(mlx, win, 15, line += 35, 0x000FFFFFF, "Zoom: + / - / mouse scroll");
	mlx_string_put(mlx, win, 15, line += 30, 0x000FFFFFF, "Anlge: 9 / 0");
	mlx_string_put(mlx, win, 15, line += 30, 0x000FFFFFF, "Rotate: Q / E, A / D, W / S");
	mlx_string_put(mlx, win, 15, line += 30, 0x000FFFFFF, "Projection: I / P");
}

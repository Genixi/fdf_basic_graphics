/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 20:57:03 by equiana           #+#    #+#             */
/*   Updated: 2019/10/31 00:08:07 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"
#include <mlx.h>
#include <stdio.h>
void display_lst(t_list *lst)
{
	t_list *tmp;
	int l;
	int x;
	int y;

	tmp = lst;
	while (tmp)
	{
		x = ((t_point*)(tmp->content))->x;
		y = ((t_point*)(tmp->content))->y;
		l = ((t_point*)(tmp->content))->line;
		printf("h: %d ", ((t_point*)(tmp->content))->h);
		printf("x: %d, y: %d, line: %dn", x, y, l);
		tmp = tmp->next;
	}
}

void ft_error(int type)
{
	if (type == 1)
		ft_putstr("line parsing error\n");
	else if (type == 2)
		ft_putstr("malloc error\n");
	else if(type == 3)
		ft_putstr("map reading error\n");
	else 
		ft_putstr("error\n");
	exit (0);
}

double get_mix(int start, int end, int current)
{
	double place;
	double distance;

	place = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (place / distance));
}

t_list *ft_lstlast(t_list *begin)
{
	t_list *tmp;
	
	if (!begin)
		return NULL;
	tmp = begin;
	while (tmp->next)
		tmp = tmp->next;
	return tmp;
}

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
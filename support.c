/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 20:57:03 by equiana           #+#    #+#             */
/*   Updated: 2019/10/31 17:52:25 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"
#include <mlx.h>

void	ft_error(int type)
{
	if (type == 1)
		ft_putstr("line parsing error\n");
	else if (type == 2)
		ft_putstr("malloc error\n");
	else if (type == 3)
		ft_putstr("map reading error\n");
	else
		ft_putstr("error\n");
	exit(0);
}

double	get_mix(int start, int end, int current)
{
	double	place;
	double	distance;

	place = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (place / distance));
}

t_list	*ft_lstlast(t_list *begin)
{
	t_list	*tmp;

	if (!begin)
		return (NULL);
	tmp = begin;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void	ft_menu(void *mlx, void *win)
{
	mlx_string_put(mlx, win, 10, 30, 0x000FFFFFF, "Projection: 1/2");
	mlx_string_put(mlx, win, 10, 60, 0x000FFFFFF, "Round: Q/E/A/D/W/S");
	mlx_string_put(mlx, win, 1310, 30, 0x000FFFFFF, "Zoom: +/-");
	mlx_string_put(mlx, win, 1280, 60, 0x000FFFFFF, "Move: Arrows");
	mlx_string_put(mlx, win, 1220, 90, 0x000FFFFFF, "Zoom: mouse scroll");
}

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

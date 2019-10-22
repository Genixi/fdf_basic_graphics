/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 20:57:03 by equiana           #+#    #+#             */
/*   Updated: 2019/10/22 22:05:18 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"
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
	//	ft_putnbr(((t_point*)(tmp->content))->height);
		x = ((t_point*)(tmp->content))->x;
		y = ((t_point*)(tmp->content))->y;
		l = ((t_point*)(tmp->content))->line;
		printf("h: %d ", ((t_point*)(tmp->content))->h); 
		printf("x: %d, y: %d, line: %d\n", x, y, l);
	//	ft_iso(&x, &y, DELTA);
	//	printf("iso projection x: %d, y: %d\n", x, y);
	//	ft_putchar(' ');
		tmp = tmp->next;
	}
}

void ft_error(void)
{
	ft_putstr("error\n");
	exit (0);
}

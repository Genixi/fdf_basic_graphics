/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 20:57:03 by equiana           #+#    #+#             */
/*   Updated: 2019/10/24 13:30:03 by equiana          ###   ########.fr       */
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
		x = ((t_point*)(tmp->content))->x;
		y = ((t_point*)(tmp->content))->y;
		l = ((t_point*)(tmp->content))->line;
		printf("h: %d ", ((t_point*)(tmp->content))->h); 
		printf("x: %d, y: %d, line: %d\n", x, y, l);
		tmp = tmp->next;
	}
}

void ft_error(void)
{
	ft_putstr("error\n");
	exit (0);
}

t_list *ft_lstlast(t_list *begin)
{
	t_list *tmp;
	tmp = begin;
	while (tmp->next)
		tmp = tmp->next;
	return tmp;
}

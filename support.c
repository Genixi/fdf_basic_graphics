/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 20:57:03 by equiana           #+#    #+#             */
/*   Updated: 2019/10/17 17:13:00 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"
#include <stdio.h>
void display_lst(t_list *lst)
{
	t_list *tmp;
	int i;

	i = 0;
	tmp = lst;
	while (tmp)
	{
	//	ft_putnbr(((t_point*)(tmp->content))->height);
		printf("h: %d ", ((t_point*)(tmp->content))->h); 
		printf("x: %d, y: %d\n", ((t_point*)(tmp->content))->x, ((t_point*)(tmp->content))->y);
	//	ft_putchar(' ');
		tmp = tmp->next;
		i++;
	}
}

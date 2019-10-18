/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 19:34:57 by equiana           #+#    #+#             */
/*   Updated: 2019/10/18 19:40:56 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>
#include <stdlib.h>
int ft_deal_key(int key, void *param)
{
	void *tmp;

	tmp = param;
	if (key == ESC)
		exit (0);
	ft_putchar('X');
	free(tmp);
	return (0);
}

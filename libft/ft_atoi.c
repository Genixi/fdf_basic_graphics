/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 09:48:27 by equiana           #+#    #+#             */
/*   Updated: 2019/09/14 18:05:45 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_overflow(unsigned long long int num, const char c, int flag)
{
	unsigned long long int res;
	unsigned long long int bench;

	res = num;
	bench = num;
	res = res * 10 + c - '0';
	if ((res - (c - '0')) / 10 == bench && res < 9223372036854775807)
		return (1);
	else
	{
		if (flag == 1)
			return (-1);
		else
			return (0);
	}
}

int			ft_atoi(const char *str)
{
	long					i;
	int						flag;
	unsigned long long int	num;

	flag = 1;
	num = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
		flag = -1;
	if ((str[i] == '-') || (str[i] == '+'))
		i++;
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		num = num * 10 + str[i] - '0';
		if (ft_overflow(num, str[i], flag) != 1)
			return (ft_overflow(num, str[i], flag));
		i++;
	}
	return (flag * num);
}

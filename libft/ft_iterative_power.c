/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 23:02:48 by equiana           #+#    #+#             */
/*   Updated: 2019/09/14 19:13:36 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ioverflow(long res, int nb)
{
	int sign;

	sign = 0;
	if ((res < 0 && nb > 0) || (res > 0 && nb < 0))
		sign = 1;
	if (res < 0)
		res = res * -1;
	if (nb < 0)
		nb = nb * -1;
	if (res * nb > res)
		return (1);
	else
	{
		if (sign == 0)
			return (-1);
		else
			return (0);
	}
}

int			ft_iterative_power(int nb, int power)
{
	int		i;
	long	res;

	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	else
	{
		i = 1;
		res = 1;
		while (i <= power)
		{
			if (ft_ioverflow(res, nb) != 1)
				return (ft_ioverflow(res, nb));
			res = res * nb;
			i++;
		}
		return (res);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 17:26:43 by equiana           #+#    #+#             */
/*   Updated: 2019/09/13 14:20:45 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;
	char			*s_el;

	i = 0;
	s_el = s;
	if (s == NULL || f == NULL)
		return ;
	while (*s_el != '\0')
	{
		f(i, s_el);
		s_el++;
		i++;
	}
}

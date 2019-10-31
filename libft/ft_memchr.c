/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 16:37:51 by equiana           #+#    #+#             */
/*   Updated: 2019/09/12 15:32:23 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s_def;

	i = 1;
	s_def = (unsigned char*)s;
	while (i <= n)
	{
		if (*s_def == (unsigned char)c)
			return ((void*)s_def);
		s_def++;
		i++;
	}
	return (NULL);
}

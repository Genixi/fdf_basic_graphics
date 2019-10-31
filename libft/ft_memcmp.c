/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 17:22:12 by equiana           #+#    #+#             */
/*   Updated: 2019/09/11 12:41:57 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_def;
	unsigned char	*s2_def;

	i = 0;
	s1_def = (unsigned char*)s1;
	s2_def = (unsigned char*)s2;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (*s1_def != *s2_def)
			return (*s1_def - *s2_def);
		s1_def++;
		s2_def++;
		i++;
	}
	return (0);
}

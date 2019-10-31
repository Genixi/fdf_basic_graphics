/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 14:08:24 by equiana           #+#    #+#             */
/*   Updated: 2019/09/11 12:32:47 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	subcycle(const char *str, const char *to_find)
{
	unsigned int i;

	i = 0;
	while (str[i] == to_find[i])
	{
		if (to_find[i + 1] == '\0')
			return (1);
		i++;
	}
	return (0);
}

char		*ft_strstr(const char *str, const char *to_find)
{
	unsigned int i_str;
	unsigned int i_to_find;

	i_str = 0;
	i_to_find = 0;
	while (to_find[i_to_find] != '\0')
		i_to_find++;
	if (i_to_find == 0)
		return ((char*)str);
	while (str[i_str] != '\0')
	{
		i_to_find = 0;
		if (subcycle(str + i_str, to_find))
			return ((char*)str + i_str);
		i_str++;
	}
	return (0);
}

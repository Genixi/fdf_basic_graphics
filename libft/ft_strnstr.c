/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 21:13:07 by equiana           #+#    #+#             */
/*   Updated: 2019/09/12 17:33:09 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *nd, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	j = 1;
	if (ft_strlen(nd) == 0)
		return ((char*)str);
	while (str[i] != '\0' && i < len)
	{
		if (str[i] == nd[0])
		{
			while (nd[j] != '\0' && str[i + j] == nd[j] && (i + j) < len)
				j++;
			if (nd[j] == '\0')
				return ((char*)&str[i]);
		}
		i++;
	}
	return (0);
}

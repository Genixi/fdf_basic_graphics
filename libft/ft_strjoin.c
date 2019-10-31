/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 18:52:50 by equiana           #+#    #+#             */
/*   Updated: 2019/09/13 15:49:14 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *str1, char const *str2)
{
	char	*str;
	size_t	size;

	if (str1 == NULL || str2 == NULL)
		return (NULL);
	else if (str1 && str2 == NULL)
		size = (size_t)(ft_strlen((char*)str1));
	else if (str2 && str1 == NULL)
		size = (size_t)(ft_strlen((char*)str2));
	else
		size = (size_t)(ft_strlen((char*)str1) + ft_strlen((char*)str2));
	str = (char*)malloc(sizeof(char) * (size + 1));
	if (str == NULL || size > size + 1)
		return (NULL);
	ft_memcpy(str, str1, ft_strlen(str1) + 1);
	ft_strcat(str, str2);
	return (str);
}

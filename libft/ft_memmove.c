/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 15:27:13 by equiana           #+#    #+#             */
/*   Updated: 2019/09/12 15:06:51 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*dst_def;
	const unsigned char	*src_def;

	i = 0;
	dst_def = (unsigned char*)dst;
	src_def = (const unsigned char*)src;
	if (dst_def > src_def)
		while (len--)
			dst_def[len] = src_def[len];
	else if (src_def > dst_def)
		while (len > i)
		{
			dst_def[i] = src_def[i];
			i++;
		}
	return (dst);
}

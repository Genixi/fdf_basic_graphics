/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 14:45:28 by equiana           #+#    #+#             */
/*   Updated: 2019/09/12 14:14:00 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*tmp;
	const unsigned char	*ttmp;

	if (!dst && !src)
		return (NULL);
	tmp = (unsigned char*)dst;
	ttmp = (const unsigned char*)src;
	while (n > 0)
	{
		*tmp = *ttmp;
		tmp++;
		ttmp++;
		n--;
	}
	return (dst);
}

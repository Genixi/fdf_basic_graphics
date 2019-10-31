/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 16:25:39 by equiana           #+#    #+#             */
/*   Updated: 2019/09/13 14:16:11 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	size_t i;
	size_t *ptr;

	i = 0;
	ptr = (size_t*)malloc(sizeof(size_t) * (size));
	if (ptr == NULL)
		return (NULL);
	while (i < size)
	{
		ptr[i] = 0;
		i++;
	}
	return ((void*)ptr);
}

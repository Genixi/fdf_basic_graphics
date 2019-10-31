/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 19:06:42 by equiana           #+#    #+#             */
/*   Updated: 2019/09/13 14:23:53 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	j;
	size_t	v;
	char	*str;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if (i == ft_strlen(s))
		return (ft_strdup(""));
	v = ft_strlen(s);
	while (s[v] == ' ' || s[v] == '\n' || s[v] == '\t' || s[v] == '\0')
		v--;
	if (!(str = (char*)malloc(sizeof(char) * (v - i + 2))))
		return (NULL);
	while (i <= v)
		str[j++] = s[i++];
	str[j] = '\0';
	return (str);
}

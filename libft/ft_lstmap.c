/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 17:33:36 by equiana           #+#    #+#             */
/*   Updated: 2019/09/13 15:31:59 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_freemem(void *content, size_t content_size)
{
	ft_memdel(&content);
	content_size = 0;
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *tmp;
	t_list *begin;

	if (lst == NULL || f == NULL)
		return (NULL);
	if (!(begin = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	*begin = *f(lst);
	tmp = begin;
	lst = lst->next;
	while (lst)
	{
		if (!(tmp->next = (t_list*)malloc(sizeof(t_list))))
		{
			ft_lstdel(&begin, ft_freemem);
			return (NULL);
		}
		*(tmp->next) = *f(lst);
		tmp = tmp->next;
		lst = lst->next;
	}
	return (begin);
}

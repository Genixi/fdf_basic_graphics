/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 17:09:32 by equiana           #+#    #+#             */
/*   Updated: 2019/09/13 15:12:28 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *tmp;
	t_list *ttmp;

	tmp = *alst;
	ttmp = tmp;
	if (!del || !alst || !(*alst))
		return ;
	while (tmp)
	{
		ttmp = tmp;
		if (tmp->next)
			tmp = tmp->next;
		else
			tmp = NULL;
		del((ttmp->content), (ttmp->content_size));
		free(ttmp);
	}
	*alst = NULL;
}

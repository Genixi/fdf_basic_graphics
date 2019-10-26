/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 19:07:39 by equiana           #+#    #+#             */
/*   Updated: 2019/10/26 14:52:38 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"
#include <stdio.h>
t_list *ft_get_point(char *value, int j, int i)
{
	//оптимизировать - не искать каждвый раз конец списка перебирая сначала
	t_list *tmp;
	int h;
	t_point *point;

	if (!(point = (t_point*)malloc(sizeof(t_point))))
		ft_error();
	h = ft_atoi(value);
	point->h = (double)h;
	point->x = (double)i*ZOOM;
	point->y = (double)j*ZOOM;
	point->line = j;
	if (!(tmp = ft_lstnew(point, sizeof(t_point))))
		ft_error();
	free(point);
	return(tmp);
}

void ft_form_list(t_list **begin, char *line, int line_num)
{
	int i;
	char **str;
	t_list *tmp;
	t_list *ttmp;

	i = 0;
	tmp = *begin;
	if (tmp)
		while (tmp->next)
			tmp = tmp->next;
	str = ft_strsplit(line, ' ');
	if (str == NULL)
		ft_error();
	while (str[i])
	{
		ttmp = ft_get_point(str[i], line_num, i);
		if (tmp)
		{
			tmp->next = ttmp;
			tmp = tmp->next;
		}
		else
		{
			*begin = ttmp;
			tmp = *begin;
		}
		i++;
	}
	//здесь надо чистить указатели
}

t_list	*ft_read_file(int fd)
{
	int ret;
	int line_num;
	char *line;
	t_list *lst;

	line_num = 0;
	lst = NULL;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		ft_form_list(&lst, line, line_num);
		free(line);
		line = NULL;
		line_num++;
	}
	if (ret == -1)
		ft_error();
	return (lst);
}

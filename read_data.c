/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 19:07:39 by equiana           #+#    #+#             */
/*   Updated: 2019/10/17 17:13:52 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"
#include <stdio.h>
t_list *ft_get_point(char *value, int x, int y)
{
	//оптимизировать - не искать каждвый раз конец списка перебирая сначала
	t_list *tmp;
	int h;
	t_point *point;

	if (!(point = (t_point*)malloc(sizeof(t_point))))
		ft_putstr("error\n");
	h = ft_atoi(value);
	point->h = h;
	point->x = x;
	point->y = y;
	tmp = ft_lstnew(point, sizeof(t_point));
	free(point);
//	printf("create point with height: %d, x: %d, y: %d\n", ((t_point*)(tmp->content))->height, ((t_point*)(tmp->content))->x, ((t_point*)(tmp->content))->y);
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
	while (str[i])
	{
		printf("iteration: %d\n", i);
		ttmp = ft_get_point(str[i], line_num, i);
//		printf("create point with height: %d\n", ((t_point*)(ttmp->content))->height);
		if (tmp)
		{
			tmp->next = ttmp;
			tmp = tmp->next;
//			printf("create point with height: %d\n", ((t_point*)(tmp->content))->height);
		}
		else
		{
			*begin = ttmp;
			tmp = *begin;
		}
		i++;
	}
}

t_list	*ft_read_file(int fd)
{
	int ret;
	int line_num;
	char *line;
	t_list *lst;

	line_num = 0;
	lst = NULL;
	while ((ret = get_next_line(fd, &line)))
	{
		printf("line read #%d\n", line_num);
		ft_form_list(&lst, line, line_num);
		free(line);
		line = NULL;
		line_num++;
	}
	if (ret == -1)
		ft_putstr("error\n");
	return (lst);
}

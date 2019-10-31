/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 19:07:39 by equiana           #+#    #+#             */
/*   Updated: 2019/10/31 16:44:00 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"

t_list	*ft_get_point(char *value, int j, int i)
{
	int		h;
	t_list	*tmp;
	t_point	*point;

	if (!(point = (t_point*)malloc(sizeof(t_point))))
		ft_error(2);
	h = ft_atoi(value);
	point->h = h;
	point->x = i * ZOOM;
	point->y = j * ZOOM;
	point->line = j;
	point->color = set_color(h);
	if (!(tmp = ft_lstnew(point, sizeof(t_point))))
		ft_error(2);
	free(point);
	return (tmp);
}

void	ft_form_list(t_list **begin, char *line, int line_num)
{
	int		i;
	char	**str;
	t_list	*tmp;
	t_list	*ttmp;

	i = -1;
	tmp = ft_lstlast(*begin);
	if (!(str = ft_strsplit(line, ' ')))
		ft_error(1);
	while (str[++i])
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
		free(str[i]);
	}
	free(str);
}

t_list	*ft_read_file(int fd)
{
	int		ret;
	int		line_num;
	char	*line;
	t_list	*lst;

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
		ft_error(3);
	return (lst);
}

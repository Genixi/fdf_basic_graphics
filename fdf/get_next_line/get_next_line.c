/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 13:48:38 by equiana           #+#    #+#             */
/*   Updated: 2019/10/16 19:42:46 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "get_next_line.h"

static char	*str_dup_join(char *dst, char *src, int ret)
{
	char *str;

	str = dst;
	src[ret] = '\0';
	if (ft_strlen(dst) == 0)
		dst = ft_strdup(src);
	else
		dst = ft_strjoin(dst, src);
	ft_strdel(&str);
	return (dst);
}

static int	get_return(char *line, int ret, char *arr)
{
	if ((ret == -1) || (line == NULL) || (arr == NULL))
		return (-1);
	if ((ft_strlen(line) == 0) && !arr)
	{
		ft_strdel(&arr);
		return (0);
	}
	else
		return (1);
}

static int	check_1(const int fd, char **line)
{
	char buff[32];

	if (fd < 0 || !line || (read(fd, buff, 0) < 0))
		return (1);
	else
		return (0);
}

static int	check_2(char *arr)
{
	if (arr != NULL && !ft_strchr(arr, '\n'))
		return (1);
	else
		return (0);
}

int			get_next_line(const int fd, char **line)
{
	int			ret;
	int			rd;
	char		*str;
	static char	*a[10340];
	char		buf[BUFF_SIZE + 1];

	if (check_1(fd, line) || (!a[fd] && (!(a[fd] = ft_strnew(1)))))
		return (-1);
	while (check_2(a[fd]) && (ret = read(fd, buf, BUFF_SIZE)) > 0)
		a[fd] = str_dup_join(a[fd], buf, ret);
	if (a[fd] != NULL && ret != -1 && !*(str = a[fd]))
	{
		ft_strdel(&a[fd]);
		return (0);
	}
	if (a[fd] != NULL && ret != -1 && (rd = (ft_strchr(a[fd], '\n') > 0)))
		*line = ft_strsub(a[fd], 0, ft_strchr(a[fd], '\n') - a[fd]);
	else if (a[fd] != NULL && ret != -1)
		*line = ft_strdup(a[fd]);
	if (a[fd] != NULL && ret != -1 && *line != NULL)
		a[fd] = ft_strsub(a[fd], (unsigned int)(rd + ft_strlen(*line)),
				(size_t)(ft_strlen(a[fd]) - rd - ft_strlen(*line)));
	if (a[fd] != NULL && ret != -1)
		ft_strdel(&str);
	return (get_return(*line, ret, a[fd]));
}

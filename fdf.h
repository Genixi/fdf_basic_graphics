/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 19:20:07 by equiana           #+#    #+#             */
/*   Updated: 2019/10/17 21:22:32 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "libft/libft.h"

# define ESC 53

typedef struct	s_point
{
	int			h;
	int			x;
	int			y;	
}				t_point;

int				get_next_line(const int fd, char **line);
void			display_lst(t_list *lst);
t_list			*ft_read_file(int fd);

#endif

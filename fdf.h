/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 19:20:07 by equiana           #+#    #+#             */
/*   Updated: 2019/10/22 21:53:28 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "libft/libft.h"

# define ESC 53
# define WIDTH 800 
# define HEIGHT 600
# define DELTA 10
# define V_ANGLE 2

typedef struct	s_point
{
	int			h;
	int			x;
	int			y;
	int			line;	
}				t_point;

typedef struct	s_param
{
	void		*mlx_ptr;
	void		*win_ptr;
}				t_param;

int				get_next_line(const int fd, char **line);
int				ft_deal_key(int key, void *param);
void			ft_iso(int *x, int *y, int z);
void			ft_error(void);
void			ft_render(t_list *map);
void			display_lst(t_list *lst);
t_list			*ft_read_file(int fd);

#endif

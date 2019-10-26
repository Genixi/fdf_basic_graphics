/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 19:20:07 by equiana           #+#    #+#             */
/*   Updated: 2019/10/26 16:33:42 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "libft/libft.h"

# define WIDTH			1000
# define HEIGHT 		1000
# define M_WIDTH		250
# define ZOOM			10

# define ESC			53

# define ARROW_UP		126
# define ARROW_DOWN		125
# define ARROW_LEFT		123
# define ARROW_RIGHT	124

# define ZOOM_IN		24
# define ZOOM_OUT		27

# define INCL_LESS		25
# define INCL_MORE		29

# define ISO			34
# define PAR			35

/*
 * point description
 */

typedef struct	s_point
{
	int			h;
	int			x;
	int			y;
	int			line;	
}				t_point;

typedef struct	s_step
{
	int			x;
	int			y;
	int			h;
}				t_step;

/*
 * window options to draw initial pictur
 */

typedef struct	s_window
{
	int			n_cols;
	int			n_rows;
	int			l_delta;
	int			h_delta;	
}				t_window;

/*
 * all parameters to draw and manipulate picture
 * x_delta - offset initial picture along x asix in case ARROW_LEFT/RIGHT push
 * y_delta - offet initial picture along y asix in case arrow ARROW_UP/DOWN push
 * map - point to the data list
 * proj - projection status, 0 - iso, 1 - parallel  
 */

typedef struct	s_param
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_list		*map;
	int			x_delta;
	int			y_delta;
	int			zoom;
	int			proj;
	int			angle;
}				t_param;

int				get_next_line(const int fd, char **line);
int				ft_deal_key(int key, void *param);
void			ft_menu(void *mlx_ptr, void *win_ptr);
void			ft_iso(int *x, int *y, int z);
void			ft_iso_apply(t_list **lst);
void			ft_par_apply(t_list **lst);
void			ft_error(void);
void			ft_arrow_move(int key, t_param *param);
void			ft_zoom_move(int key, t_param *param);
void			ft_incline_move(int key, t_param *param);
void			ft_project_move(int key, t_param *param);
void			ft_render(t_list *map);
void			ft_bresenham(t_param *prm, t_point p0, t_point p1, t_window window);
void			ft_render_map(t_list *map, t_param *param);
void			display_lst(t_list *lst);
t_list			*ft_lstlast(t_list *begin);
t_list			*ft_read_file(int fd);

#endif

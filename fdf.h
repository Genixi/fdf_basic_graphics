/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 19:20:07 by equiana           #+#    #+#             */
/*   Updated: 2019/10/31 18:27:07 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "libft/libft.h"

# define COLOR_MAX		2147483647
# define COLOR_MIN		-2147483648

# define WIDTH			1420
# define HEIGHT 		780
# define M_WIDTH		250
# define ZOOM			1

# define ESC			53

# define ARROW_UP		126
# define ARROW_DOWN		125
# define ARROW_LEFT		123
# define ARROW_RIGHT	124

# define ROTATE_X1		2
# define ROTATE_X2		0
# define ROTATE_Y1		1
# define ROTATE_Y2		13
# define ROTATE_Z1		12
# define ROTATE_Z2		14

# define ZOOM_IN		24
# define ZOOM_OUT		27

# define ISO			18
# define PAR			19

# define MOUSE_LEFT		1
# define MOUSE_UP		4
# define MOUSE_DOWN		5

# define STEELBLUE		0x4682B4
# define TAN			0xD2B48C
# define SANDYBROWN		0xF4A460
# define GOLDENROD		0xDAA520
# define CHOCOLATE		0xD2691E
# define SIENNA			0xA0522D
# define BROWN			0xA52A2A
# define WHITE			0xFFFFFF

/*
** point description
*/

typedef struct	s_point
{
	int			h;
	int			x;
	int			y;
	int			line;
	int			color;
}				t_point;

typedef struct	s_step
{
	int			x;
	int			y;
	int			x_tmp;
	int			y_tmp;
	int			h;
	int			x_step;
	int			y_step;
}				t_step;

/*
** all parameters to draw and manipulate picture
** x_delta - offset initial picture along x asix in case ARROW_LEFT/RIGHT push
** y_delta - offet initial picture along y asix in case arrow ARROW_UP/DOWN push
** map - point to the data structure
** proj - projection status, 0 - iso, 1 - parallel
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
	int			h_min;
	int			h_max;
	double		x_angle;
	double		y_angle;
	double		z_angle;
	int			mouse;
	int			x_mouse;
	int			y_mouse;
}				t_param;

int				get_next_line(const int fd, char **line);
int				ft_deal_key(int key, void *param);
int				ft_deal_mouse(int key, int x, int y, void *param);
int				ft_mouse_click(int key, int x, int y, void *param);
int				ft_mouse_move(int x, int y, void*param);
int				set_color(int h);
int				get_light(int start, int end, double mix);
int				get_clr(t_point a, t_point p0, t_point p1, t_step delta);
double			get_mix(int start, int end, int current);
void			ft_menu(void *mlx_ptr, void *win_ptr);
void			ft_error(int type);
void			ft_iso_apply(int *x, int *y, int z);
void			ft_rotate(int *x, int *y, int *z, t_param *param);
void			ft_arrow_move(int key, t_param *param);
void			ft_zoom_move(int key, t_param *param);
void			ft_rotate_move(int key, t_param *param);
void			ft_incline_move(int key, t_param *param);
void			ft_project_move(int key, t_param *param);
void			ft_render(t_list *map, char *name);
void			ft_brnhm(t_param *prm, t_point p0, t_point p1);
void			ft_brnhm_init(t_step *t, t_step *s, t_point p0, t_point p1);
void			ft_render_map(t_list *map, t_param *param);
t_point			ft_proj_apply(t_point point, t_param *param);
t_list			*ft_lstlast(t_list *begin);
t_list			*ft_read_file(int fd);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 18:03:35 by equiana           #+#    #+#             */
/*   Updated: 2019/10/31 17:19:45 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"
#include <mlx.h>
#include <math.h>

void	ft_render_map(t_list *m, t_param *p)
{
	t_point	p01;
	t_list	*t;
	t_point	p11;

	if (p->mlx_ptr && p->win_ptr)
		mlx_clear_window((void*)(p->mlx_ptr), (void*)(p->win_ptr));
	ft_menu(p->mlx_ptr, p->win_ptr);
	t = m;
	while (m && m->next)
	{
		p01 = *(t_point*)(m->next->content);
		if ((*(t_point*)(m->content)).line == p01.line)
			ft_brnhm(p, *(t_point*)(m->content), p01);
		if (t->next && (*(t_point*)(m->content)).line != 0)
		{
			p11 = *(t_point*)(t->next->content);
			if (p11.line == (*(t_point*)(t->content)).line)
			{
				ft_brnhm(p, p11, p01);
				ft_brnhm(p, *(t_point*)(t->content), *(t_point*)(m->content));
			}
			t = t->next;
		}
		m = m->next;
	}
}

void	ft_brnhm_init(t_step *t, t_step *s, t_point p0, t_point p1)
{
	s->x = p0.x;
	s->y = p0.y;
	s->x_step = ((p0.x < p1.x) ? 1 : -1);
	s->y_step = ((p0.y < p1.y) ? 1 : -1);
	t->x = abs(p1.x - p0.x);
	t->y = abs(p1.y - p0.y);
	t->h = t->x - t->y;
}

void	ft_brnhm(t_param *p, t_point p0, t_point p1)
{
	t_step	t;
	t_step	s;
	t_point	c;
	int		error;

	p0 = ft_proj_apply(p0, p);
	p1 = ft_proj_apply(p1, p);
	c = p0;
	ft_brnhm_init(&t, &s, p0, p1);
	while (s.x != p1.x || s.y != p1.y)
	{
		mlx_pixel_put(p->mlx_ptr, p->win_ptr, s.x, s.y, get_clr(c, p0, p1, t));
		if ((error = t.h * 2) > -t.y)
		{
			t.h -= t.y;
			s.x = s.x + s.x_step;
			c.x = s.x;
		}
		if (error < t.x)
		{
			t.h += t.x;
			s.y = s.y + s.y_step;
			c.y = s.y;
		}
	}
}

void	ft_render(t_list *map, char *name)
{
	t_param	param;

	param.mlx_ptr = mlx_init();
	param.win_ptr = mlx_new_window(param.mlx_ptr, WIDTH, HEIGHT, name);
	param.x_delta = 0;
	param.y_delta = 0;
	param.zoom = 1;
	param.angle = 1;
	param.proj = 'P';
	param.x_angle = 0;
	param.y_angle = 0;
	param.z_angle = 0;
	param.h_min = COLOR_MIN;
	param.h_max = COLOR_MAX;
	param.mouse = 0;
	param.x_mouse = 0;
	param.y_mouse = 0;
	param.map = map;
	mlx_hook(param.win_ptr, 2, 0, ft_deal_key, (void*)(&param));
	mlx_hook(param.win_ptr, 4, 0, ft_deal_mouse, (void*)(&param));
	mlx_hook(param.win_ptr, 5, 0, ft_mouse_click, (void*)(&param));
	mlx_hook(param.win_ptr, 6, 0, ft_mouse_move, (void*)(&param));
	ft_render_map(map, &param);
	mlx_loop(param.mlx_ptr);
}

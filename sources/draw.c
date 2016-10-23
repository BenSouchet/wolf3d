/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 18:39:52 by bsouchet          #+#    #+#             */
/*   Updated: 2016/10/21 16:39:28 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	draw_player_triangle(t_var *v, int center, int height, int clr)
{
	int		start;
	int		end;

	start = center;
	end = center;
	v->y = center - 2;
	while (++v->y < height && (v->x = start--) > 0 && ++end > 0)
		while (v->x <= end)
			if (v->x++ > 0 && mlx_get_pixel_clr(v->img, v->x, v->y) != BG_MAP)
				mlx_put_pixel(v->img, v->x, v->y, clr);
}

void	draw_rectangle(t_var *v, int x, int y, int clr)
{
	int		p_x;
	int		p_y;

	p_x = v->x;
	p_y = v->y;
	while (v->x < x && mlx_put_pixel(v->img, v->x, v->y, clr) == 0)
		v->x++;
	while (v->y < y && mlx_put_pixel(v->img, v->x, v->y, clr) == 0)
		v->y++;
	while (v->x > p_x && mlx_put_pixel(v->img, v->x, v->y, clr) == 0)
		v->x--;
	while (v->y > p_y && mlx_put_pixel(v->img, v->x, v->y, clr) == 0)
		v->y--;
}

void	draw_start_texts(t_var *v)
{
	if (v->start != 1)
		return ;
	v->loop = (v->loop >= 60) ? 0 : v->loop + 1;
	if (v->loop < 40)
		mlx_put_str(v->mlx, v->win, v->mid, (WIN_H - 115), UI_B, START);
}

void	draw_ui(t_var *v, int x, int y)
{
	int		clr;
	void	*img;

	if (v->t == 0)
		img = (v->h != 1) ? v->ui : v->hr;
	else
		img = (v->h == 0) ? v->ui_t : v->hr_t;
	while (++y < WIN_H && (x = -1) != 0)
		while (++x < 214 && (clr = mlx_get_pixel_clr(img, x, y)) != 0)
			mlx_put_pixel(v->img, x, y, clr);
	if (v->m != 0)
		player_transform(v);
	key_operations(v);
	key_transform(v, 0., 0.);
	(v->h == 1) ? draw_mm_hardcore(v, -1, -1, 0) : draw_mm(v, 0, 0, 0);
}

void	draw_ui_texts(t_var *v)
{
	if (v->t != 1)
		mlx_put_str(v->mlx, v->win, v->len, (WIN_H - 55), UI_B, v->name);
	else
		mlx_put_str(v->mlx, v->win, v->len, (WIN_H - 55), UI_F, v->name);
	if (v->h == 1 && v->t == 0)
		mlx_put_str(v->mlx, v->win, 66, 95, UI_B, "DISABLED");
	else if (v->h == 1)
		mlx_put_str(v->mlx, v->win, 66, 95, UI_T, "DISABLED");
}

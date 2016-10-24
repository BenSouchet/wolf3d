/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 15:33:54 by bsouchet          #+#    #+#             */
/*   Updated: 2016/10/24 19:34:39 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <stdio.h>

static void		draw_wall(t_var *v, int y, int clr)
{
	clr = (v->easy != 1) ? ft_gt_colors(v->p_clr, AO,
	((v->dist - 0.4) / ((4. - (2. * FT(v->h))) - 0.4))) : v->p_clr;
	while (++y < WIN_H && y <= v->max)
		mlx_put_pixel(v->img, v->x, y,
		ft_add_ao(clr, ((y - v->min) * 100. / (v->max - v->min))));
}

static void		wall_color_detection(t_var *v, double tx, double ty)
{
	if (ty == I(ty) && tx == I(tx))
		v->p_clr = v->p_clr;
	else if (ty == I(ty) && v->posy > ty)
		v->p_clr = WALL_N;
	else if (ty == I(ty) && v->posy <= ty)
		v->p_clr = WALL_S;
	else if (tx == I(tx) && v->posx <= tx)
		v->p_clr = WALL_E;
	else if (tx == I(tx) && v->posx > tx)
		v->p_clr = WALL_W;
}

static void		execute_raycasting(t_var *v, int x, double tx, double ty)
{
	int		y;
	int		height;

	v->ray = (FOV * atan(((x - 214.) - ((WIN_W - 215.) / 2.)) / v->s_dist));
	while (v->map[I(ty)][I(tx)][2] != '1')
	{
		tx += cos(((v->p_r + v->ray) - 90.) * (PI / 180.)) * 0.003;
		ty += sin(((v->p_r + v->ray) - 90.) * (PI / 180.)) * 0.003;
	}
	tx = (!(tx >= (I(tx) + 0.0029) && tx <= (I(tx) + 0.9971))) ? round(tx) : tx;
	ty = (!(ty >= (I(ty) + 0.0029) && ty <= (I(ty) + 0.9971))) ? round(ty) : ty;
	v->dist = (sqrt(pow((tx - v->posx), 2.) + pow((ty - v->posy), 2.)) *
	cos(v->ray * (PI / 180.)));
	height = round(((v->s_dist - 200.) / v->dist) / 2.);
	if (x == v->x && x != 214 && height >= (v->p_height + 20))
		execute_raycasting(v, (x + 15), v->posx, v->posy);
	else
		wall_color_detection(v, tx, ty);
	v->min = ((WIN_H / 2) - height);
	v->max = ((WIN_H / 2) + height);
	y = (v->min < -1) ? -1 : v->min;
	if (x == v->x && (v->p_height = height) != 0)
		(v->t != 1) ? draw_wall(v, y, 0) : draw_textured_wall(v, tx, ty, y);
}

static void		draw_background(t_var *v, double val, int clr)
{
	v->y = -1;
	while (++v->y < WIN_H && (v->x = 213) != 0)
	{
		if (v->easy != 0)
			val = 0.;
		else if (v->h != 1)
			val = (v->y < 370) ?
			(-(0.75 / ((FT(v->y + 20) / 100.) - 3.78)) - 0.1) :
			((0.75 / (((FT(v->y) - 430) / 100.) + 0.68)) - 0.1);
		else
			val = (v->y < 370) ?
			(-(1.55 / ((FT(v->y + 20) / 100.) - 3.69)) - 0.2) :
			((1.55 / (((FT(v->y) - 500) / 100.) + 1.29)) - 0.2);
		clr = ft_gt_colors(((v->y < 370) ? WALL_T : WALL_B), AO, val);
		while (++v->x < WIN_W)
			mlx_put_pixel(v->img, v->x, v->y, clr);
	}
}

void			raycasting(t_var *v)
{
	if (v->t != 1)
		draw_background(v, 0., 0);
	v->x = 213;
	while (++v->x < WIN_W)
		execute_raycasting(v, v->x, v->posx, v->posy);
	v->x = v->len - 14;
	v->y = (WIN_H - 65);
	draw_rectangle(v, (WIN_W - 25), (WIN_H - 25), ((v->t != 1) ? UI_B : UI_F));
}

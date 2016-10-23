/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 15:33:54 by bsouchet          #+#    #+#             */
/*   Updated: 2016/10/20 11:37:45 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	draw_t_floor(t_var *v, double tx, double ty, int y)
{
	int		clr;
	int		t_x;
	int		t_y;
	double	dist;

	while (y < WIN_H)
	{
		tx += cos(((v->p_r + v->ray) + 90.) * (PI / 180.)) * 0.0022;
		ty += sin(((v->p_r + v->ray) + 90.) * (PI / 180.)) * 0.0022;
		t_x = 511. * FT(tx - (int)tx);
		t_y = 511. * FT(ty - (int)ty);
		dist = (sqrt(pow((tx - v->posx), 2.) + pow((ty - v->posy), 2.))) *
		cos(v->ray * (PI / 180.));
		clr = mlx_get_pixel_clr(v->fl, t_x, t_y);
		clr = (v->easy != 1) ? ft_gt_colors(clr, AO,
		((dist - 0.4) / ((4. - (2. * FT(v->h))) - 0.4))) : clr;
		y = ((WIN_H / 2) + round(((v->s_dist - 200.) / dist) / 2.));
		mlx_put_pixel(v->img, v->x, y, clr);
		clr = mlx_get_pixel_clr(v->cl, t_x, t_y);
		clr = (v->easy != 1) ? ft_gt_colors(clr, AO,
		((dist - 0.4) / ((4. - (2. * FT(v->h))) - 0.4))) : clr;
		mlx_put_pixel(v->img, v->x, (WIN_H - y), clr);
	}
}

int		draw_t_wall(t_var *v, double tx, double ty, int y)
{
	int		t_x;
	int		t_y;
	int		clr;

	t_x = (v->p_clr == WALL_W || v->p_clr == WALL_E) ?
	511. * FT(ty - (int)ty) : 511. * FT(tx - (int)tx);
	while (++y < WIN_H && y <= v->max)
	{
		t_y = 511. * FT(y - v->min) / FT(v->max - v->min);
		clr = mlx_get_pixel_clr(v->wt, t_x, t_y);
		clr = (v->easy != 1) ? ft_gt_colors(clr, AO,
		((v->dist - 0.4) / ((4. - (2. * FT(v->h))) - 0.4))) : clr;
		mlx_put_pixel(v->img, v->x, y,
		ft_add_ao(clr, ((y - v->min) * 100. / (v->max - v->min))));
	}
	draw_t_floor(v, tx, ty, 0);
	return (0);
}

int		draw_wall(t_var *v, int y, int clr)
{
	clr = (v->easy != 1) ? ft_gt_colors(v->p_clr, AO,
	((v->dist - 0.4) / ((4. - (2. * FT(v->h))) - 0.4))) : v->p_clr;
	while (++y < WIN_H && y <= v->max)
		mlx_put_pixel(v->img, v->x, y,
		ft_add_ao(clr, ((y - v->min) * 100. / (v->max - v->min))));
	return (0);
}

void	wall_color_detection(t_var *v, double tx, double ty)
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

void	execute_raycasting(t_var *v, int x, double tx, double ty)
{
	int		y;
	int		height;

	v->ray = (FOV * atan(((x - 214.) - ((WIN_W - 215.) / 2.)) / v->s_dist));
	while (v->map[I(ty)][I(tx)][2] != '1')
	{
		tx += cos(((v->p_r + v->ray) - 90.) * (PI / 180.)) * 0.005;
		ty += sin(((v->p_r + v->ray) - 90.) * (PI / 180.)) * 0.005;
	}
	tx = (!(tx >= (I(tx) + 0.005) && tx <= (I(tx) + 0.995))) ? round(tx) : tx;
	ty = (!(ty >= (I(ty) + 0.005) && ty <= (I(ty) + 0.995))) ? round(ty) : ty;
	v->dist = (sqrt(pow((tx - v->posx), 2.) + pow((ty - v->posy), 2.)) *
	cos(v->ray * (PI / 180.)));
	height = round(((v->s_dist - 200.) / v->dist) / 2.);
	wall_color_detection(v, tx, ty);
	v->min = ((WIN_H / 2) - height);
	v->max = ((WIN_H / 2) + height);
	y = (v->min < -1) ? -1 : v->min;
	(v->t != 1) ? draw_wall(v, y, 0) : draw_t_wall(v, tx, ty, y);
}

void	draw_background(t_var *v, double val, int clr)
{
	v->y = -1;
	while (++v->y < WIN_H && (v->x = 213) != 0)
	{
		if (v->easy != 0)
			val = 0.;
		else if (v->h != 1)
			val = (v->y < 370) ? (-(0.75 / ((FT(v->y + 20) / 100.) - 3.78)) - 0.1) :
			((0.75 / (((FT(v->y) - 430) / 100.) + 0.68)) - 0.1);
		else
			val = (v->y < 370) ? (-(1.55 / ((FT(v->y + 20) / 100.) - 3.69)) - 0.2) :
			((1.55 / (((FT(v->y) - 500) / 100.) + 1.29)) - 0.2);
		clr = ft_gt_colors(((v->y < 370) ? WALL_T : WALL_B), AO, val);
		while (++v->x < WIN_W)
			mlx_put_pixel(v->img, v->x, v->y, clr);
	}
}

void	raycasting(t_var *v)
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

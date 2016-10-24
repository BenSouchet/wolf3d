/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 18:35:58 by bsouchet          #+#    #+#             */
/*   Updated: 2016/10/24 17:00:13 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		expose_hook(t_var *v)
{
	if (v->start == 2 && v->mu == 1 && ++v->start == 3)
		system("killall afplay 2&>/dev/null >/dev/null\n \
		afplay /System/Library/Sounds/Hero.aiff&\n \
		afplay ./assets/songs/song1.mp3&");
	if (v->start > 2)
		mlx_clear_img(v->img, AO);
	mlx_clear_win(v->mlx, v->win);
	(v->start < 2) ? start_screen(v) : draw_ui(v, 0, -1);
	if (v->start > 2)
		raycasting(v);
	if (v->start == 0)
		mlx_put_img_to_win(v->mlx, v->win, v->ps, 0, 0);
	else if (v->start == 1)
		mlx_put_img_to_win(v->mlx, v->win, v->ss, 0, 0);
	else
		mlx_put_img_to_win(v->mlx, v->win, v->img, 0, 0);
	(v->start < 2) ? draw_start_texts(v) : draw_ui_texts(v);
	return (0);
}

int		key_press_hook(int key, t_var *v)
{
	++v->start;
	if (key == 53)
		return (close_prog(v));
	v->k[key] = 1;
	return (0);
}

int		key_release_hook(int key, t_var *v)
{
	if (key == 4 && (v->easy = 0) != 1)
		v->h = (v->h != 1) ? 1 : 0;
	if (key == 6 && (v->h = 0) != 1)
		v->easy = (v->easy != 1) ? 1 : 0;
	if (key == 17)
		v->t = (v->t != 1) ? 1 : 0;
	if (key == 46)
		v->m = (v->m != 1) ? 1 : 0;
	if (v->start > 3 && key == 35 && v->mu == 1 && (v->mu = 2) == 2)
		system("killall -SIGSTOP afplay 2&>/dev/null >/dev/null");
	else if (v->start > 3 && key == 35 && v->mu == 2 && (v->mu = 1) == 1)
		system("killall -SIGCONT afplay 2&>/dev/null >/dev/null");
	if (v->start > 3 && key >= 18 && key <= 21)
		change_song(v, key - 17);
	if (v->start > 3 && key >= 83 && key <= 86)
		change_song(v, key - 82);
	if (key == 71)
		reset_values(v);
	v->k[key] = 0;
	return (0);
}

int		motion_hook(int x, int y, t_var *v)
{
	v->mx = x;
	v->my = y;
	return (0);
}

int		mouse_hook(int button, int x, int y, t_var *v)
{
	(void)x;
	(void)y;
	(void)button;
	++v->start;
	return (0);
}

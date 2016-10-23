/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/22 11:33:00 by bsouchet          #+#    #+#             */
/*   Updated: 2016/10/19 15:42:06 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	reset_values(t_var *v)
{
	v->h = 0;
	v->t = 0;
	v->m = 0;
	v->sp = 1.;
	v->p_r = 0.;
	v->easy = 0;
	v->posx = v->p_x;
	v->posy = v->p_y;
}

int		close_prog(t_var *v)
{
	mlx_destroy_img(v->mlx, v->ui);
	mlx_destroy_img(v->mlx, v->ps);
	mlx_destroy_img(v->mlx, v->ss);
	mlx_destroy_img(v->mlx, v->hr);
	mlx_destroy_img(v->mlx, v->wt);
	mlx_destroy_img(v->mlx, v->fl);
	mlx_destroy_img(v->mlx, v->cl);
	mlx_destroy_img(v->mlx, v->ui_t);
	mlx_destroy_img(v->mlx, v->hr_t);
	mlx_destroy_img(v->mlx, v->img);
	mlx_destroy_win(v->mlx, v->win);
	if (v->mu > 0)
		system("killall afplay 2&>/dev/null >/dev/null");
	free(v->name);
	free(v->map);
	free(v);
	exit(0);
	return (0);
}

int		free_stuff(t_var *v, int type)
{
	if (type == 0)
		return (1);
	else if (type == 1)
		;
	else if (type == 2)
		free(v->buf);
	else if (type == 3)
		free(v->map);
	else if (type == 4)
	{
		free(v->buf);
		free(v->map);
	}
	free(v);
	return (1);
}

int		error(t_var *v, int t1, int t2)
{
	char	*s;

	if (t1 == 0)
		write(2, MSG0, ft_strlen(MSG0));
	else if (t1 == 1)
		write(2, MSG1, ft_strlen(MSG1));
	else if (t1 == 2)
		write(2, MSG2, ft_strlen(MSG2));
	else if (t1 == 3)
		write(2, MSG3, ft_strlen(MSG3));
	else if (t1 == 4 || t1 == 6)
	{
		s = ft_strjoin(ft_strjoin("error : ", strerror(errno), 'N'), ".", 'L');
		write(2, s, ft_strlen(s));
		free(s);
	}
	else if (t1 == 5)
		write(2, MSG5, ft_strlen(MSG5));
	write(2, "\n", 1);
	return (free_stuff(v, t2));
}

void	change_song(t_var *v, int song_num)
{
	if (v->mu > 0)
		system("killall afplay 2&>/dev/null >/dev/null");
	if (song_num == 1)
		system("afplay ./assets/songs/song1.mp3&");
	else if (song_num == 2)
		system("afplay ./assets/songs/song2.mp3&");
	else if (song_num == 3)
		system("afplay ./assets/songs/song3.mp3&");
	else if (song_num == 4)
		system("afplay ./assets/songs/song4.mp3&");
}

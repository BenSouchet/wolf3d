/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 17:30:09 by bsouchet          #+#    #+#             */
/*   Updated: 2016/10/24 15:19:10 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int		convert(t_var *v)
{
	v->i = -1;
	v->y = -1;
	v->pts = (int **)malloc(sizeof(int *) * 4);
	while (++v->i < 4)
		v->pts[v->i] = (int *)malloc(sizeof(int) * 2);
	v->i = 0;
	if (!(v->map = (int ***)malloc(sizeof(int **) * v->lns)))
		return (error(v, 0, 2));
	while (++v->y < v->lns && (v->x = 0) == 0)
	{
		if (!(v->map[v->y] = (int **)malloc(sizeof(int *) * v->wth)))
			return (error(v, 0, 4));
		while (v->x < v->wth)
		{
			v->map[v->y][v->x] = (int *)malloc(sizeof(int) * 3);
			v->map[v->y][v->x][0] = (106 - ((int)v->p_y * S_L)) + (S_L * v->y);
			v->map[v->y][v->x][1] = (106 - ((int)v->p_x * S_L)) + (S_L * v->x);
			v->map[v->y][v->x++][2] = v->buf[v->i++];
		}
		v->i++;
	}
	free(v->buf);
	return (0);
}

static void		init_values(t_var *v)
{
	v->h = 0;
	v->t = 0;
	v->m = 0;
	v->mu = 1;
	v->sp = 1.;
	v->add = 0;
	v->loop = 0;
	v->easy = 0;
	v->start = 0;
	v->h_frame = 0;
	v->h_repeat = 0;
	v->posx = v->p_x;
	v->posy = v->p_y;
	v->p_clr = WALL_W;
	import_textures(v);
	v->name = ft_strjoin("Map : ", ft_del_dir_name(v->file), 'R');
	v->len = ((WIN_W - 50) - (ft_strlen(v->name) * 10)) + 11;
	v->mid = (WIN_W / 2) - ((ft_strlen(START) * 10) / 2);
	v->s_dist = round(((WIN_W - 214) / 2) / tan((FOV / 2.) * (PI / 180.)));
}

static void		init_win(t_var *v)
{
	v->mlx = mlx_init();
	init_values(v);
	v->img = mlx_new_img(v->mlx, WIN_W, WIN_H, AO);
	v->win = mlx_new_win(v->mlx, -1, -1, WIN_W, WIN_H, WIN_TITLE);
	system("afplay ./assets/songs/start_screen.mp3&");
	mlx_hook(v->win, 2, (1L << 0), key_press_hook, v);
	mlx_hook(v->win, 3, (1L << 1), key_release_hook, v);
	mlx_hook(v->win, 6, (1L << 6), motion_hook, v);
	mlx_hook(v->win, 17, (1L << 17), close_prog, v);
	mlx_mouse_hook(v->win, mouse_hook, v);
	mlx_loop_hook(v->mlx, expose_hook, v);
	mlx_loop(v->mlx);
	exit(0);
}

static int		execute(t_var *v, int fd)
{
	v->lns = 0;
	if (!(v->buf = (char *)malloc(sizeof(char))))
		return (error(v, 0, 1));
	v->buf[0] = 0;
	if (ft_strchr_at_end(v->file, ".w3d") == -1)
		return (error(v, 3, 2));
	if ((fd = open(v->file, O_RDONLY)) == -1)
		return (error(v, 4, 2));
	while (get_next_line(fd, &v->line) > 0 && ++v->lns > 0)
		v->buf = ft_strjoin(v->buf, ft_strjoin(v->line, "\n", 'L'), 'B');
	if (v->lns < 3)
		return (error(v, 5, 2));
	if (check(v) != 0 || convert(v) != 0)
		return (-1);
	if (close(fd) == -1)
		return (error(v, 6, 3));
	init_win(v);
	return (0);
}

int				main(int ac, char **av)
{
	t_var	*v;

	if (!(v = (t_var *)malloc(sizeof(t_var))))
		return (error(v, 0, 0));
	if (ac != 2)
		return (error(v, 1, 1));
	if (WIN_W < 1024 || WIN_H < 576)
		return (error(v, 2, 1));
	v->file = av[1];
	return (execute(v, 0));
}

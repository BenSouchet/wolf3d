/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 17:26:10 by bsouchet          #+#    #+#             */
/*   Updated: 2016/10/20 17:47:51 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <math.h>
# include <fcntl.h>
# include <errno.h>

# include "../libft/include/libft.h"
# include "../libmlx/includes/mlx.h"

# define WIN_TITLE "Wolf3D - bsouchet"

# define UI_B 0x2686D9
# define UI_T 0xAB7C49
# define UI_F 0xB58752
# define BG_CLR 0x353535
# define BG_MAP 0x2F2F2F
# define TX_CLR 0x453A2E
# define MM_CLR 0x3d3d3d

# define WALL_T 0x0D3558
# define WALL_B 0x0B2D4B
# define WALL_N 0x174F80
# define WALL_E 0x1B5C96
# define WALL_S 0x14446e
# define WALL_W 0x804d17

# define FOV 70.

# define WIN_W 1280
# define WIN_H 720

# define MID_W 640
# define MID_H 360

# define MID_VIEW_W 746
# define MID_VIEW_H 360

# define MID_MM_W 106.
# define MID_MM_H 106.

# define S_L 26
# define S_M 13

# define STEP_L 0.068

# define START "PRESS ANY BUTTON TO START"

# define MSG0 "error: Dynamic memory allocation failed."
# define MSG1 "usage: ./wolf3d input_file.w3d"
# define MSG2 "error: The window size must be greater than 1024 x 576."
# define MSG3 "error: The input file haven't the right extension (.w3d)."
# define MSG5 "error: The input file isn't a valid wolf3d map."

# define PI 3.14159265359

# define I (int)
# define FT (float)

typedef struct	s_var
{
	int			i;
	int			m;
	int			x;
	int			y;
	int			h;
	int			t;
	int			mu;
	int			mx;
	int			my;
	int			add;
	int			lns;
	int			len;
	int			mid;
	int			loop;
	int			easy;
	int			start;
	int			p_clr;
	double		s_dist;
	char		*file;
	char		*name;
	double		sp;
	char		*buf;
	char		*line;
	int			**pts;
	int			***map;
	int			h_frame;
	int			h_repeat;
	int			wth;
	double		p_x;
	double		p_y;
	double		p_r;
	double		ray;
	double		dist;
	double		posx;
	double		posy;
	char		k[280];
	void		*img;
	void		*mlx;
	void		*win;
	void		*ps;
	void		*ss;
	void		*ui;
	void		*hr;
	void		*ui_t;
	void		*hr_t;
	void		*wt;
	void		*fl;
	void		*cl;
	int			min;
	int			max;
}				t_var;

int				check(t_var *v);

int				error(t_var *v, int t1, int t2);
int				free_stuff(t_var *v, int type);
int				close_prog(t_var *v);

int				expose_hook(t_var *v);

int				key_press_hook(int key, t_var *v);
int				key_release_hook(int key, t_var *v);

void			key_operations(t_var *v);
void			key_transform(t_var *v, double px, double py);

int				mouse_hook(int button, int x, int y, t_var *v);
int				motion_hook(int x, int y, t_var *v);

void			player_transform(t_var *v);

void			start_screen(t_var *v);

void			draw_mm(t_var *v, int x, int y, int m);
void			draw_mm_hardcore(t_var *v, int x, int y, int clr);

void			draw_player_triangle(t_var *v, int center, int height, int clr);
void			draw_rectangle(t_var *v, int x, int y, int clr);
void			draw_start_texts(t_var *v);
void			draw_ui(t_var *v, int x, int y);
void			draw_ui_texts(t_var *v);

void			raycasting(t_var *v);

void			change_song(t_var *v, int song_num);

void			reset_values(t_var *v);

#endif

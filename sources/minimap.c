/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/10 14:45:30 by bsouchet          #+#    #+#             */
/*   Updated: 2016/10/06 15:57:07 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int		check_mm_point(t_var *v, int y, int x)
{
	int		i;
	int		j;
	int		c;

	c = 0;
	i = 0;
	j = (4 - 1);
	while (i < 4)
	{
		if (((v->pts[i][0] >= y) != (v->pts[j][0] >= y)) &
		(x <= (v->pts[j][1] - v->pts[i][1]) * (double)(y - v->pts[i][0]) /
		(double)(v->pts[j][0] - v->pts[i][0]) + v->pts[i][1]))
			c = !c;
		j = i++;
	}
	return (c);
}

static void		rotate_mm_square(t_var *v, int i)
{
	int		x;

	x =
	(FT(int)(cos(FT(-(v->p_r)) * (PI / 180.)) * 10000000) / 10000000) *
	FT(FT(v->pts[i][1]) - MID_MM_W) -
	(FT(int)(sin(FT(-(v->p_r)) * (PI / 180.)) * 10000000) / 10000000) *
	FT(FT(v->pts[i][0]) - MID_MM_H) + MID_MM_W;
	v->pts[i][0] =
	(FT(int)(sin(FT(-(v->p_r)) * (PI / 180.)) * 10000000) / 10000000) *
	FT(FT(v->pts[i][1]) - MID_MM_W) +
	(FT(int)(cos(FT(-(v->p_r)) * (PI / 180.)) * 10000000) / 10000000) *
	FT(FT(v->pts[i][0]) - MID_MM_H) + MID_MM_H;
	v->pts[i][1] = x;
}

static void		draw_mm_square(t_var *v, int y, int x, int i)
{
	int		clr;

	clr = (v->t != 1) ? MM_CLR : TX_CLR;
	v->pts[0][0] = (v->map[y][x][0] - S_M) - ((v->posy - v->p_y) * S_L);
	v->pts[0][1] = (v->map[y][x][1] - S_M) - ((v->posx - v->p_x) * S_L);
	v->pts[1][0] = (v->map[y][x][0] - S_M) - ((v->posy - v->p_y) * S_L);
	v->pts[1][1] = (v->map[y][x][1] + S_M) - ((v->posx - v->p_x) * S_L);
	v->pts[2][0] = (v->map[y][x][0] + S_M) - ((v->posy - v->p_y) * S_L);
	v->pts[2][1] = (v->map[y][x][1] + S_M) - ((v->posx - v->p_x) * S_L);
	v->pts[3][0] = (v->map[y][x][0] + S_M) - ((v->posy - v->p_y) * S_L);
	v->pts[3][1] = (v->map[y][x][1] - S_M) - ((v->posx - v->p_x) * S_L);
	while (++i < 4)
		rotate_mm_square(v, i);
	y = 25;
	while (++y <= 187 && (x = 25) == 25)
		while (++x <= 187)
			if (check_mm_point(v, y, x) == 1)
				mlx_put_pixel(v->img, x, y, clr);
}

void			draw_mm_hardcore(t_var *v, int x, int y, int clr)
{
	char	*str;
	void	*img;

	v->h_frame = (v->h_frame == 12) ? 0 : v->h_frame;
	str = ft_strjoin(ft_strjoin("./assets/images/noise/", ft_itoa(v->h_frame),
	'R'), ".xpm", 'L');
	img = mlx_xpm_to_img(v->mlx, str);
	while (++y < 162 && (x = -1) != 0)
		while (++x < 162 && (clr = mlx_get_pixel_clr(img, x, y)) != 0)
			mlx_put_pixel(v->img, (x + 26), (y + 26), clr);
	mlx_destroy_img(v->mlx, img);
	v->h_frame += (v->h_repeat == 3) ? 1 : 0;
	v->h_repeat = (v->h_repeat == 3) ? 0 : ++v->h_repeat;
	free(str);
}

void			draw_mm(t_var *v, int x, int y, int m)
{
	int		clr;
	int		end_x;
	int		end_y;

	m = (I(v->posx) - 5 >= 0) ? I(v->posx) - 5 : 0;
	end_x = (I(v->posx) + 5 >= v->wth) ? v->wth : I(v->posx) + 5;
	y = (I(v->posy) - 5 >= 0) ? I(v->posy) - 5 : 0;
	end_y = (I(v->posy) + 5 >= v->lns) ? v->lns : I(v->posy) + 5;
	while (++y < end_y && (x = m) == m)
		while (++x < end_x)
			if (v->map[y][x][2] != '1')
				draw_mm_square(v, y, x, -1);
	clr = (v->t != 1) ? UI_B : UI_T;
	draw_player_triangle(v, 106, 109, clr);
}

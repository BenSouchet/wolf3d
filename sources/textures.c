/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 14:59:01 by bsouchet          #+#    #+#             */
/*   Updated: 2016/10/24 17:01:08 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		import_textures(t_var *v)
{
	v->ui = mlx_xpm_to_img(v->mlx, "./assets/images/ui/normal.xpm");
	v->ui_t = mlx_xpm_to_img(v->mlx, "./assets/images/ui/normal_t.xpm");
	v->ps = mlx_xpm_to_img(v->mlx, "./assets/images/start/prods.xpm");
	v->ss = mlx_xpm_to_img(v->mlx, "./assets/images/start/start.xpm");
	v->wt = mlx_xpm_to_img(v->mlx, "./assets/images/textures/wall.xpm");
	v->fl = mlx_xpm_to_img(v->mlx, "./assets/images/textures/stone.xpm");
	v->cl = mlx_xpm_to_img(v->mlx, "./assets/images/textures/ceilling.xpm");
	v->hr = mlx_xpm_to_img(v->mlx, "./assets/images/ui/hardcore.xpm");
	v->hr_t = mlx_xpm_to_img(v->mlx, "./assets/images/ui/hardcore_t.xpm");
}

static void	draw_textured_floor_ceilling(t_var *v, double tx, double ty, int y)
{
	int		clr;
	int		t_x;
	int		t_y;
	double	dist;

	while (y < WIN_H)
	{
		v->val = (y < 466) ? .02 :
		((1.22 / (((y - 466.) / 100.) + .56)) - 0.18) / 100.;
		tx += cos(((v->p_r + v->ray) + 90.) * (PI / 180.)) * v->val;
		ty += sin(((v->p_r + v->ray) + 90.) * (PI / 180.)) * v->val;
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

void		draw_textured_wall(t_var *v, double tx, double ty, int y)
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
	draw_textured_floor_ceilling(v, tx, ty, 0);
}

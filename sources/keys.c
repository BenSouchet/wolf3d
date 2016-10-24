/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 15:36:51 by bsouchet          #+#    #+#             */
/*   Updated: 2016/10/24 19:32:16 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			player_transform(t_var *v)
{
	int		tmp;

	tmp = ((WIN_W - 214) / 2);
	if (v->mx >= 214 && v->mx < WIN_W && v->my >= 0 && v->my < WIN_H)
	{
		if (v->mx >= 214 && v->mx <= 284)
			v->add -= 3;
		if (v->mx >= (WIN_W - 70) && v->mx < WIN_W)
			v->add += 3;
		v->p_r = (((v->mx - (tmp + 213)) * 55) / tmp) + v->add;
	}
}

static void		key_detect_walls(t_var *v)
{
	if (v->map[I(v->posy)][I(v->posx) - 1][2] == '1')
		v->posx = (v->posx < I(v->posx) + .15) ? I(v->posx) + .15 : v->posx;
	if (v->map[I(v->posy)][I(v->posx) + 1][2] == '1')
		v->posx = (v->posx > I(v->posx) + .85) ? I(v->posx) + .85 : v->posx;
	if (v->map[I(v->posy) - 1][I(v->posx)][2] == '1')
		v->posy = (v->posy < I(v->posy) + .15) ? I(v->posy) + .15 : v->posy;
	if (v->map[I(v->posy) + 1][I(v->posx)][2] == '1')
		v->posy = (v->posy > I(v->posy) + .85) ? I(v->posy) + .85 : v->posy;
}

void			key_operations(t_var *v)
{
	if (v->h != 1 && v->t != 1)
		v->sp = (v->k[257] != 0 || v->k[258] != 0) ? 1.455 : 1.;
	else if (v->t != 1)
		v->sp = (v->k[257] != 0 || v->k[258] != 0) ? .565 : .4;
	else if (v->h != 1)
		v->sp = (v->k[257] != 0 || v->k[258] != 0) ? 1.755 : 1.55;
	else
		v->sp = (v->k[257] != 0 || v->k[258] != 0) ? 1.250 : 1.245;
	if (v->k[12] != 0 || v->k[123] != 0)
		v->p_r -= (v->t != 1 && v->h != 0) ? 2. : 3.5;
	if (v->k[14] != 0 || v->k[124] != 0)
		v->p_r += (v->t != 1 && v->h != 0) ? 2. : 3.5;
}

void			key_transform(t_var *v, double px, double py)
{
	if (v->k[0] != 0)
		v->posy -= cos((v->p_r - 90.) * (PI / 180.)) * (STEP_L * v->sp);
	if (v->k[0] != 0)
		v->posx += sin((v->p_r - 90.) * (PI / 180.)) * (STEP_L * v->sp);
	if (v->k[2] != 0)
		v->posy += cos((v->p_r - 90.) * (PI / 180.)) * (STEP_L * v->sp);
	if (v->k[2] != 0)
		v->posx -= sin((v->p_r - 90.) * (PI / 180.)) * (STEP_L * v->sp);
	px = v->posx;
	py = v->posy;
	if (v->k[1] != 0 || v->k[125] != 0)
		py += cos(v->p_r * (PI / 180.)) * (STEP_L * v->sp);
	v->posy = (v->map[(int)py][(int)v->posx][2] != '1') ? py : v->posy;
	if (v->k[1] != 0 || v->k[125] != 0)
		px -= sin(v->p_r * (PI / 180.)) * (STEP_L * v->sp);
	v->posx = (v->map[(int)v->posy][(int)px][2] != '1') ? px : v->posx;
	if (v->k[13] != 0 || v->k[126] != 0)
		py -= cos(v->p_r * (PI / 180.)) * (STEP_L * v->sp);
	v->posy = (v->map[(int)py][(int)v->posx][2] != '1') ? py : v->posy;
	if (v->k[13] != 0 || v->k[126] != 0)
		px += sin(v->p_r * (PI / 180.)) * (STEP_L * v->sp);
	v->posx = (v->map[(int)v->posy][(int)px][2] != '1') ? px : v->posx;
	key_detect_walls(v);
}

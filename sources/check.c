/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/10 15:12:45 by bsouchet          #+#    #+#             */
/*   Updated: 2016/10/06 15:56:01 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			start_screen(t_var *v)
{
	if (v->start == 0 && v->loop++ <= 150)
		;
	if (v->loop == 150 && (v->loop = 0) == 0)
		v->start++;
}

static int		ft_sizeline(char *str, int pos)
{
	int		counter;

	counter = 0;
	while (str[pos] != 0 && str[pos] != '\n')
	{
		pos++;
		counter++;
	}
	return (counter);
}

static int		find_player(t_var *v, char c, int x, int y)
{
	int		i;
	int		counter;

	i = -1;
	counter = 0;
	while (v->buf[++i] != 0)
	{
		if (v->buf[i] == 10 && ++y != 0)
			x = 0;
		else if (v->buf[i] == c && ++counter != 0)
		{
			v->p_x = ((double)x - 0.5);
			v->p_y = ((double)y + 0.5);
			v->p_r = 0.;
		}
		x++;
	}
	return (counter);
}

int				check(t_var *v)
{
	int		pos;

	v->i = -1;
	v->y = 0;
	if (ft_checkstr(v->buf, "01X\n") == 1 || find_player(v, 'X', 0, 0) != 1)
		return (error(v, 5, 2));
	v->wth = ft_sizeline(v->buf, 0);
	while (++v->i > -1 && v->y < v->lns && (pos = 0) == 0)
	{
		if (v->y != 0 && ft_sizeline(v->buf, v->i) != v->wth)
			return (error(v, 5, 2));
		while (v->buf[v->i] != 0 && v->buf[v->i] != '\n')
		{
			if (((v->y == 0 || v->y == (v->lns - 1)) && v->buf[v->i] != '1') ||
			((pos == 0 || pos == (v->wth - 1)) && v->buf[v->i] != '1'))
				return (error(v, 5, 2));
			pos++;
			v->i++;
		}
		v->y++;
	}
	return (0);
}

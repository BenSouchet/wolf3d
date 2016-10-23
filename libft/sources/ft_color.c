/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 19:06:33 by bsouchet          #+#    #+#             */
/*   Updated: 2016/10/19 18:56:29 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_gt_colors(int clr1, int clr2, double val)
{
	int		r;
	int		g;
	int		b;

	if (val > 1.0)
		val = 1.0;
	else if (val < 0.0)
		val = 0.0;
	r = floor(D((clr1 >> 16) & 0xFF) -
	((D((clr1 >> 16) & 0xFF) - D((clr2 >> 16) & 0xFF)) * val));
	g = floor(D((clr1 >> 8) & 0xFF) -
	((D((clr1 >> 8) & 0xFF) - D((clr2 >> 8) & 0xFF)) * val));
	b = floor(D((clr1) & 0xFF) - ((D((clr1) & 0xFF) - D((clr2) & 0xFF)) * val));
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}

int			ft_shade_color(int clr, double val)
{
	int		r;
	int		g;
	int		b;

	if (val > 1.0)
		val = 1.0;
	else if (val < 0.0)
		val = 0.0;
	r = floor(D((clr >> 16) & 0xFF) + D((0.0 - D((clr >> 16) & 0xFF)) * val));
	g = floor(D((clr >> 8) & 0xFF) + D((0.0 - D((clr >> 8) & 0xFF)) * val));
	b = floor(D((clr) & 0xFF) + D((0.0 - D((clr) & 0xFF)) * val));
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}

int			ft_add_ao(int clr, double percent)
{
	double	intensity;

	if (percent >= 0. && percent <= 10.)
	{
		intensity = ((1.4 / (((percent * 25.) / 100.) + 1.)) - 0.4);
		intensity /= 5.;
		clr = ft_shade_color(clr, intensity);
	}
	else if (percent >= 90. && percent <= 100. && (percent -= 90.) != -1)
	{
		intensity = ((1.4 / (-((percent * 25.) / 100.) + 3.5)) - 0.4);
		intensity /= 5.;
		clr = ft_shade_color(clr, intensity);
	}
	return (clr);
}

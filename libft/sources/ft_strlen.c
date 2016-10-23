/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 18:59:16 by bsouchet          #+#    #+#             */
/*   Updated: 2016/06/20 15:50:02 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strlen(char *str)
{
	int		i;

	i = -1;
	while (str[++i] != 0)
		;
	return (i);
}

int		ft_strlen_wspace(char *str)
{
	int		i;
	int		counter;

	i = -1;
	counter = 0;
	while (str[++i] != 0)
		if (str[i] != 32)
			counter++;
	return (counter);
}

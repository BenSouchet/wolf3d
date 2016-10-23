/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 18:58:04 by bsouchet          #+#    #+#             */
/*   Updated: 2016/09/07 13:27:52 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_strjoin_free(char *s1, char *s2, int type)
{
	if (type == 'L')
		free(s1);
	else if (type == 'R')
		free(s2);
	else if (type == 'B')
	{
		free(s1);
		free(s2);
	}
}

char		*ft_strjoin(char *s1, char *s2, char type)
{
	char	*n;
	int		i[2];

	i[0] = 0;
	while (s1[i[0]])
		i[0]++;
	i[1] = 0;
	while (s2[i[1]])
		i[1]++;
	n = (char *)malloc(sizeof(char) * (i[0] + i[1] + 1));
	i[0] = -1;
	while (s1[++i[0]])
		n[i[0]] = s1[i[0]];
	i[1] = -1;
	while (s2[++i[1]])
		n[i[0] + i[1]] = s2[i[1]];
	ft_strjoin_free(s1, s2, type);
	n[i[0] + i[1]] = '\0';
	return (n);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_dir_name.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/22 16:53:42 by bsouchet          #+#    #+#             */
/*   Updated: 2016/06/22 16:54:01 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_del_dir_name(char *file)
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	len = 0;
	len = ft_strlen(file);
	while (--len > 0 && file[len] != '/')
		i++;
	str = (char *)malloc(sizeof(char) * ++i);
	i = 0;
	while (++len < ft_strlen(file))
		str[i++] = file[len];
	str[i] = 0;
	return (str);
}

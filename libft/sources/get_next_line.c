/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/18 16:55:00 by bsouchet          #+#    #+#             */
/*   Updated: 2016/09/10 15:48:38 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		resultat(char **line, char *buf_save)
{
	char		*eol;

	eol = ft_strchr(buf_save, '\n');
	if (NULL != eol)
	{
		*eol = '\0';
		*line = ft_strdup(buf_save);
		ft_memmove(buf_save, &eol[1], ft_strlen(&eol[1]) + 1);
		return (1);
	}
	if (0 < ft_strlen(buf_save))
	{
		*line = ft_strdup(buf_save);
		*buf_save = '\0';
		return (1);
	}
	return (0);
}

int		get_next_line(int const fd, char **line)
{
	static char	*buf_save = NULL;
	char		buffer[BUFF_SIZE + 1];
	char		*line_tmp;
	int			ret;

	if (NULL == line || fd < 0 || BUFF_SIZE <= 0)
		return (-1);
	if (NULL == buf_save)
		buf_save = (char *)malloc(sizeof(char));
	while (!ft_strchr(buf_save, '\n'))
	{
		ret = read(fd, buffer, BUFF_SIZE);
		if (ret == -1)
			return (-1);
		if (0 == ret)
			break ;
		buffer[ret] = '\0';
		line_tmp = ft_strjoin(buf_save, buffer, 'L');
		buf_save = line_tmp;
	}
	return (resultat(line, buf_save));
}

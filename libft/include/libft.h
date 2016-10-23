/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 13:30:40 by bsouchet          #+#    #+#             */
/*   Updated: 2016/10/19 18:56:20 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <math.h>

# define BUFF_SIZE 1

# define D (double)

# define AO 0x000000

char			*ft_del_dir_name(char *file);

char			*ft_itoa(int n);

int				ft_checkstr(char *s1, char *s2);

void			*ft_memcpy(void *dst, void *src, size_t len);

void			*ft_memmove(void *dst, void *src, size_t len);

char			*ft_strchr(char *str, int c);

int				ft_strlen(char *str);

int				ft_strlen_wspace(char *str);

char			*ft_strjoin(char *s1, char *s2, char type);

char			*ft_strdup(char *str);

int				ft_strchr_at_end(char *str, char *find);

int				get_next_line(int fd, char **line);

int				ft_shade_color(int clr, double val);

int				ft_gt_colors(int clr1, int clr2, double val);

int				ft_add_ao(int clr, double percent);

#endif

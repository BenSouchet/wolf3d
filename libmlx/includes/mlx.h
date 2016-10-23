/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 11:16:33 by bsouchet          #+#    #+#             */
/*   Updated: 2016/09/22 19:30:18 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_H
# define MLX_H

void		*mlx_init();

void		*mlx_new_win(void *mlx_ptr, int pos_x, int pos_y,
			int size_x, int size_y, char *title);

int			mlx_width_screen(void);

int         mlx_clear_img(void *img, int clr);
int			mlx_clear_win(void *mlx_ptr, void *win_ptr);

int			mlx_put_pixel(void *img, int x, int y, int clr);

void		*mlx_new_img(void *mlx_ptr,int width,int height, int clr);
char		*mlx_get_data_addr(void *img_ptr, int *bits_per_pixel,
			int *size_line, int *endian);

int			mlx_put_img_to_win(void *mlx_ptr, void *win_ptr,
			void *img_ptr, int x, int y);

unsigned    mlx_get_color_value(void *mlx_ptr, int color);

int         mlx_get_pixel_clr(void *img, int x, int y);

int		    mlx_mouse_hook(void *win_ptr, int (*funct_ptr)(), void *param);
int			mlx_key_hook(void *win_ptr, int (*funct_ptr)(), void *param);
int			mlx_expose_hook(void *win_ptr, int (*funct_ptr)(), void *param);

int			mlx_loop_hook(void *mlx_ptr, int (*funct_ptr)(), void *param);
int			mlx_loop(void *mlx_ptr);

int			mlx_put_str(void *mlx, void *win, int x, int y, int clr,
            char *str);

void		*mlx_xpm_to_image(void *mlx_ptr, char **xpm_data,
			int *width, int *height);
void		*mlx_xpm_to_img(void *mlx_ptr, char *filename);

int			mlx_destroy_win(void *mlx_ptr, void *win_ptr);

int			mlx_destroy_img(void *mlx_ptr, void *img_ptr);

int			mlx_hook(void *win_ptr, int x_event, int x_mask,
			int (*funct)(), void *param);

int			mlx_do_key_autorepeatoff(void *mlx_ptr);
int			mlx_do_key_autorepeaton(void *mlx_ptr);
int			mlx_do_sync(void *mlx_ptr);

#endif

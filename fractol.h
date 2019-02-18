/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-gac- <tle-gac-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 20:26:15 by tle-gac-          #+#    #+#             */
/*   Updated: 2018/01/15 20:56:01 by tle-gac-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>

# include "./libft/includes/libft.h"
# include <stdlib.h>
# include <math.h>
# include "./minilibx_macos/mlx.h"
# include <errno.h>
# include <pthread.h>
# define MALLOC_ERR "Error : malloc failed.\n"
# define MLX_ERR "Error : MiniLibX failed.\n"
# define WIN_X 1000
# define WIN_Y 1000

typedef struct		s_point
{
	double			x;
	double			y;
}					t_point;

typedef struct		s_int_point
{
	int				x;
	int				y;
}					t_int_point;

typedef struct		s_color
{
	int				red;
	int				green;
	int				blue;
}					t_color;

typedef struct		s_img
{
	void			*imgptr;
	int				*data;
	int				bits_per_pixel;
	int				pixel_per_line;
	int				endian;
}					t_img;

typedef struct		s_lock
{
	int				locked;
	double			x;
	double			y;
}					t_lock;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	t_img			img;
	t_point			center;
	double			win_size;
	int				button_held;
	double			max_iter;
	int				shift;
	int				palette;
	t_int_point		mouse_pos;
	int				display;
	t_lock			lock;
	int				psyched;
	int				help;
}					t_env;

typedef struct		s_draw_part
{
	t_int_point		a;
	t_int_point		b;
}					t_draw_part;

int					keyhook(int keycode, void *tmp);
int					mousehook(int button, int x, int y, void *tmp);
int					mouse_release_hook(int button, int x, int y, void *env);
int					mouse_move(int x, int y, void *tmp);
void				initiate_img(t_img *img, void *mlx);
void				exit_error(char *str);
t_env				*setup(void);
void				*draw(void *quarter);
void				put_pixel(int x, int y, t_img *img, int colour);
void				draw_window(t_env *env);
void				iterate_julia(int i, int j, t_env *env, unsigned int iter);
void				iterate_ship(int i, int j, t_env *env, unsigned int iter);
t_color				**palettes();
void				reset(t_env *env);
int					get_colors(double exact, t_env *env);
void				send_halp(void);

#endif

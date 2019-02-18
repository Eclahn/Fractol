/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-gac- <tle-gac-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 15:43:19 by tle-gac-          #+#    #+#             */
/*   Updated: 2018/01/15 18:54:58 by tle-gac-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	initiate_img(t_img *img, void *mlx)
{
	int		i;

	i = 0;
	if (!img->imgptr)
	{
		if (!(img->imgptr = mlx_new_image(mlx, WIN_X, WIN_Y)))
			exit_error(MLX_ERR);
		img->data = (int*)mlx_get_data_addr(img->imgptr, &(img->bits_per_pixel),
									&(img->pixel_per_line), &(img->endian));
	}
	else
		ft_bzero(img->data, WIN_X * WIN_Y * 8);
}

void	reset(t_env *env)
{
	env->max_iter = 24.0;
	env->center.x = -0.5;
	env->center.y = 0;
	env->win_size = 4.0;
	env->shift = 0;
	env->lock.locked = 0;
}

t_env	*setup(void)
{
	static	t_env *env = NULL;

	if (env)
		return (env);
	if (!(env = malloc(sizeof(t_env)))
			|| !(env->mlx = mlx_init()))
		exit_error((!env) ? MALLOC_ERR : MLX_ERR);
	env->img.imgptr = NULL;
	env->button_held = 0;
	env->center.x = -0.5;
	env->center.y = 0;
	env->win_size = 4.0;
	env->max_iter = 24.0;
	env->shift = 0;
	env->palette = 0;
	env->display = 0;
	env->lock.locked = 0;
	env->psyched = 0;
	env->help = 1;
	if (!(env->win = mlx_new_window(env->mlx, WIN_X, WIN_Y, "fractol")))
		exit_error(MLX_ERR);
	return (env);
}

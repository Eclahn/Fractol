/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-gac- <tle-gac-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 21:20:56 by tle-gac-          #+#    #+#             */
/*   Updated: 2018/01/15 21:11:35 by tle-gac-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	keyhook_norme(int keycode, t_env *env)
{
	if (keycode >= 18 && keycode <= 20)
	{
		reset(env);
		env->display = keycode - 18;
	}
	else if (keycode == 37)
	{
		env->lock.locked = env->lock.locked == 0 ? 1 : 0;
		env->lock.x = env->center.x + (env->mouse_pos.x - WIN_X / 2) * \
					env->win_size / 2 / WIN_X;
		env->lock.y = env->center.y + (env->mouse_pos.y - WIN_Y / 2) * \
					env->win_size / 2 / WIN_Y;
	}
	else if (keycode == 49)
		reset(env);
	else if (keycode == 67)
		env->psyched = env->psyched == 0 ? 1 : 0;
	else if (keycode == 4)
		env->help = env->help == 1 ? 0 : 1;
}

int		keyhook(int keycode, void *tmp)
{
	t_env	*env;

	env = (t_env*)tmp;
	if (keycode == 0x35)
		exit(0);
	else if (keycode == 48)
	{
		env->shift += 10;
		if (env->shift >= 768)
			env->shift -= 768;
	}
	else if (keycode >= 12 && keycode <= 14)
		env->palette = keycode - 12;
	else if (keycode == 69 || keycode == 78)
		env->max_iter += (keycode == 69 ? 3 : -3);
	keyhook_norme(keycode, env);
	draw_window(env);
	return (0);
}

int		mousehook(int button, int x, int y, void *tmp)
{
	t_env	*env;
	float	multi;

	env = ((t_env*)tmp);
	if (button && y > 2)
	{
		mlx_clear_window(env->mlx, env->win);
		if (button == 4 || (button == 5 && env->win_size < 16.0))
		{
			multi = button == 4 ? 1.0 / 1.5 : 1.5;
			env->center.x += ((x - WIN_X / 2) * (env->win_size - \
						env->win_size * multi) / 2) / WIN_X;
			env->center.y += ((y - WIN_Y / 2) * (env->win_size - \
						env->win_size * multi) / 2) / WIN_Y;
			env->win_size *= multi;
			env->max_iter += button == 4 ? 3.0 : -3.0;
		}
		else if (button == 1)
			env->button_held = 1;
		draw_window(env);
	}
	return (0);
}

int		mouse_release_hook(int button, int x, int y, void *env)
{
	(void)x;
	(void)y;
	(void)button;
	((t_env*)env)->button_held = 0;
	return (0);
}

int		mouse_move(int x, int y, void *tmp)
{
	t_env	*env;

	env = ((t_env*)tmp);
	if (env->button_held == 1)
	{
		mlx_clear_window(env->mlx, env->win);
		env->center.x -= (x - env->mouse_pos.x) * env->win_size / 2 / WIN_X;
		env->center.y -= (y - env->mouse_pos.y) * env->win_size / 2 / WIN_Y;
		draw_window(env);
	}
	env->mouse_pos.x = x;
	env->mouse_pos.y = y;
	if (env->display == 1 && env->lock.locked == 0)
	{
		mlx_clear_window(env->mlx, env->win);
		draw_window(env);
	}
	return (0);
}

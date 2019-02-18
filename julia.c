/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-gac- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 14:34:30 by tle-gac-          #+#    #+#             */
/*   Updated: 2018/01/15 20:25:29 by tle-gac-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	iterate_julia(int i, int j, t_env *env, unsigned int iter)
{
	t_point				c;
	t_point				z;
	double				exact;

	c.x = env->lock.locked == 0 ? env->center.x + (env->mouse_pos.x - \
			WIN_X / 2) * env->win_size / 2 / WIN_X : env->lock.x;
	c.y = env->lock.locked == 0 ? env->center.y + (env->mouse_pos.y - \
			WIN_Y / 2) * env->win_size / 2 / WIN_Y : env->lock.y;
	z.x = env->center.x + (i - WIN_X / 2) * env->win_size / 2 / WIN_X;
	z.y = env->center.y + (j - WIN_Y / 2) * env->win_size / 2 / WIN_Y;
	while (++iter < env->max_iter && z.x * z.x + z.y * z.y <= 4.0)
	{
		exact = z.x * z.x - z.y * z.y + c.x;
		z.y = 2 * z.x * z.y + c.y;
		z.x = exact;
	}
	if (iter < env->max_iter)
	{
		exact = (iter + 1 - ((log((log(z.x * z.x + z.y * z.y)) * 0.5)) - \
					log(0.5 * log(2))) / log(2)) * 768.0 / env->max_iter;
		exact = exact >= 0 && exact <= 768.0 ? exact : 0;
		put_pixel(i, j, &(env->img), get_colors(exact, env));
	}
	else
		put_pixel(i, j, &(env->img), env->palette == 1 ? 0xFFFFFF : 0);
}

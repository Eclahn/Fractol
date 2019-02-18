/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-gac- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 21:28:42 by tle-gac-          #+#    #+#             */
/*   Updated: 2018/01/15 17:12:58 by tle-gac-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	iterate_ship(int i, int j, t_env *env, unsigned int iter)
{
	t_point				c;
	t_point				pt;
	double				exact;

	c.x = env->center.x + (i - WIN_X / 2) * env->win_size / 2 / WIN_X;
	c.y = env->center.y + (j - WIN_Y / 2) * env->win_size / 2 / WIN_Y;
	pt.x = 0;
	pt.y = 0;
	while (pt.x * pt.x + pt.y * pt.y <= 4.0 && ++iter < env->max_iter)
	{
		exact = pt.x * pt.x - pt.y * pt.y + c.x;
		pt.y = fabs(2 * pt.x * pt.y + c.y);
		pt.x = fabs(exact);
	}
	if (iter < env->max_iter)
	{
		exact = (iter + 1 - ((log((log(pt.x * pt.x + pt.y * pt.y)) * 0.5)) - \
					log(0.5 * log(2))) / log(2)) * 768.0 / env->max_iter;
		exact = exact >= 0 && exact <= 768.0 ? exact : 0;
		put_pixel(i, j, &(env->img), get_colors(exact, env));
	}
	else
		put_pixel(i, j, &(env->img), env->palette == 1 ? 0xFFFFFF : 0);
}

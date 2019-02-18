/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-gac- <tle-gac-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 13:51:23 by tle-gac-          #+#    #+#             */
/*   Updated: 2018/01/15 17:31:12 by tle-gac-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel(int x, int y, t_img *img, int colour)
{
	if (x >= 0 && x < WIN_X && y >= 0 && y < WIN_Y)
		img->data[x + (img->pixel_per_line * y) / 4] = colour;
}

int		get_colors(double exact, t_env *env)
{
	t_color	res;
	t_color	a;
	t_color	b;
	t_color	**schemes;

	schemes = palettes();
	a = schemes[env->palette][((int)exact + env->shift) % 768];
	b = schemes[env->palette][((int)(exact + 1.0) + env->shift) % 768];
	exact = exact - floor(exact);
	res.red = (double)a.red * (1.0 - exact) + (double)b.red * exact;
	res.green = (double)a.green * (1.0 - exact) + (double)b.green * exact;
	res.blue = (double)a.blue * (1.0 - exact) + (double)b.blue * exact;
	return ((res.red << 16) + (res.green << 8) + res.blue);
}

void	iterate_mandelbrot(int i, int j, t_env *env, unsigned int iter)
{
	t_point			c;
	t_point			z;
	double			exact;

	c.x = env->center.x + (i - WIN_X / 2) * env->win_size / 2 / WIN_X;
	c.y = env->center.y + (j - WIN_Y / 2) * env->win_size / 2 / WIN_Y;
	z.x = 0;
	z.y = 0;
	while (z.x * z.x + z.y * z.y <= 4.0 && ++iter < env->max_iter)
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

void	*draw(void *q)
{
	int				j;
	t_draw_part		*quarter;
	static void		(*fun[3]) (int i, int j, t_env *env, unsigned int iter) =\
	{iterate_mandelbrot, iterate_julia, iterate_ship};

	quarter = (t_draw_part*)q;
	quarter->a.x -= 1;
	while (++quarter->a.x < quarter->b.x)
	{
		j = quarter->a.y - 1;
		while (++j < quarter->b.y)
			fun[setup()->display](quarter->a.x, j, setup(), -1);
	}
	return (q);
}

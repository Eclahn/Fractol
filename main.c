/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-gac- <tle-gac-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 20:23:37 by tle-gac-          #+#    #+#             */
/*   Updated: 2018/01/15 20:53:40 by tle-gac-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		loophook(void *tmp)
{
	t_env	*env;

	env = (t_env*)tmp;
	if (env->psyched == 1)
	{
		env->shift = (env->shift + 20) % 768;
		draw_window(env);
	}
	return (0);
}

void	exit_error(char *str)
{
	ft_putstr(str);
	exit(errno);
}

void	exit_usage(void)
{
	ft_putstr("Error : Usage : ./fractol [Mandelbrot | Julia | BurningShip]\n");
	exit(errno);
}

void	draw_window(t_env *env)
{
	t_draw_part		*quarter;
	pthread_t		threads[8];
	int				i;

	i = -1;
	quarter = malloc(sizeof(t_draw_part) * 8);
	while (++i < 8)
	{
		quarter[i].a.x = i * WIN_X / 8;
		quarter[i].a.y = 0;
		quarter[i].b.x = (i + 1) * WIN_X / 8;
		quarter[i].b.y = WIN_Y;
	}
	i = -1;
	while (++i < 8)
		pthread_create(&threads[i], NULL, draw, &quarter[i]);
	i = -1;
	while (++i < 8)
		pthread_join(threads[i], NULL);
	free(quarter);
	mlx_put_image_to_window(env->mlx, env->win, env->img.imgptr, 0, 0);
	if (setup()->help == 1)
		send_halp();
}

int		main(int argc, char **argv)
{
	t_env		*env;

	(void)argv;
	if (argc != 2)
		exit_usage();
	env = setup();
	if (ft_strequ(argv[1], "Mandelbrot"))
		env->display = 0;
	else if (ft_strequ(argv[1], "Julia"))
		env->display = 1;
	else if (ft_strequ(argv[1], "BurningShip"))
		env->display = 2;
	else
		exit_usage();
	palettes();
	initiate_img(&(env->img), env->mlx);
	draw_window(env);
	mlx_hook(env->win, 2, 2, keyhook, env);
	mlx_hook(env->win, 4, 8, mousehook, env);
	mlx_hook(env->win, 5, 16, mouse_release_hook, env);
	mlx_hook(env->win, 6, 0, mouse_move, env);
	mlx_loop_hook(env->mlx, loophook, env);
	mlx_loop(env->mlx);
	return (0);
}

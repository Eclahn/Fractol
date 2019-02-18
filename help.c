/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-gac- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 18:32:52 by tle-gac-          #+#    #+#             */
/*   Updated: 2018/01/15 21:24:53 by tle-gac-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	send_halp(void)
{
	static char	*tab[12];
	int			i;
	t_env		*env;

	env = setup();
	i = 0;
	tab[0] = "Commands :";
	tab[1] = "1, 2, 3 : change set";
	tab[2] = "Q, W, E : change color scheme";
	tab[3] = "Numpad +, numpad - : increase/decrease iteration count";
	tab[4] = "Tab : shift color scheme";
	tab[5] = "Numpad * : turn on/off color waves";
	tab[6] = "Spacebar : reset fractal";
	tab[7] = "L : lock Julia";
	tab[8] = "Zoom in/out : mouse wheel";
	tab[9] = "Move : click & drag";
	tab[10] = "";
	tab[11] = "Show/mask help : H";
	while (i < 12)
	{
		mlx_string_put(env->mlx, env->win, 8, i * 15 - 1, \
				env->palette == 2 ? 0 : 0xFFFFFF, tab[i]);
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palettes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-gac- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 15:46:45 by tle-gac-          #+#    #+#             */
/*   Updated: 2018/01/15 17:26:12 by tle-gac-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_color		*bgr_palette(int i)
{
	t_color	*scheme;

	if (!(scheme = malloc(sizeof(t_color) * 768)))
		exit_error(MALLOC_ERR);
	while (++i < 768)
	{
		scheme[i].red = 0;
		scheme[i].green = 0;
		scheme[i].blue = 0;
		if (i >= 512)
		{
			scheme[i].red = i - 512;
			scheme[i].green = 255 - scheme[i].red;
		}
		else if (i >= 256)
		{
			scheme[i].green = i - 256;
			scheme[i].blue = 255 - scheme[i].green;
		}
		else
			scheme[i].blue = i;
	}
	return (scheme);
}

t_color		*lightning_palette(int i)
{
	t_color	*scheme;

	if (!(scheme = malloc(sizeof(t_color) * 768)))
		exit_error(MALLOC_ERR);
	while (++i < 768)
	{
		scheme[i].red = i / 3 - 1;
		scheme[i].green = i / 6;
		scheme[i].blue = (2 * i / 3 - 1) > 255 ? 255 : (2 * i / 3 - 1);
	}
	return (scheme);
}

t_color		*continuous_palette(int i)
{
	t_color	*scheme;

	if (!(scheme = malloc(sizeof(t_color) * 768)))
		exit_error(MALLOC_ERR);
	while (++i < 768)
	{
		if (i < 256 && ((scheme[i].red = 255 - i)))
		{
			scheme[i].green = i;
			scheme[i].blue = 255;
		}
		else if (i < 512)
		{
			scheme[i].red = i - 255;
			scheme[i].green = 255;
			scheme[i].blue = 511 - i;
		}
		else
		{
			scheme[i].red = 255;
			scheme[i].green = 767 - i;
			scheme[i].blue = i - 511;
		}
	}
	return (scheme);
}

t_color		**palettes(void)
{
	static t_color	**schemes = NULL;

	if (schemes)
		return (schemes);
	if (!(schemes = malloc(sizeof(t_color*) * 3)))
		exit_error(MALLOC_ERR);
	schemes[0] = bgr_palette(-1);
	schemes[1] = lightning_palette(-1);
	schemes[2] = continuous_palette(-1);
	return (schemes);
}

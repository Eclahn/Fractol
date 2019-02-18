/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-gac- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 12:44:35 by tle-gac-          #+#    #+#             */
/*   Updated: 2017/09/02 12:50:53 by tle-gac-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	ft_strreplace(char *str, int seek, int swap)
{
	char	*target;

	if ((target = ft_strchr(str, (char)seek)))
		*target = (char)swap;
}

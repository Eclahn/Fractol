/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-gac- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 16:28:54 by tle-gac-          #+#    #+#             */
/*   Updated: 2017/09/13 20:26:22 by tle-gac-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

/*
** f = first, l = last, b = both
*/

char	*ft_strappend(char **s1, char **s2, char del)
{
	char	*str;

	if (s1 && s2 && *s1 && *s2)
		str = ft_strjoin(*s1, *s2);
	else if (s2 && *s2)
		str = ft_strdup(*s2);
	else if (s1 && *s1)
		str = ft_strdup(*s1);
	else
		str = ft_strnew(0);
	if (del == 'f' || del == 'b')
		ft_strdel(s1);
	if (del == 'l' || del == 'b')
		ft_strdel(s2);
	return (str);
}

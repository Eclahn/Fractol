/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitwords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 17:30:13 by rghirell          #+#    #+#             */
/*   Updated: 2016/11/25 14:24:20 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_splitwords(char const *src, int *i, char c)
{
	int		a;
	char	*snd;

	a = 0;
	if (!(snd = ft_strnew(ft_strlen(src))))
		return (NULL);
	while (src[*i] == c)
		*i += 1;
	while (src[*i] != c && src[*i] != '\0')
	{
		snd[a] = src[*i];
		*i += 1;
		a++;
	}
	return (snd);
}

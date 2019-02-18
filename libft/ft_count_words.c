/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 17:33:20 by rghirell          #+#    #+#             */
/*   Updated: 2017/10/18 18:30:39 by tle-gac-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

int		ft_count_words(char const *src, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	if (src[0] != c && src[0] != '\0')
		count++;
	while (src[i])
	{
		if (src[i] == c && src[i + 1] != '\0' && src[i + 1] != c)
			count++;
		i++;
	}
	return (count);
}

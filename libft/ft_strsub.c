/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 16:37:10 by rghirell          #+#    #+#             */
/*   Updated: 2016/11/25 15:26:06 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*dst;
	size_t		i;
	size_t		j;

	j = 0;
	i = 0;
	dst = (char*)malloc(sizeof(*dst) * (len + 1));
	if (!dst || !s)
		return (NULL);
	while (s[start] != '\0' && j < len)
	{
		dst[i] = s[start];
		i++;
		start++;
		j++;
	}
	dst[i] = '\0';
	return (dst);
}

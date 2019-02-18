/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 17:36:52 by rghirell          #+#    #+#             */
/*   Updated: 2016/11/25 15:02:57 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strrchr(const char *s1, int c)
{
	int i;

	i = ft_strlen(s1);
	while (i >= 0)
	{
		if (s1[i] == (char)c)
			return ((char*)s1 + i);
		i--;
	}
	return (NULL);
}

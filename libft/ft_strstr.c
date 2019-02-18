/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 18:07:30 by rghirell          #+#    #+#             */
/*   Updated: 2016/11/25 14:57:38 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	if (*s2 == '\0')
		return ((char*)s1);
	if (s1 == s2)
		return ((char*)s1);
	while ((char)*s1)
	{
		if (ft_strncmp((char*)s1, (char*)s2, ft_strlen(s2)) == 0)
			return ((char*)s1);
		s1++;
	}
	return (NULL);
}

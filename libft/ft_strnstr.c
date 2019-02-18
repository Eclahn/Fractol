/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 10:43:25 by rghirell          #+#    #+#             */
/*   Updated: 2016/11/25 15:02:04 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	if (s1 == s2)
		return ((char*)s1);
	while (*s1 && i < n)
	{
		if (ft_strncmp(s1, s2, ft_strlen(s2)) == 0 && i < n
				&& ft_strlen(s2) <= n - i)
			return ((char*)s1);
		s1++;
		i++;
	}
	return (NULL);
}

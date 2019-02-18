/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 17:18:34 by rghirell          #+#    #+#             */
/*   Updated: 2016/12/05 15:56:00 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"
#include <stdio.h>

char	*ft_strtrim(char const *s)
{
	size_t a;
	size_t b;
	size_t min;
	size_t len;

	a = 0;
	b = 0;
	if (!s)
		return (NULL);
	while (s[b] != '\0')
		b++;
	while ((s[a] == ' ' || s[a] == '\n' || s[a] == '\t') && s[a] != '\0')
		a++;
	min = a;
	while ((s[b - 1] == ' ' || s[b - 1] == '\n' || s[b - 1] == '\t') && b > a)
		b--;
	len = b - a;
	return (ft_strsub(s, a, len));
}

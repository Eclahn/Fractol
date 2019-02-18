/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 14:21:07 by rghirell          #+#    #+#             */
/*   Updated: 2016/12/05 15:50:08 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"
#include <stdio.h>

static int			count_size(int n)
{
	int i;

	i = 0;
	if (n < 0)
		n *= -1;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char				*ft_itoa(int n)
{
	char	*dst;
	int		i;
	int		c;

	c = count_size(n);
	i = 0;
	if (n == -2147483648)
		return ((dst = ft_strdup("-2147483648")));
	if (n < 0 || c == 0)
		c++;
	if (!(dst = ft_strnew(c)))
		return (NULL);
	if (n < 0)
	{
		n *= -1;
		dst[0] = '-';
		i++;
	}
	while (c > i)
	{
		c--;
		dst[c] = (n % 10) + '0';
		n /= 10;
	}
	return (dst);
}

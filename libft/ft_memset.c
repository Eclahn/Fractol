/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 19:10:54 by rghirell          #+#    #+#             */
/*   Updated: 2016/11/25 14:14:11 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *s1;

	s1 = ((unsigned char *)b);
	while (len--)
	{
		*s1 = (unsigned char)c;
		s1++;
	}
	return (unsigned char *)b;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_bits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 16:41:54 by rghirell          #+#    #+#             */
/*   Updated: 2016/12/05 15:52:32 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

#include <stdio.h>

unsigned char	ft_reverse_bits(unsigned char octet)
{
	octet = (octet & 0xF0) >> 4 | (octet & 0x0F) << 4;
	octet = (octet & 0xCC) >> 2 | (octet & 0x33) << 2;
	octet = (octet & 0xAA) >> 1 | (octet & 0x55) << 1;
	return (octet);
}

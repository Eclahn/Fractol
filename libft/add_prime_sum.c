/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 15:40:49 by rghirell          #+#    #+#             */
/*   Updated: 2016/12/05 15:49:06 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

static int	ft_is_prime(int nbr)
{
	int i;

	i = 3;
	if (nbr == 2)
		return (1);
	if (nbr % 2 == 0)
		return (0);
	while (i * i <= nbr)
	{
		if (nbr % i == 0)
			return (0);
		i++;
	}
	return (1);
}

static void	add_prime_sum(int nbr)
{
	int i;
	int count;

	i = 2;
	count = 0;
	while (i <= nbr)
	{
		if (ft_is_prime(i))
			count = count + i;
		i++;
	}
	ft_putnbr(count);
}

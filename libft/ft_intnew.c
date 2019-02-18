/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 14:02:38 by rghirell          #+#    #+#             */
/*   Updated: 2016/12/15 18:23:55 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	*ft_intnew(size_t size)
{
	int				*tab;
	unsigned int	i;

	i = 0;
	tab = malloc(sizeof(int) * (size + 1));
	if (!tab)
		return (NULL);
	while (size--)
	{
		tab[i] = '\0';
		i++;
	}
	return (tab);
}

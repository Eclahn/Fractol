/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 17:04:59 by rghirell          #+#    #+#             */
/*   Updated: 2016/12/05 15:51:53 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	ft_putlist(t_list **begin_list)
{
	t_list *list_i;

	list_i = *begin_list;
	while (list_i)
	{
		ft_putstr(list_i->content);
		write(1, "\n", 1);
		ft_putnbr(list_i->content_size);
		write(1, "\n", 1);
		list_i = list_i->next;
	}
}

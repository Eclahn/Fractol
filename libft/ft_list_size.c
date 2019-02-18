/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 18:33:17 by rghirell          #+#    #+#             */
/*   Updated: 2016/11/30 10:34:17 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

int	ft_list_size(t_list *begin_list)
{
	if (begin_list)
		return (ft_list_size(begin_list->next) + 1);
	return (0);
}

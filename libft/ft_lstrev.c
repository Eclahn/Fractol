/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 10:45:07 by rghirell          #+#    #+#             */
/*   Updated: 2016/11/25 13:53:20 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	ft_lstrev(t_list **alst)
{
	t_list	*next;
	t_list	*prev;
	t_list	*current;

	if (*alst != NULL)
	{
		current = *alst;
		prev = NULL;
		while (current != NULL)
		{
			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}
		*alst = prev;
	}
}

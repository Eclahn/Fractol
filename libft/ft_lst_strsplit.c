/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_strsplit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghirell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 10:38:38 by rghirell          #+#    #+#             */
/*   Updated: 2016/12/05 15:51:26 by rghirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

static int	ft_splitwords_count(char const *src, int *i, char c)
{
	int		a;
	char	*snd;

	a = 0;
	if (!(snd = ft_strnew(ft_strlen(src))))
		return (0);
	while (src[*i] == c)
		*i += 1;
	while (src[*i] != c && src[*i] != '\0')
	{
		snd[a] = src[*i];
		*i += 1;
		a++;
	}
	free(snd);
	return ((a) + 1);
}

t_list		*ft_lst_strsplit(char const *s, char c)
{
	t_list	*list;
	t_list	*tmp;
	int		i;
	int		k;
	int		a;

	a = 0;
	k = 0;
	i = 1;
	if (s[0] == '\0')
		return (NULL);
	list = ft_lstnew(ft_splitwords(s, &k, c), ft_splitwords_count(s, &a, c));
	tmp = list;
	while (i < ft_count_words(s, c))
	{
		tmp = tmp->next;
		tmp = ft_lstnew(ft_splitwords(s, &k, c), ft_splitwords_count(s, &a, c));
		ft_list_add_last(&list, tmp);
		i++;
	}
	return (list);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-gac- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 13:42:31 by tle-gac-          #+#    #+#             */
/*   Updated: 2017/10/20 14:43:01 by tle-gac-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"
#include <stdio.h>
#include <limits.h>

/*
** limits.h :
** http://pubs.opengroup.org/onlinepubs/009695399/basedefs/limits.h.html
*/

char	**get_buf(int fd)
{
	static char		**buf_array[OPEN_MAX + 1] = { NULL };

	if (!buf_array[fd])
	{
		buf_array[fd] = malloc(sizeof(char**));
		*buf_array[fd] = NULL;
	}
	return (buf_array[fd]);
}

int		seriously_norme_wtf(int ret, char **line, char *buf)
{
	ft_strdel(&buf);
	return ((ret < 0) ? -1 : *line != NULL);
}

int		get_next_line(const int fd, char **line)
{
	char			*buf;
	int				newline;
	int				ret;
	char			**rd;

	newline = 0;
	if (!(buf = ft_strnew(BUFF_SIZE)) || fd < 0 || fd > OPEN_MAX || !line)
		return (-1);
	*line = NULL;
	rd = get_buf(fd);
	while (newline != 1)
	{
		ret = read(fd, buf, BUFF_SIZE);
		*rd = ft_strappend(rd, &buf, 'f');
		if (ret < 0 || (ret == 0 && !ft_strlen(*rd)))
			return (seriously_norme_wtf(ret, line, buf));
		newline = (ft_strchr(*rd, '\n') || ret < BUFF_SIZE);
		ft_strreplace(*rd, '\n', '\0');
		*line = ft_strappend(line, rd, 'f');
		ft_strclr((!newline) ? *rd : NULL);
		ft_strclr(buf);
	}
	ft_strclr(ft_strcpy(*rd, *rd + ft_strlen(*rd) + 1) + ft_strlen(*rd) + 2);
	ft_strdel(&buf);
	return (1);
}

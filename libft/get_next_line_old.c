/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_old.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 19:23:30 by gjigglyp          #+#    #+#             */
/*   Updated: 2021/01/16 16:35:57 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				proff(const int fd, char **line, char **copydoc)
{
	if (fd < 0 || !line || fd > 200000)
		return (-1);
	if (!(*copydoc))
		if (!(*copydoc = ft_strnew(1)))
			return (-1);
	return (0);
}

void			copy_doc(int ret, char *buf, char **copydoc)
{
	char		*tmp;

	buf[ret] = '\0';
	tmp = *copydoc;
	*copydoc = ft_strjoin(*copydoc, buf);
	free(tmp);
}

int				write_doc(char **line, char **copydoc, char *i)
{
	char		*tmp;

	(*line) = ft_strndup(*copydoc, (i - *copydoc));
	tmp = *copydoc;
	*copydoc = ft_strdup(i + 1);
	free(tmp);
	return (1);
}

int				write_last(char **line, char **copydoc)
{
	(*line) = ft_strdup(*copydoc);
	*copydoc = ft_strnew(0);
	return (1);
}

int				get_next_line_old(const int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	char		*copydoc[200000];
	int			ret;
	char		*i;

	if (proff(fd, line, &(copydoc[fd])) == -1)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		copy_doc(ret, buf, &(copydoc[fd]));
		if (ft_strchr(buf, '\n') != 0)
			break ;
	}
	if (ret < 0)
		return (-1);
	if (ft_strlen(copydoc[fd]) > 0)
	{
		if ((i = ft_strchr(copydoc[fd], '\n')) > 0)
			return (write_doc(line, &(copydoc[fd]), i));
		else
			return (write_last(line, &(copydoc[fd])));
	}
	ft_strdel(&copydoc[fd]);
	return (0);
}

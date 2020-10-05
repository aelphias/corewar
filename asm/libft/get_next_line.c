/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qweissna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 14:04:47 by qweissna          #+#    #+#             */
/*   Updated: 2020/01/28 14:04:50 by qweissna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		freedom(char *buf, int n)
{
	free(buf);
	return (n);
}

static t_list	*fill_list(t_list **doc, int fd)
{
	t_list *tmp;

	tmp = *doc;
	while (tmp)
	{
		if (tmp->content_size == (size_t)fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = (t_list *)malloc(sizeof(t_list));
	tmp->content_size = fd;
	tmp->content = ft_strnew(0);
	ft_lstadd(doc, tmp);
	return (tmp);
}

static int		dont_forget_line(char **line, t_list *tmp, char *buf, int ret)
{
	char *tmp_l;

	ret == 0 ? free(buf) : 0;
	if (tmp->content == NULL)
		return (0);
	tmp_l = ft_strchr(tmp->content, '\n');
	if (tmp_l)
	{
		*tmp_l = '\0';
		(*line) = ft_strdup(tmp->content);
		tmp_l++;
		ft_strcpy(tmp->content, tmp_l);
		return (1);
	}
	else if (ft_strlen(tmp->content) > 0)
	{
		*line = ft_strdup(tmp->content);
		return (1);
	}
	free(tmp->content);
	free(tmp);
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*doc;
	t_list			*tmp;
	char			*buf;
	int				ret;

	if (fd < 0 || !line || BUFF_SIZE <= 0)
		return (-1);
	if (!doc)
		fill_list(&doc, fd);
	tmp = fill_list(&doc, fd);
	buf = ft_strnew(BUFF_SIZE);
	while (!(ft_strchr(buf, '\n')))
	{
		if ((ret = read(fd, buf, BUFF_SIZE)) == -1)
			return (freedom(buf, -1));
		else if (ret == 0)
			return (dont_forget_line(line, tmp, buf, ret));
		buf[ret] = '\0';
		*line = ft_strjoin(tmp->content, buf);
		free(tmp->content);
		tmp->content = *line;
	}
	free(buf);
	return (dont_forget_line(line, tmp, buf, ret));
}

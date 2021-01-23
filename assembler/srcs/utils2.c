/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 16:40:54 by gjigglyp          #+#    #+#             */
/*   Updated: 2021/01/23 14:26:02 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*j_f(char *line, char *line2, int flag)
{
	char	*line3;
	char	*line4;

	if (!line2 || !line)
		return (NULL);
	line3 = ft_strdup(line);
	line4 = ft_strdup(line2);
	ft_strdel(&line);
	line = ft_strjoin(line3, line4);
	if (flag == 1)
		ft_strdel(&line2);
	ft_strdel(&line3);
	line3 = ft_strdup(line);
	ft_strdel(&line);
	line = ft_strjoin(line3, "\n");
	ft_strdel(&line3);
	ft_strdel(&line4);
	return (line);
}

int	len_to(char *str, char c)
{
	int	i;

	i = 0;
	c == '%' ? i += 1 : i + 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] == c)
			break ;
	}
	return (i + 1);
}

void	matclean(char **matrix)
{
	int	i;

	i = -1;
	while (matrix[++i])
		ft_strdel(&matrix[i]);
	free(matrix);
	matrix = 0;
}
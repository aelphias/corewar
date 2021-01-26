/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 14:44:06 by gjigglyp          #+#    #+#             */
/*   Updated: 2021/01/26 16:42:18 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char		*ft_strjoin_for_asm(char *line, char *line2, int flag)
{
	char	*line3;
	char	*line4;

	if (!line2 || !line)
		return (0);
	line3 = ft_strdup(line);
	line4 = ft_strdup(line2);
	free(line);
	line = ft_strjoin(line3, line4);
	if (flag == 1)
		free(line2);
	free(line3);
	line3 = ft_strdup(line);
	free(line);
	line = ft_strjoin(line3, "\n");
	free(line3);
	free(line4);
	return (line);
}

void		count_lbl(t_lbl *label, t_cmnd *cmnd)
{
	if (cmnd->arg_is_lbl[0] != 0)
	{
		while (--cmnd->arg_is_lbl[0] > 0)
			label = label->next;
		cmnd->argument[0] = label->pos - cmnd->pos;
	}
	else if (cmnd->arg_is_lbl[1] != 0)
	{
		while (--cmnd->arg_is_lbl[1] > 0)
			label = label->next;
		cmnd->argument[1] = label->pos - cmnd->pos;
	}
	else if (cmnd->arg_is_lbl[2] != 0)
	{
		while (--cmnd->arg_is_lbl[2] > 0)
			label = label->next;
		cmnd->argument[2] = label->pos - cmnd->pos;
	}
}

int			sc(t_cmnd *cmnd)
{
	int		code;
	int		count;
	int		i;

	count = 3;
	i = 0;
	code = 0;
	while (count--)
	{
		while (i <= 2)
		{
			code += (cmnd->argument_type[i]);
			code <<= 2;
			i++;
		}
	}
	return (code);
}

void		free_str_arr(char **str, char ***arr, int flag)
{
	int		i;

	if ((flag == 1 || flag == 2) && *str != 0)
	{
		free(*str);
		*str = 0;
	}
	if ((flag == 0 || flag == 2) && arr != 0 && *arr != 0)
	{
		i = 0;
		while (arr[0][i])
		{
			free(arr[0][i]);
			arr[0][i] = 0;
			i++;
		}
		free(*arr);
		*arr = 0;
	}
}

void		checkfs(t_crw *crw)
{
	while (crw->af[crw->arp] != '\n' &&
			crw->af[crw->arp] != COMMENT_CHAR &&
			crw->af[crw->arp] != ALT_COMMENT)
	{
		if (if_is_space(crw->af[crw->arp]) == 1)
			crw->arp++;
		else
			call_simple_error("ERROR: the string with name/comment of champion "
			"contains invalid data\n");
	}
}

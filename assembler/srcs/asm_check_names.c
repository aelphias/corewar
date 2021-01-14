/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_check_names.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 12:32:17 by gjigglyp          #+#    #+#             */
/*   Updated: 2021/01/14 17:38:10 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	while_is_name(char **line, int *i, t_crw *ch, int *j)
{
	int ans;

	if ((*line)[(*i)++] != '"')
		free_no_name(line, ch);
	while ((*line)[*i] != '"')
	{
		ft_printf("%c", (*line)[*i]);
		if (*j >= PROG_NAME_LENGTH)
			if_prog_length(ch, line);
		else if ((*line)[*i] == '\0')
		{
			free(*line);
			ch->name[(*j)++] = '\n';
			if ((ans = get_next_line(ch->fd, line)) > 0)
				*i = 0;
			else
				free_and_call(*ch, ER_IN_F);
		}
		ch->name[(*j)++] = (*line)[(*i)++];
	}
	ch->name[*j] = '\0';
}

int		is_name(char **line, int fd, t_crw *ch, int name)
{
	int len_const;
	int i;
	int j;

	j = 0;
	len_const = ft_strlen(NAME_CMD_STRING);
	i = 0;
	while ((*line)[i] == ' ' || (*line)[i] == '\t')
		i++;
	if (ft_strncmp(NAME_CMD_STRING, &(*line)[i], len_const))
		return (0);
	if (name)
	{
		free(*line);
		free_and_call(*ch, MORE_CO);
	}
	i += len_const;
	while ((*line)[i] != '"' && (*line)[i] != '\0' &&\
	(*line)[i] != COMMENT_CHAR && (*line)[i] != ALT_COMMENT &&\
	((*line)[i] == ' ' || (*line)[i] == '\t'))
		i++;
	ch->fd = fd;
	while_is_name(line, &i, ch, &j);
	skip_spaces(i + 1, *line, ch);
	return (1);
}

int		is_command_or_not(char *line, t_crw *ch)
{
	int		i;
	char	*name_com;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	name_com = NULL;
	name_com = check_name_com(&line[i], ch);
	if (name_com == NULL || line[i + ft_strlen(name_com)] == LABEL_CHAR)
	{
		free(name_com);
		return (0);
	}
	ft_strcpy(ch->lbls[ch->l_size].cmd_n, name_com);
	free(name_com);
	convert_command(&line[i + ft_strlen(name_com)], ch);
	return (1);
}

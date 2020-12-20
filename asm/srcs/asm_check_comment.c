/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_check_comment.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 16:56:25 by gjigglyp          #+#    #+#             */
/*   Updated: 2020/12/19 16:57:08 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		is_comment(char *line)
{
	int i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] == COMMENT_CHAR || line[i] == ALT_COMMENT)
		return (1);
	else if (line[i] == '\0')
		return (1);
	return (0);
}

void	skip_spaces(int i, char *line, t_crw *champ)
{
	while (line[i] != '\0')
	{
		if (line[i] == COMMENT_CHAR || line[i] == ALT_COMMENT)
			break ;
		if (line[i] != ' ' && line[i] != '\t')
		{
			free(line);
			free_all(*champ, "Error: invalid file\n");
			exit(-1);
		}
		i++;
	}
}

void	while_in_m_comment(t_crw *champ, char **line, int *i, int *j)
{
	int ans;

	if (*j >= COMMENT_LENGTH)
	{
		free(*line);
		free_all(*champ, "Error: too long comment\n");
	}
	else if ((*line)[*i] == '\0')
	{
		free(*line);
		champ->comment[(*j)++] = '\n';
		while ((ans = get_next_line(champ->fd, line)) > 0)
		{
			*i = 0;
			if ((*line)[0] == '\0')
				champ->comment[(*j)++] = '\n';
			else
			{
				break ;
			}
			free(*line);
		}
		if (ans <= 0)
			free_all(*champ, "Error: invalid file\n");
	}
}

int		init_main_com(int *len_const, int *i, char **line, t_crw *champ)
{
	*len_const = ft_strlen(COMMENT_CMD_STRING);
	*i = 0;
	while ((*line)[*i] == ' ' || (*line)[*i] == '\t')
		(*i)++;
	if (ft_strncmp(COMMENT_CMD_STRING, &(*line)[*i], *len_const))
		return (0);
	*i += *len_const;
	if (champ->len == 1)
	{
		free(*line);
		free_all(*champ, "Error: two or more main comments\n");
	}
	while ((*line)[*i] != '"' && (*line)[*i] != '\0' &&\
	(*line)[*i] != COMMENT_CHAR && (*line)[*i] != ALT_COMMENT &&\
	((*line)[*i] == ' ' || (*line)[*i] == '\t'))
		(*i)++;
	return (1);
}

int		is_main_comment(char **line, int fd, t_crw *champ, int mc)
{
	int len_const;
	int i;
	int j;

	j = 0;
	champ->len = mc;
	if (init_main_com(&len_const, &i, line, champ) == 0)
		return (0);
	if ((*line)[i++] != '"')
	{
		free(*line);
		free_all(*champ, "Error: no main comment\n");
	}
	champ->fd = fd;
	while ((*line)[i] != '"')
	{
		while_in_m_comment(champ, line, &i, &j);
		if ((*line)[i] == '"')
			break ;
		champ->comment[j++] = (*line)[i++];
	}
	champ->comment[j] = '\0';
	skip_spaces(i + 1, *line, champ);
	return (1);
}

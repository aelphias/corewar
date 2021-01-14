/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_check_comment.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 11:59:53 by gjigglyp          #+#    #+#             */
/*   Updated: 2021/01/14 18:20:29 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** комментарий ли эта строка?
*/

int		is_comment_or_not(char *ln)
{
	int i;

	i = 0;
	while (ln[i] == ' ' || ln[i] == '\t')
		i++;
	if (ln[i] == COMMENT_CHAR || ln[i] == ALT_COMMENT)
		return (1);
	else if (ln[i] == '\0' || ln[i] == '\n')
		return (1);
	return (0);
}

/*
** пропуск пробелов
*/

void	skip_spaces(int i, char *line, t_crw *ch)
{
	while (line[i] != '\0')
	{
		if (line[i] == COMMENT_CHAR || line[i] == ALT_COMMENT)
			break ;
		if (line[i] != ' ' && line[i] != '\t')
		{
			free(line);
			free_and_call(*ch, ER_IN_F);
			exit(-1);
		}
		i++;
	}
}

/*
** пока мы находимся в главном комментарии
*/

void	while_in_m_comment(t_crw *ch, char **line, int *i, int *j)
{
	int ans;

	if (*j >= COMMENT_LENGTH)
	{
		free(*line);
		free_and_call(*ch, LONG_CO);
	}
	else if ((*line)[*i] == '\0')
	{
		free(*line);
		ch->comment[(*j)++] = '\n';
		while ((ans = get_next_line(ch->fd, line)) > 0)
		{
			*i = 0;
			if ((*line)[0] == '\0')
				ch->comment[(*j)++] = '\n';
			else
				break ;
			free(*line);
		}
		if (ans <= 0)
			free_and_call(*ch, ER_IN_F);
	}
}

int		init_main_com(int *len_const, int *i, char **line, t_crw *ch)
{
	*len_const = ft_strlen(COMMENT_CMD_STRING);
	*i = 0;
	while ((*line)[*i] == ' ' || (*line)[*i] == '\t')
		(*i)++;
	if (ft_strncmp(COMMENT_CMD_STRING, &(*line)[*i], *len_const))
		return (0);
	*i += *len_const;
	if (ch->len == 1)
	{
		free(*line);
		free_and_call(*ch, MORE_CO);
	}
	while ((*line)[*i] != '"' && (*line)[*i] != '\0' &&\
	(*line)[*i] != COMMENT_CHAR && (*line)[*i] != ALT_COMMENT &&\
	((*line)[*i] == ' ' || (*line)[*i] == '\t'))
		(*i)++;
	return (1);
}

int		is_main_cmnt_or_not(char **line, int fd, t_crw *ch, int mc)
{
	int len_const;
	int i;
	int j;

	j = 0;
	ch->len = mc;
	if (init_main_com(&len_const, &i, line, ch) == 0)
		return (0);
	if ((*line)[i++] != '"')
	{
		free(*line);
		free_and_call(*ch, MAIN_CO);
	}
	ch->fd = fd;
	while ((*line)[i] != '"')
	{
		while_in_m_comment(ch, line, &i, &j);
		if ((*line)[i] == '"')
			break ;
		ch->comment[j++] = (*line)[i++];
	}
	ch->comment[j] = '\0';
	skip_spaces(i + 1, *line, ch);
	return (1);
}

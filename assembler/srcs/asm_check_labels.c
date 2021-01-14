/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_check_labels.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 16:57:32 by gjigglyp          #+#    #+#             */
/*   Updated: 2021/01/14 14:43:55 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	if_in_is_label_or_not(t_crw *ch, t_l *new, char *line, int i)
{
	ch->lbls[ch->l_size].is_label_or_not = 1;
	if (ch->lbls[ch->l_size].names == NULL)
	{
		if (!(new = malloc(sizeof(t_l))))
			free_and_call(*ch, MEM_ALL);
		ft_strncpy(new->name, &line[ch->len], i - ch->len);
		new->name[i - ch->len] = '\0';
		new->next = NULL;
		ch->lbls[ch->l_size].names = new;
		ch->lbls[ch->l_size].start = new;
	}
	else
	{
		if (!(new = malloc(sizeof(t_l))))
			free_and_call(*ch, MEM_ALL);
		ft_strncpy(new->name, &line[ch->len], i - ch->len);
		new->name[i - ch->len] = '\0';
		new->next = NULL;
		ch->lbls[ch->l_size].names->next = new;
		ch->lbls[ch->l_size].names = new;
	}
}

void	init_is_label_or_not(int *i, t_crw *ch, char *line)
{
	*i = 0;
	while (line[*i] == ' ' || line[*i] == '\t')
		(*i)++;
	ch->len = *i;
}

int		is_label_or_not(char *line, t_crw *ch)
{
	int i;
	t_l *new;

	new = NULL;
	init_is_label_or_not(&i, ch, line);
	while (line[i] != ' ' && line[i] != '\t' && line[i] != LABEL_CHAR && \
	line[i] != '\0' && line[i] != COMMENT_CHAR && line[i] != ALT_COMMENT &&\
	char_in_lbl(line[i]))
		i++;
	if (line[i] == LABEL_CHAR)
		if_in_is_label_or_not(ch, new, line, i);
	else
		return (0);
	i++;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] == '\0' || line[i] == COMMENT_CHAR || line[i] == ALT_COMMENT)
		return (1);
	else if (is_command_or_not(&line[i], ch))
		return (1);
	else
		free_and_call(*ch, ER_IN_F);
	return (1);
}

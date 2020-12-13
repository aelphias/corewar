/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_check_labels.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 15:19:59 by gjigglyp          #+#    #+#             */
/*   Updated: 2020/12/13 15:19:59 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	if_in_is_label_or_not(t_crw *champ, t_l *new, char *line, int i)
{
	champ->labels[champ->l_size].is_label_or_not = 1;
	if (champ->labels[champ->l_size].names == NULL)
	{
		if (!(new = malloc(sizeof(t_l))))
			free_all(*champ, "Error: memory didn't allocated\n");
		ft_strncpy(new->name, &line[champ->len], i - champ->len);
		new->name[i - champ->len] = '\0';
		new->next = NULL;
		champ->labels[champ->l_size].names = new;
		champ->labels[champ->l_size].start = new;
	}
	else
	{
		if (!(new = malloc(sizeof(t_l))))
			free_all(*champ, "Error: memory didn't allocated\n");
		ft_strncpy(new->name, &line[champ->len], i - champ->len);
		new->name[i - champ->len] = '\0';
		new->next = NULL;
		champ->labels[champ->l_size].names->next = new;
		champ->labels[champ->l_size].names = new;
	}
}

void	init_is_label_or_not(int *i, t_crw *champ, char *line)
{
	*i = 0;
	while (line[*i] == ' ' || line[*i] == '\t')
		(*i)++;
	champ->len = *i;
}

int		is_label_or_not(char *line, t_crw *champ)
{
	int i;
	t_l *new;

	new = NULL;
	init_is_label_or_not(&i, champ, line);
	while (line[i] != ' ' && line[i] != '\t' && line[i] != LABEL_CHAR && \
	line[i] != '\0' && line[i] != COMMENT_CHAR && line[i] != ALT_COMMENT &&\
	char_in_label(line[i]))
		i++;
	if (line[i] == LABEL_CHAR)
		if_in_is_label_or_not(champ, new, line, i);
	else
		return (0);
	i++;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] == '\0' || line[i] == COMMENT_CHAR || line[i] == ALT_COMMENT)
		return (1);
	else if (is_command_or_not(&line[i], champ))
		return (1);
	else
		free_all(*champ, "Error: invalid file\n");
	return (1);
}

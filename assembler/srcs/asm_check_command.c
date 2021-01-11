/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_check_command.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 16:48:04 by gjigglyp          #+#    #+#             */
/*   Updated: 2021/01/05 13:40:18 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "application.h"

void		writelbl(t_crw *ch, int *i, int arg_cntr, char *line)
{
	int		j;

	j = 0;
	while (char_in_label(line[(*i)]))
	{
		if (g_op[ch->len].args_num - arg_cntr + 1 == 1)
		{
			ch->labels[ch->l_size].arg_now = 1;
			ch->labels[ch->l_size].l_name_1[j++] = line[(*i)];
		}
		else if (g_op[ch->len].args_num - arg_cntr + 1 == 2)
		{
			ch->labels[ch->l_size].arg_now = 2;
			ch->labels[ch->l_size].l_name_2[j++] = line[(*i)];
		}
		else if (g_op[ch->len].args_num - arg_cntr + 1 == 3)
		{
			ch->labels[ch->l_size].arg_now = 3;
			ch->labels[ch->l_size].l_name_3[j++] = line[(*i)];
		}
		(*i)++;
	}
	if (line[(*i)] != ' ' && line[*i] != ',' && line[*i] != '\t' &&\
	line[*i] != '\0' && line[*i] != COMMENT_CHAR && line[*i] != ALT_COMMENT)
		free_and_call(*ch, ER_I_AR);
}

void		zero_exec(t_crw *ch, int exec_size)
{
	int i;

	i = 0;
	while (i < exec_size)
		ch->exec_code[i++] = 0;
}

int			get_dir_ind_arg_val(t_crw *champ, char *line, int *i)
{
	int start;

	start = *i;
	if (line[*i] == '-')
		(*i)++;
	while (line[*i] >= '0' && line[*i] <= '9')
		(*i)++;
	if (line[*i - 1] == '-' && *i == 1)
		free_and_call(*champ, ER_I_AR);
	return (ft_atoi(&line[start]));
}

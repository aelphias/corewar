/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_check_command.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 14:50:31 by gjigglyp          #+#    #+#             */
/*   Updated: 2020/12/13 14:50:31 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "asm.h"

void		if_is_label_or_not(t_crw *champ, int arg_cntr, char *line, int *i)
{
	if (g_op[champ->len].args_num - arg_cntr + 1 == 1)
	{
		champ->labels[champ->l_size].arg_1 += 2;
		champ->labels[champ->l_size].type_1 = T_IND;
	}
	else if (g_op[champ->len].args_num - arg_cntr + 1 == 2)
	{
		champ->labels[champ->l_size].arg_2 += 2;
		champ->labels[champ->l_size].type_2 = T_IND;
	}
	else if (g_op[champ->len].args_num - arg_cntr + 1 == 3)
	{
		champ->labels[champ->l_size].arg_3 += 2;
		champ->labels[champ->l_size].type_3 = T_IND;
	}
	(*i)++;
	recording_label(champ, i, arg_cntr, line);
	find_label(champ);
}

void		recording_label(t_crw *champ, int *i, int arg_cntr, char *line)
{
	int		j;

	j = 0;
	while (char_in_label(line[(*i)]))
	{
		if (g_op[champ->len].args_num - arg_cntr + 1 == 1)
		{
			champ->labels[champ->l_size].arg_now = 1;
			champ->labels[champ->l_size].l_name_1[j++] = line[(*i)];
		}
		else if (g_op[champ->len].args_num - arg_cntr + 1 == 2)
		{
			champ->labels[champ->l_size].arg_now = 2;
			champ->labels[champ->l_size].l_name_2[j++] = line[(*i)];
		}
		else if (g_op[champ->len].args_num - arg_cntr + 1 == 3)
		{
			champ->labels[champ->l_size].arg_now = 3;
			champ->labels[champ->l_size].l_name_3[j++] = line[(*i)];
		}
		(*i)++;
	}
	if (line[(*i)] != ' ' && line[*i] != ',' && line[*i] != '\t' &&\
	line[*i] != '\0' && line[*i] != COMMENT_CHAR && line[*i] != ALT_COMMENT)
		free_all(*champ, "Error: wrong symbol\n");
}

void		zero_exec(t_crw *champ, int exec_size)
{
	int 	i;

	i = 0;
	while (i < exec_size)
		champ->exec_code[i++] = 0;
}

int			get_reg_arg_val(t_crw *champ, char *line, int *i)
{
	(*i)++;
	while (line[*i] >= '0' && line[*i] <= '9')
		(*i)++;
	if (ft_atoi(&line[1]) > REG_NUMBER || *i == 1 || ft_atoi(&line[1]) < 1)
	{
		free_all(*champ, "Error: invalid arg\n");
	}
	return (ft_atoi(&line[1]));
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
	{
		free_all(*champ, "Error: invalid arg\n");
	}
	return (ft_atoi(&line[start]));
}

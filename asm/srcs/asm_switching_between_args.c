/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_switching_between_args.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 23:23:55 by marvin            #+#    #+#             */
/*   Updated: 2020/11/26 23:23:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	if_is_r(int arg_counter, t_crw *champ, char *line, int *i)
{
	if (g_op[champ->len].args_num - arg_counter + 1 == 1)
	{
		champ->labels[champ->l_size].arg_1++;
		champ->labels[champ->l_size].type_1 = 1;
		champ->labels[champ->l_size].range_1 =\
		get_reg_arg_val(champ, line, i);
	}
	else if (g_op[champ->len].args_num - arg_counter + 1 == 2)
	{
		champ->labels[champ->l_size].arg_2++;
		champ->labels[champ->l_size].type_2 = 1;
		champ->labels[champ->l_size].range_2 =\
		get_reg_arg_val(champ, line, i);
	}
	else if (g_op[champ->len].args_num - arg_counter + 1 == 3)
	{
		champ->labels[champ->l_size].arg_3++;
		champ->labels[champ->l_size].type_3 = 1;
		champ->labels[champ->l_size].range_3 =\
		get_reg_arg_val(champ, line, i);
	}
}

void	if_is_ind(t_crw *champ, int arg_counter, char *line, int *i)
{
	if (g_op[champ->len].args_num - arg_counter + 1 == 1)
	{
		champ->labels[champ->l_size].arg_1 += 2;
		champ->labels[champ->l_size].range_1 =\
		get_dir_ind_arg_val(champ, line, i);
		champ->labels[champ->l_size].type_1 = T_IND;
	}
	else if (g_op[champ->len].args_num - arg_counter + 1 == 2)
	{
		champ->labels[champ->l_size].arg_2 += 2;
		champ->labels[champ->l_size].range_2 =\
		get_dir_ind_arg_val(champ, line, i);
		champ->labels[champ->l_size].type_2 = T_IND;
	}
	else if (g_op[champ->len].args_num - arg_counter + 1 == 3)
	{
		champ->labels[champ->l_size].arg_3 += 2;
		champ->labels[champ->l_size].range_3 =\
		get_dir_ind_arg_val(champ, line, i);
		champ->labels[champ->l_size].type_3 = T_IND;
	}
}

void	is_lab_in_dir_char(char *line, t_crw *champ, int arg_counter, int *i)
{
	(*i)++;
	if (line[*i] == LABEL_CHAR)
	{
		(*i)++;
		recording_label(champ, i, arg_counter, line);
		find_label(champ);
	}
	else if ((line[*i] >= '0' && line[*i] <= '9') || line[*i] == '-')
	{
		if (g_op[champ->len].args_num - arg_counter + 1 == 1)
			champ->labels[champ->l_size].range_1 =\
			get_dir_ind_arg_val(champ, line, i);
		else if (g_op[champ->len].args_num - arg_counter + 1 == 2)
			champ->labels[champ->l_size].range_2 =\
			get_dir_ind_arg_val(champ, line, i);
		else if (g_op[champ->len].args_num - arg_counter + 1 == 3)
			champ->labels[champ->l_size].range_3 =\
			get_dir_ind_arg_val(champ, line, i);
	}
	else
		free_all(*champ, "Error: invalid arg\n");
}

void	if_is_dir(t_crw *champ, int arg_counter, char *line, int *i)
{
	if (g_op[champ->len].args_num - arg_counter + 1 == 1)
	{
		champ->labels[champ->l_size].arg_1 += g_op[champ->len].t_dir_size;
		champ->labels[champ->l_size].type_1 = 2;
	}
	else if (g_op[champ->len].args_num - arg_counter + 1 == 2)
	{
		champ->labels[champ->l_size].arg_2 += g_op[champ->len].t_dir_size;
		champ->labels[champ->l_size].type_2 = 2;
	}
	else if (g_op[champ->len].args_num - arg_counter + 1 == 3)
	{
		champ->labels[champ->l_size].arg_3 += g_op[champ->len].t_dir_size;
		champ->labels[champ->l_size].type_3 = 2;
	}
	is_lab_in_dir_char(line, champ, arg_counter, i);
}

int		switching_between_args(char *line, int arg_counter, t_crw *champ)
{
	int i;

	champ->len = 0;
	i = 0;
	while (ft_strcmp(g_op[champ->len].name,\
	champ->labels[champ->l_size].cmd_name) != 0)
		champ->len++;
	if (line[i] == 'r')
		if_is_r(arg_counter, champ, line, &i);
	else if (line[i] == DIRECT_CHAR)
		if_is_dir(champ, arg_counter, line, &i);
	else if (line[i] == '-' || (line[i] >= '0' && line[i] <= '9'))
		if_is_ind(champ, arg_counter, line, &i);
	else if (line[i] == LABEL_CHAR)
		if_is_label_or_not(champ, arg_counter, line, &i);
	return (i);
}

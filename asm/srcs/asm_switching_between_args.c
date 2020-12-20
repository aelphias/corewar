/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_switching_between_args.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 17:32:11 by gjigglyp          #+#    #+#             */
/*   Updated: 2020/12/19 17:32:21 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	if_is_r(int arg_cntr, t_crw *champ, char *line, int *i)
{
	if (g_op[champ->len].args_num - arg_cntr + 1 == 1)
	{
		champ->labels[champ->l_size].arg_1++;
		champ->labels[champ->l_size].t1 = 1;
		champ->labels[champ->l_size].r1 =\
		get_reg_arg_val(champ, line, i);
	}
	else if (g_op[champ->len].args_num - arg_cntr + 1 == 2)
	{
		champ->labels[champ->l_size].arg_2++;
		champ->labels[champ->l_size].t2 = 1;
		champ->labels[champ->l_size].r2 =\
		get_reg_arg_val(champ, line, i);
	}
	else if (g_op[champ->len].args_num - arg_cntr + 1 == 3)
	{
		champ->labels[champ->l_size].arg_3++;
		champ->labels[champ->l_size].t3 = 1;
		champ->labels[champ->l_size].r3 =\
		get_reg_arg_val(champ, line, i);
	}
}

void	if_is_ind(t_crw *champ, int arg_cntr, char *line, int *i)
{
	if (g_op[champ->len].args_num - arg_cntr + 1 == 1)
	{
		champ->labels[champ->l_size].arg_1 += 2;
		champ->labels[champ->l_size].r1 =\
		get_dir_ind_arg_val(champ, line, i);
		champ->labels[champ->l_size].t1 = T_IND;
	}
	else if (g_op[champ->len].args_num - arg_cntr + 1 == 2)
	{
		champ->labels[champ->l_size].arg_2 += 2;
		champ->labels[champ->l_size].r2 =\
		get_dir_ind_arg_val(champ, line, i);
		champ->labels[champ->l_size].t2 = T_IND;
	}
	else if (g_op[champ->len].args_num - arg_cntr + 1 == 3)
	{
		champ->labels[champ->l_size].arg_3 += 2;
		champ->labels[champ->l_size].r3 =\
		get_dir_ind_arg_val(champ, line, i);
		champ->labels[champ->l_size].t3 = T_IND;
	}
}

void	is_lab_in_dir_char(char *line, t_crw *champ, int arg_cntr, int *i)
{
	(*i)++;
	if (line[*i] == LABEL_CHAR)
	{
		(*i)++;
		recording_label(champ, i, arg_cntr, line);
		find_label(champ);
	}
	else if ((line[*i] >= '0' && line[*i] <= '9') || line[*i] == '-')
	{
		if (g_op[champ->len].args_num - arg_cntr + 1 == 1)
			champ->labels[champ->l_size].r1 =\
			get_dir_ind_arg_val(champ, line, i);
		else if (g_op[champ->len].args_num - arg_cntr + 1 == 2)
			champ->labels[champ->l_size].r2 =\
			get_dir_ind_arg_val(champ, line, i);
		else if (g_op[champ->len].args_num - arg_cntr + 1 == 3)
			champ->labels[champ->l_size].r3 =\
			get_dir_ind_arg_val(champ, line, i);
	}
	else
		free_all(*champ, "Error: invalid arg\n");
}

void	if_is_dir(t_crw *champ, int arg_cntr, char *line, int *i)
{
	if (g_op[champ->len].args_num - arg_cntr + 1 == 1)
	{
		champ->labels[champ->l_size].arg_1 += g_op[champ->len].t_dir_size;
		champ->labels[champ->l_size].t1 = 2;
	}
	else if (g_op[champ->len].args_num - arg_cntr + 1 == 2)
	{
		champ->labels[champ->l_size].arg_2 += g_op[champ->len].t_dir_size;
		champ->labels[champ->l_size].t2 = 2;
	}
	else if (g_op[champ->len].args_num - arg_cntr + 1 == 3)
	{
		champ->labels[champ->l_size].arg_3 += g_op[champ->len].t_dir_size;
		champ->labels[champ->l_size].t3 = 2;
	}
	is_lab_in_dir_char(line, champ, arg_cntr, i);
}

int		switching_between_args(char *line, int arg_cntr, t_crw *champ)
{
	int i;

	champ->len = 0;
	i = 0;
	while (ft_strcmp(g_op[champ->len].name,\
	champ->labels[champ->l_size].cmd_n) != 0)
		champ->len++;
	if (line[i] == 'r')
		if_is_r(arg_cntr, champ, line, &i);
	else if (line[i] == DIRECT_CHAR)
		if_is_dir(champ, arg_cntr, line, &i);
	else if (line[i] == '-' || (line[i] >= '0' && line[i] <= '9'))
		if_is_ind(champ, arg_cntr, line, &i);
	else if (line[i] == LABEL_CHAR)
		if_is_label_or_not(champ, arg_cntr, line, &i);
	return (i);
}

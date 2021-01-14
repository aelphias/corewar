/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_switching_between_args.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 11:42:55 by gjigglyp          #+#    #+#             */
/*   Updated: 2021/01/14 14:44:28 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	if_is_r(int arg_cntr, t_crw *ch, char *line, int *i)
{
	if (g_op[ch->len].args_num - arg_cntr + 1 == 1)
	{
		ch->lbls[ch->l_size].arg_1++;
		ch->lbls[ch->l_size].t1 = 1;
		ch->lbls[ch->l_size].r1 =\
		get_reg_arg_val(ch, line, i);
	}
	else if (g_op[ch->len].args_num - arg_cntr + 1 == 2)
	{
		ch->lbls[ch->l_size].arg_2++;
		ch->lbls[ch->l_size].t2 = 1;
		ch->lbls[ch->l_size].r2 =\
		get_reg_arg_val(ch, line, i);
	}
	else if (g_op[ch->len].args_num - arg_cntr + 1 == 3)
	{
		ch->lbls[ch->l_size].arg_3++;
		ch->lbls[ch->l_size].t3 = 1;
		ch->lbls[ch->l_size].r3 =\
		get_reg_arg_val(ch, line, i);
	}
}

void	if_is_ind(t_crw *ch, int arg_cntr, char *line, int *i)
{
	if (g_op[ch->len].args_num - arg_cntr + 1 == 1)
	{
		ch->lbls[ch->l_size].arg_1 += 2;
		ch->lbls[ch->l_size].r1 =\
		get_dir_ind_arg_val(ch, line, i);
		ch->lbls[ch->l_size].t1 = T_IND;
	}
	else if (g_op[ch->len].args_num - arg_cntr + 1 == 2)
	{
		ch->lbls[ch->l_size].arg_2 += 2;
		ch->lbls[ch->l_size].r2 =\
		get_dir_ind_arg_val(ch, line, i);
		ch->lbls[ch->l_size].t2 = T_IND;
	}
	else if (g_op[ch->len].args_num - arg_cntr + 1 == 3)
	{
		ch->lbls[ch->l_size].arg_3 += 2;
		ch->lbls[ch->l_size].r3 =\
		get_dir_ind_arg_val(ch, line, i);
		ch->lbls[ch->l_size].t3 = T_IND;
	}
}

void	is_lab_in_dir_char(char *line, t_crw *ch, int arg_cntr, int *i)
{
	(*i)++;
	if (line[*i] == LABEL_CHAR)
	{
		(*i)++;
		writelbl(ch, i, arg_cntr, line);
		find_label(ch);
	}
	else if ((line[*i] >= '0' && line[*i] <= '9') || line[*i] == '-')
	{
		if (g_op[ch->len].args_num - arg_cntr + 1 == 1)
			ch->lbls[ch->l_size].r1 =\
			get_dir_ind_arg_val(ch, line, i);
		else if (g_op[ch->len].args_num - arg_cntr + 1 == 2)
			ch->lbls[ch->l_size].r2 =\
			get_dir_ind_arg_val(ch, line, i);
		else if (g_op[ch->len].args_num - arg_cntr + 1 == 3)
			ch->lbls[ch->l_size].r3 =\
			get_dir_ind_arg_val(ch, line, i);
	}
	else
		free_and_call(*ch, ER_I_AR);
}

void	if_is_dir(t_crw *ch, int arg_cntr, char *line, int *i)
{
	if (g_op[ch->len].args_num - arg_cntr + 1 == 1)
	{
		ch->lbls[ch->l_size].arg_1 += g_op[ch->len].t_dir_size;
		ch->lbls[ch->l_size].t1 = 2;
	}
	else if (g_op[ch->len].args_num - arg_cntr + 1 == 2)
	{
		ch->lbls[ch->l_size].arg_2 += g_op[ch->len].t_dir_size;
		ch->lbls[ch->l_size].t2 = 2;
	}
	else if (g_op[ch->len].args_num - arg_cntr + 1 == 3)
	{
		ch->lbls[ch->l_size].arg_3 += g_op[ch->len].t_dir_size;
		ch->lbls[ch->l_size].t3 = 2;
	}
	is_lab_in_dir_char(line, ch, arg_cntr, i);
}

int		switching_between_args(char *line, int arg_cntr, t_crw *ch)
{
	int i;

	ch->len = 0;
	i = 0;
	while (ft_strcmp(g_op[ch->len].name,\
	ch->lbls[ch->l_size].cmd_n) != 0)
		ch->len++;
	if (line[i] == 'r')
		if_is_r(arg_cntr, ch, line, &i);
	else if (line[i] == DIRECT_CHAR)
		if_is_dir(ch, arg_cntr, line, &i);
	else if (line[i] == '-' || (line[i] >= '0' && line[i] <= '9'))
		if_is_ind(ch, arg_cntr, line, &i);
	else if (line[i] == LABEL_CHAR)
		if_is_label_or_not(ch, arg_cntr, line, &i);
	return (i);
}

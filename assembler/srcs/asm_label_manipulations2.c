/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_label_manipulations2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 11:46:49 by gjigglyp          #+#    #+#             */
/*   Updated: 2021/01/15 14:22:59 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	if_is_label_or_not(t_crw *ch, int arg_cntr, char *line, int *i)
{
	if (g_op[ch->len].args_num - arg_cntr + 1 == 1)
	{
		ch->lbls[ch->l_size].arg_1 += 2;
		ch->lbls[ch->l_size].t1 = T_IND;
	}
	else if (g_op[ch->len].args_num - arg_cntr + 1 == 2)
	{
		ch->lbls[ch->l_size].arg_2 += 2;
		ch->lbls[ch->l_size].t2 = T_IND;
	}
	else if (g_op[ch->len].args_num - arg_cntr + 1 == 3)
	{
		ch->lbls[ch->l_size].arg_3 += 2;
		ch->lbls[ch->l_size].t3 = T_IND;
	}
	(*i)++;
	writelbl(ch, i, arg_cntr, line);
	lblfind(ch);
}

int		get_reg_arg_val(t_crw *ch, char *line, int *i)
{
	(*i)++;
	while (line[*i] >= '0' && line[*i] <= '9')
		(*i)++;
	if (ft_atoi(&line[1]) > REG_NUMBER || *i == 1 || ft_atoi(&line[1]) < 1)
		free_and_call(*ch, ER_I_AR);
	return (ft_atoi(&line[1]));
}

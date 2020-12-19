/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_label_manipulations2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 15:30:51 by gjigglyp          #+#    #+#             */
/*   Updated: 2020/12/19 15:30:51 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	if_is_label_or_not(t_crw *champ, int arg_cntr, char *line, int *i)
{
	if (g_op[champ->len].args_num - arg_cntr + 1 == 1)
	{
		champ->labels[champ->l_size].arg_1 += 2;
		champ->labels[champ->l_size].t1 = T_IND;
	}
	else if (g_op[champ->len].args_num - arg_cntr + 1 == 2)
	{
		champ->labels[champ->l_size].arg_2 += 2;
		champ->labels[champ->l_size].t2 = T_IND;
	}
	else if (g_op[champ->len].args_num - arg_cntr + 1 == 3)
	{
		champ->labels[champ->l_size].arg_3 += 2;
		champ->labels[champ->l_size].t3 = T_IND;
	}
	(*i)++;
	recording_label(champ, i, arg_cntr, line);
	find_label(champ);
}

int		get_reg_arg_val(t_crw *champ, char *line, int *i)
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

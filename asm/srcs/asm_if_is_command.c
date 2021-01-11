/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_if_is_command.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 16:53:30 by gjigglyp          #+#    #+#             */
/*   Updated: 2021/01/10 17:49:07 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		if_in_conv_com(char **line, t_crw *champ, int *i, t_tw *arg)
{
	if ((*line)[*i] == 'r' || (*line)[*i] == DIRECT_CHAR || (*line)[*i] == '-'\
	|| (*line)[*i] == LABEL_CHAR || ((*line)[*i] >= '0' && (*line)[*i] <= '9'))
	{
		if (arg->comma == 1)
			free_and_call(*champ, ERR_COM);
		arg->comma = 1;
		*i += switching_between_args(&((*line)[*i]), arg->arg_cntr, champ);
		arg->arg_cntr--;
	}
	else if ((*line)[(*i)++] == SEPARATOR_CHAR)
	{
		if (arg->comma == 0)
			free_and_call(*champ, ERR_COE);
		arg->comma = 0;
	}
	else if ((*line)[--(*i)] == COMMENT_CHAR || (*line)[*i] == ALT_COMMENT)
	{
		if (arg->arg_cntr != 0)
			exit(-1);
		increase_crw(champ);
		return (1);
	}
	else if ((*line)[*i] != ' ' && (*line)[*i] != '\t' && (*line)[*i] != '\0')
		free_and_call(*champ, ER_I_SY);
	return (0);
}

void	convert_command(char *line, t_crw *champ)
{
	int		i;
	t_tw	arg;

	i = 0;
	while (ft_strcmp(g_op[i].name, champ->labels[champ->l_size].cmd_n) != 0)
		i++;
	arg.arg_cntr = g_op[i].args_num;
	if (g_op[i].args_types_code)
		champ->labels[champ->l_size].cmd_t = 1;
	else
		champ->labels[champ->l_size].cmd_t = 0;
	i = 0;
	arg.comma = 0;
	champ->new_com = champ->l_size;
	while (line[i] != '\0')
	{
		while (line[i] == ' ' || line[i] == '\t')
			i++;
		if (if_in_conv_com(&line, champ, &i, &arg))
			return ;
	}
	if (arg.comma == 0 || arg.arg_cntr != 0)
		free_and_call(*champ, ER_I_SY);
	increase_crw(champ);
}

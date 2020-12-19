/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_counters.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 15:23:26 by gjigglyp          #+#    #+#             */
/*   Updated: 2020/12/19 15:23:29 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int				count_code_size(t_crw *champ)
{
	int i;
	int sum;

	sum = 0;
	i = 0;
	while (i != champ->l_size)
	{
		sum += champ->labels[i].arg_1 + champ->labels[i].arg_2 +\
		champ->labels[i].arg_3 + champ->labels[i].cmd_t + 1;
		i++;
	}
	return (sum);
}

int				skip_everything(char *line)
{
	int j;

	j = 0;
	while (line[j] != ' ' && line[j] != '\t' && line[j] != '\0' && \
	line[j] != ALT_COMMENT && line[j] != COMMENT_CHAR && \
	line[j] != LABEL_CHAR && line[j] != DIRECT_CHAR)
		j++;
	return (j);
}

unsigned char	count_code_type_arg(t_crw *champ, int i)
{
	unsigned char ret;

	ret = 0;
	if (champ->labels[i].t1 == T_REG)
		ret += 1;
	else if (champ->labels[i].t1 == T_DIR)
		ret += 2;
	else if (champ->labels[i].t1 == T_IND)
		ret += 3;
	ret = ret << 2;
	if (champ->labels[i].t2 == T_REG)
		ret += 1;
	else if (champ->labels[i].t2 == T_DIR)
		ret += 2;
	else if (champ->labels[i].t2 == T_IND)
		ret += 3;
	ret = ret << 2;
	if (champ->labels[i].t3 == T_REG)
		ret += 1;
	else if (champ->labels[i].t3 == T_DIR)
		ret += 2;
	else if (champ->labels[i].t3 == T_IND)
		ret += 3;
	ret = ret << 2;
	return (ret);
}

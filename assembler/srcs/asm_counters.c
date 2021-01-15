/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_counters.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 17:09:33 by gjigglyp          #+#    #+#             */
/*   Updated: 2021/01/15 13:51:48 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int				cs_count(t_crw *ch)
{
	int i;
	int sum;

	sum = 0;
	i = 0;
	while (i != ch->l_size)
	{
		sum += ch->lbls[i].arg_1 + ch->lbls[i].arg_2 +\
		ch->lbls[i].arg_3 + ch->lbls[i].cmd_t + 1;
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

unsigned char	count_cta(t_crw *ch, int i)
{
	unsigned char ret;

	ret = 0;
	if (ch->lbls[i].t1 == T_REG)
		ret += 1;
	else if (ch->lbls[i].t1 == T_DIR)
		ret += 2;
	else if (ch->lbls[i].t1 == T_IND)
		ret += 3;
	ret = ret << 2;
	if (ch->lbls[i].t2 == T_REG)
		ret += 1;
	else if (ch->lbls[i].t2 == T_DIR)
		ret += 2;
	else if (ch->lbls[i].t2 == T_IND)
		ret += 3;
	ret = ret << 2;
	if (ch->lbls[i].t3 == T_REG)
		ret += 1;
	else if (ch->lbls[i].t3 == T_DIR)
		ret += 2;
	else if (ch->lbls[i].t3 == T_IND)
		ret += 3;
	ret = ret << 2;
	return (ret);
}

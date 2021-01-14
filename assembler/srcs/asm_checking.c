/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_checking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 11:46:10 by gjigglyp          #+#    #+#             */
/*   Updated: 2021/01/14 14:57:54 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*check_name_com(char *line, t_crw *ch)
{
	int		end;
	int		i;
	int		j;
	char	*result;

	i = 0;
	while (line[i] == ' ' && line[i] == '\t')
		i++;
	end = i;
	i = 0;
	j = skip_everything(line);
	if (j == end)
		return (NULL);
	while (i != 16 && ft_strncmp(&line[end], g_op[i].name, j - end) != 0)
		i++;
	if (i != 16)
	{
		result = ft_strsub(line, end, end + (j - end));
		ch->lbls[ch->l_size].cmd_c = g_op[i].code;
		return (result);
	}
	return (NULL);
}

int		char_in_lbl(char el)
{
	int i;

	i = 0;
	while (LABEL_CHARS[i] != '\0')
	{
		if (LABEL_CHARS[i] == el)
			return (1);
		i++;
	}
	return (0);
}

void	finish_fill_label_range(t_crw *ch)
{
	int i;

	i = 0;
	while (i < ch->l_size + 1)
	{
		if (ch->lbls[i].l_name_1[0] && ch->lbls[i].r1 == 0)
		{
			if (find_lab_aft_cmd(ch, ch->lbls[i].l_name_1, i, 1) == 0)
				exit(-1);
		}
		if (ch->lbls[i].l_name_2[0] && ch->lbls[i].r2 == 0)
		{
			if (find_lab_aft_cmd(ch, ch->lbls[i].l_name_2, i, 2) == 0)
				exit(-1);
		}
		if (ch->lbls[i].l_name_3[0] && ch->lbls[i].r3 == 0)
		{
			if (find_lab_aft_cmd(ch, ch->lbls[i].l_name_3, i, 3) == 0)
				exit(-1);
		}
		i++;
	}
}

void	check_type_arg(t_crw *ch)
{
	int i;
	int j;

	i = 0;
	while (i != ch->l_size)
	{
		j = 0;
		while (ft_strcmp(g_op[j].name, ch->lbls[i].cmd_n) != 0)
			j++;
		if ((g_op[j].args_types[0] & ch->lbls[i].t1) == 0)
			free_and_call(*ch, NO_LABE);
		if ((g_op[j].args_types[1] & ch->lbls[i].t2) == 0  \
		&& (g_op[j].args_types[1] || ch->lbls[i].t2))
			free_and_call(*ch, NO_LABE);
		if ((g_op[j].args_types[2] & ch->lbls[i].t3) == 0  \
		&& (g_op[j].args_types[2] || ch->lbls[i].t3))
			free_and_call(*ch, NO_LABE);
		i++;
	}
}

char	*change_ex(char *filename, char *old, char *new)
{
	char	*bn;

	bn = ft_strsub(filename, 0, ft_strlen(filename) - ft_strlen(old));
	if (!bn)
	{
		ft_strdel(&bn);
		exit(-1);
	}
	if (!(filename = ft_strjoin(bn, new)))
	{
		ft_strdel(&bn);
		exit(-1);
	}
	ft_strdel(&bn);
	return (filename);
}

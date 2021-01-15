/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_label_manipulations.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 17:30:09 by gjigglyp          #+#    #+#             */
/*   Updated: 2021/01/15 14:22:59 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		ft_contains(char *str, t_lbl label)
{
	t_l *tmp;

	tmp = label.start;
	while (tmp != NULL)
	{
		if (ft_strcmp(tmp->name, str) == 0)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	while_in_lblfind(t_crw *ch, char *str, int *sum, int i)
{
	while (i != ch->l_size)
	{
		if (ch->lbls[i].is_label_or_not == 1 &&\
		ft_contains(str, ch->lbls[i]))
		{
			while (i != ch->l_size)
			{
				*sum -= ch->lbls[i].arg_1 + ch->lbls[i].arg_2 +\
				ch->lbls[i].arg_3 + 1 + ch->lbls[i].cmd_t;
				i++;
			}
			break ;
		}
		i++;
	}
}

void	lblfind(t_crw *ch)
{
	int		i;
	char	*str;
	int		sum;

	sum = 0;
	str = NULL;
	if (ch->lbls[ch->l_size].arg_now == 1)
		str = ch->lbls[ch->l_size].l_name_1;
	else if (ch->lbls[ch->l_size].arg_now == 2)
		str = ch->lbls[ch->l_size].l_name_2;
	else if (ch->lbls[ch->l_size].arg_now == 3)
		str = ch->lbls[ch->l_size].l_name_3;
	i = 0;
	while_in_lblfind(ch, str, &sum, i);
	if (ch->lbls[ch->l_size].arg_now == 1)
		ch->lbls[ch->l_size].r1 = sum;
	else if (ch->lbls[ch->l_size].arg_now == 2)
		ch->lbls[ch->l_size].r2 = sum;
	else if (ch->lbls[ch->l_size].arg_now == 3)
		ch->lbls[ch->l_size].r3 = sum;
}

int		find_lab_aft_cmd(t_crw *ch, char *l_name, int start, int arg)
{
	int i;
	int sum;

	i = start;
	sum = 0;
	while (i < ch->l_size + 1)
	{
		if (ft_contains(l_name, ch->lbls[i]))
			break ;
		sum += ch->lbls[i].arg_1 + ch->lbls[i].arg_2 +\
		ch->lbls[i].arg_3 + 1 + ch->lbls[i].cmd_t;
		i++;
		if (i == ch->l_size + 1)
			return (0);
	}
	if (arg == 1)
		ch->lbls[start].r1 = sum;
	else if (arg == 2)
		ch->lbls[start].r2 = sum;
	else if (arg == 3)
		ch->lbls[start].r3 = sum;
	return (1);
}

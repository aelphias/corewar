/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_label_manipulations.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 15:23:57 by gjigglyp          #+#    #+#             */
/*   Updated: 2020/12/19 15:24:00 by gjigglyp         ###   ########.fr       */
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
		{
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

void	while_in_find_label(t_crw *champ, char *str, int *sum, int i)
{
	while (i != champ->l_size)
	{
		if (champ->labels[i].is_label_or_not == 1 &&\
		ft_contains(str, champ->labels[i]))
		{
			while (i != champ->l_size)
			{
				*sum -= champ->labels[i].arg_1 + champ->labels[i].arg_2 +\
				champ->labels[i].arg_3 + 1 + champ->labels[i].cmd_t;
				i++;
			}
			break ;
		}
		i++;
	}
}

void	find_label(t_crw *champ)
{
	int		i;
	char	*str;
	int		sum;

	sum = 0;
	str = NULL;
	if (champ->labels[champ->l_size].arg_now == 1)
		str = champ->labels[champ->l_size].l_name_1;
	else if (champ->labels[champ->l_size].arg_now == 2)
		str = champ->labels[champ->l_size].l_name_2;
	else if (champ->labels[champ->l_size].arg_now == 3)
		str = champ->labels[champ->l_size].l_name_3;
	i = 0;
	while_in_find_label(champ, str, &sum, i);
	if (champ->labels[champ->l_size].arg_now == 1)
		champ->labels[champ->l_size].r1 = sum;
	else if (champ->labels[champ->l_size].arg_now == 2)
		champ->labels[champ->l_size].r2 = sum;
	else if (champ->labels[champ->l_size].arg_now == 3)
		champ->labels[champ->l_size].r3 = sum;
}

int		find_lab_aft_cmd(t_crw *champ, char *l_name, int start, int arg)
{
	int i;
	int sum;

	i = start;
	sum = 0;
	while (i < champ->l_size + 1)
	{
		if (ft_contains(l_name, champ->labels[i]))
			break ;
		sum += champ->labels[i].arg_1 + champ->labels[i].arg_2 +\
		champ->labels[i].arg_3 + 1 + champ->labels[i].cmd_t;
		i++;
		if (i == champ->l_size + 1)
			return (0);
	}
	if (arg == 1)
		champ->labels[start].r1 = sum;
	else if (arg == 2)
		champ->labels[start].r2 = sum;
	else if (arg == 3)
		champ->labels[start].r3 = sum;
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_initialization_free.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 11:44:37 by gjigglyp          #+#    #+#             */
/*   Updated: 2021/01/14 14:44:49 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	free_label(t_lbl label)
{
	t_l *to_del;
	t_l *tmp;

	to_del = label.start;
	while (to_del)
	{
		tmp = to_del->next;
		free(to_del);
		to_del = tmp;
	}
}

void	free_all(t_crw ch)
{
	int i;

	i = 0;
	while (i < ch.l_size + 1)
	{
		free_label(ch.lbls[i]);
		i++;
	}
	free(ch.lbls);
	exit(0);
}

void	zeroing_values(t_crw *ch, int i, int j)
{
	while (j != 256)
	{
		ch->lbls[i].l_name_1[j] = '\0';
		ch->lbls[i].l_name_2[j] = '\0';
		ch->lbls[i].l_name_3[j] = '\0';
		j++;
	}
	j = 0;
	while (j != 6)
	{
		ch->lbls[i].cmd_n[j] = '\0';
		j++;
	}
	ch->lbls[i].is_label_or_not = 0;
	ch->lbls[i].cmd_t = 0;
	ch->lbls[i].r1 = 0;
	ch->lbls[i].r2 = 0;
	ch->lbls[i].r3 = 0;
	ch->lbls[i].arg_now = 0;
}

void	init_crw(t_crw *ch)
{
	int i;
	int j;

	j = 0;
	i = 0;
	ch->l_size = 0;
	if (!(ch->lbls = malloc(sizeof(t_lbl) * 250)))
		free_and_call(*ch, MEM_ALL);
	while (i != 250)
	{
		ch->lbls[i].names = NULL;
		ch->lbls[i].start = NULL;
		ch->lbls[i].arg_1 = 0;
		ch->lbls[i].arg_2 = 0;
		ch->lbls[i].arg_3 = 0;
		ch->lbls[i].arg_now = 0;
		ch->lbls[i].t1 = 0;
		ch->lbls[i].t2 = 0;
		ch->lbls[i].t3 = 0;
		zeroing_values(ch, i, j);
		i++;
	}
}

void	increase_crw(t_crw *ch)
{
	int i;
	int j;

	j = 0;
	if ((ch->l_size + 1) % 250 == 0)
	{
		ch->lbls = realloc(ch->lbls, ch->l_size + 251);
		i = ch->l_size + 1;
		ch->lbls[i].names = NULL;
		while (i != 250 + ch->l_size)
		{
			ch->lbls[i].arg_1 = 0;
			ch->lbls[i].arg_2 = 0;
			ch->lbls[i].arg_3 = 0;
			zeroing_values(ch, i, j);
			i++;
		}
	}
	ch->l_size++;
}

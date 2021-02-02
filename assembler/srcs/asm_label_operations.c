/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_label_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 14:57:55 by gjigglyp          #+#    #+#             */
/*   Updated: 2021/02/01 20:31:14 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** проверка меток на валидность
*/

int				is_lbl_or_not(char *word)
{
	int			len;

	len = (int)ft_strlen(word);
	if (len > 1 && word[len - 1] == LABEL_CHAR)
	{
		len -= 2;
		while (len >= 0)
		{
			if (ft_strchr(LABEL_CHARS, word[len]) == NULL)
				return (0);
			len--;
		}
		return (1);
	}
	return (0);
}

/*
** инициализация меток
*/

void			init_newlbl(t_lbl **tmp, char *word, int id)
{
	tmp[0] = (t_lbl*)ft_memalloc(sizeof(t_lbl));
	tmp[0]->name = ft_strdup(word);
	tmp[0]->id = id;
	tmp[0]->pos = -1;
}

t_lbl			*labadd(t_lbl **label, char *word)
{
	int			id;
	int			len;
	t_lbl		*res;
	t_lbl		*tmp;

	len = ft_strlen(word);
	id = 1;
	res = *label;
	if (len > 0)
		word[len - 1] = '\0';
	while (res != NULL && res->next != NULL && ft_strcmp(res->name, word) != 0)
	{
		id++;
		res = res->next;
	}
	if (res != NULL && ft_strcmp(res->name, word) == 0)
		return (res);
	if (res != NULL)
		id++;
	init_newlbl(&tmp, word, id);
	if (res == NULL)
		*label = tmp;
	else
		res->next = tmp;
	return (tmp);
}

void			checklbl(t_crw *crw, char **aw, int nw)
{
	t_lbl		*lbl;

	if ((crw->if_name_exist == 0) || (crw->if_cmnt_exist == 0))
		call_simple_error(ERR_EST);
	lbl = labadd(&crw->lbl, aw[0]);
	if (lbl->pos != -1)
		call_simple_error(LBL_DUP);
	if (crw->size_code == 0)
		lbl->pos = 0;
	else
		lbl->pos = crw->last_cmnd->pos + crw->last_cmnd->size;
	if (nw > 1 && is_lbl_or_not(aw[1]))
		checklbl(crw, &aw[1], nw - 1);
	else if (nw > 1 && is_cmnd_or_not(aw[1]) > 0)
		check_cmnd(crw, &aw[1], is_cmnd_or_not(aw[1]), nw - 1);
	else if (nw > 1)
		call_simple_error(ER_I_ST);
	else
		crw->arp += ft_strlen(crw->string) - 1;
}

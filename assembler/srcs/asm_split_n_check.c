/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_split_n_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 14:08:58 by gjigglyp          #+#    #+#             */
/*   Updated: 2021/01/26 19:13:59 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** проверка содержимого файла
*/

void		tokensplit(t_crw *crw)
{
	while (crw->arp < (int)crw->sf)
	{
		if (!comment_skip(crw))
		{
			ft_bzero(crw->string, 1000);
			strread(crw);
			if (ft_strchr(crw->string, '.'))
			{
				if ((crw->af[crw->arp] == '.')
					&& (crw->af[crw->arp + 1] == 'n'))
					check_name(crw);
				else if ((crw->af[crw->arp] == '.')
						&& (crw->af[crw->arp + 1] == 'c'))
					check_cmnt(crw);
				else
					call_simple_error("ERROR: invalid cmnd after '.'\n");
			}
			else
			{
				label_and_cmnd(crw);
				if (!comment_skip(crw))
					crw->arp++;
			}
		}
	}
}

/*
** проверка на несуществующий label
*/

void		nonex_lbls(t_crw *crw)
{
	t_lbl	*tmp;

	tmp = crw->lbl;
	while (tmp)
	{
		if (tmp->pos == -1)
			call_simple_error("ERROR: non-existent label in argument\n");
		tmp = tmp->next;
	}
}

/*
** выводим ошибку, если в подаваемом нам файле не будет исполняемого кода
*/

void		nonex_code(t_crw *crw)
{
	if (crw->cmnd == NULL && crw->lbl == NULL)
		call_simple_error("ERROR: execution code not exist\n");
}

/*
** обработка файла
*/

void		split_n_check(t_crw *crw)
{
	tokensplit(crw);
	nonex_code(crw);
	nonex_lbls(crw);
}

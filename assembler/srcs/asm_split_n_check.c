/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_split_n_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 14:08:58 by gjigglyp          #+#    #+#             */
/*   Updated: 2021/01/27 16:04:21 by gjigglyp         ###   ########.fr       */
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
		if (!cmntskip(crw))
		{
			ft_bzero(crw->string, 1000);
			strread(crw);
			if (ft_strchr(crw->string, '.'))
			{
				if ((crw->af[crw->arp] == '.')
					&& (crw->af[crw->arp + 1] == 'n'))
					namecheck(crw);
				else if ((crw->af[crw->arp] == '.')
					&& (crw->af[crw->arp + 1] == 'c'))
					cmntcheck(crw);
				else
					call_simple_error(ER_IN_C);
			}
			else
			{
				lbl_and_cmnd(crw);
				if (!cmntskip(crw))
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
			call_simple_error(LAB_EXI);
		tmp = tmp->next;
	}
}

/*
** выводим ошибку, если в подаваемом нам файле не будет исполняемого кода
*/

void		nonex_code(t_crw *crw)
{
	if (crw->cmnd == NULL && crw->lbl == NULL)
		call_simple_error(NO_COMM);
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

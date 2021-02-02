/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_filler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 15:03:12 by gjigglyp          #+#    #+#             */
/*   Updated: 2021/02/01 20:27:57 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** заполнение имени
*/

void		fill_name(t_crw *crw)
{
	int		i;

	if (!(crw->name = (char *)malloc(sizeof(char) * PROG_NAME_LENGTH + 1)))
		call_simple_error(MEM_ALL);
	i = 0;
	crw->arp++;
	while (crw->af[crw->arp] != '\"')
	{
		if (crw->af[crw->arp] == '\0')
			call_simple_error(ER_IN_F);
		if (i > 127)
			call_simple_error(LONG_NA);
		crw->name[i] = crw->af[crw->arp];
		crw->arp++;
		i++;
	}
	crw->name[i] = '\0';
	crw->if_name_exist = 1;
	crw->arp++;
}

/*
** заполнение комментария
*/

void		fill_cmnt(t_crw *crw)
{
	int		i;

	if (!(crw->cmnt = (char *)malloc(sizeof(char) * COMMENT_LENGTH + 1)))
		call_simple_error(MEM_ALL);
	i = 0;
	crw->arp++;
	while (crw->af[crw->arp] != '\"')
	{
		if (crw->af[crw->arp] == '\0')
			call_simple_error(ER_IN_F);
		if (i > 2047)
			call_simple_error(LONG_CO);
		crw->cmnt[i] = crw->af[crw->arp];
		crw->arp++;
		i++;
	}
	crw->cmnt[i] = '\0';
	crw->if_cmnt_exist = 1;
	crw->arp++;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_filler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 15:03:12 by gjigglyp          #+#    #+#             */
/*   Updated: 2021/01/26 16:37:24 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		fill_name(t_crw *crw)
{
	int		i;

	if (!(crw->name = (char *)malloc(sizeof(char) * PROG_NAME_LENGTH + 1)))
		call_simple_error("ERROR: no memory allocated\n");
	i = 0;
	crw->arp++;
	while (crw->af[crw->arp] != '\"')
	{
		if (crw->af[crw->arp] == '\0')
			call_simple_error("ERROR: invalid file\n");
		if (i > 127)
			call_simple_error("ERROR: name of champion too long\n");
		crw->name[i] = crw->af[crw->arp];
		crw->arp++;
		i++;
	}
	crw->name[i] = '\0';
	crw->if_name_exist = 1;
	crw->arp++;
}

void		fill_cmnt(t_crw *crw)
{
	int		i;

	if (!(crw->cmnt = (char *)malloc(sizeof(char) * COMMENT_LENGTH + 1)))
		call_simple_error("ERROR: no memory allocated\n");
	i = 0;
	crw->arp++;
	while (crw->af[crw->arp] != '\"')
	{
		if (crw->af[crw->arp] == '\0')
			call_simple_error("ERROR: invalid file\n");
		if (i > 2047)
			call_simple_error("ERROR: comment of champion too long\n");
		crw->cmnt[i] = crw->af[crw->arp];
		crw->arp++;
		i++;
	}
	crw->cmnt[i] = '\0';
	crw->if_cmnt_exist = 1;
	crw->arp++;
}

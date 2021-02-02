/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_check1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 14:38:07 by gjigglyp          #+#    #+#             */
/*   Updated: 2021/02/01 20:08:57 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		lbl_and_cmnd(t_crw *crw)
{
	char	*tmp_str;
	char	**aw;
	int		nw;

	if (ft_strlen(crw->string) == 0)
		return ;
	tmp_str = add_spaces(crw->string);
	aw = split_string(tmp_str);
	free_str_arr(&tmp_str, NULL, 1);
	nw = 0;
	while (aw[nw])
		nw++;
	if (is_lbl_or_not(aw[0]))
		checklbl(crw, aw, nw);
	else if (is_cmnd_or_not(aw[0]) != 0)
		check_cmnd(crw, aw,
				is_cmnd_or_not(aw[0]), nw);
	else
		call_simple_error(ER_IN_C);
	free_str_arr(NULL, &aw, 0);
}

void		namecheck(t_crw *crw)
{
	if ((ft_strncmp(&crw->af[crw->arp], NAME_CMD_STRING, 5)) == 0)
	{
		if (crw->if_name_exist == 1)
			call_simple_error(MORE_CH);
		crw->arp += 5;
		spaceskip(crw);
		if (crw->af[crw->arp] == '\"')
		{
			if (crw->af[crw->arp + 1] == '\"')
			{
				crw->if_name_exist = 1;
				crw->arp += 2;
			}
			else
				fill_name(crw);
			checkfs(crw);
		}
		else
			call_simple_error(CHA_NAM);
	}
	else
		call_simple_error(ER_IN_C);
}

/*
** проверка комментария
*/

void		cmntcheck(t_crw *crw)
{
	if ((ft_strncmp(&crw->af[crw->arp], COMMENT_CMD_STRING, 8)) == 0)
	{
		if (crw->if_cmnt_exist == 1)
			call_simple_error(MORE_CH);
		crw->arp += 8;
		spaceskip(crw);
		if (crw->af[crw->arp] == '\"')
		{
			if (crw->af[crw->arp + 1] == '\"')
			{
				crw->if_cmnt_exist = 1;
				crw->arp += 2;
			}
			else
				fill_cmnt(crw);
			checkfs(crw);
		}
		else
			call_simple_error(CHA_COM);
	}
	else
		call_simple_error(ER_IN_C);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_skip.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 14:34:45 by gjigglyp          #+#    #+#             */
/*   Updated: 2021/01/29 18:31:19 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		if_is_space(char c)
{
	if (c == '\t' || c == '\v' || c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

void	spaceskip(t_crw *crw)
{
	while (if_is_space(crw->af[crw->arp]))
		crw->arp++;
}

int		cmntskip(t_crw *crw)
{
	if (!(crw->af[crw->arp] == COMMENT_CHAR
		|| crw->af[crw->arp] == ALT_COMMENT))
		return (0);
	else
		while (crw->af[crw->arp] != '\n')
			crw->arp++;
	return (1);
}

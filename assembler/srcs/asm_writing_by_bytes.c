/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_writing_by_bytes.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 17:34:02 by gjigglyp          #+#    #+#             */
/*   Updated: 2021/01/15 16:41:31 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** запись 1 байта
*/

void	writing_1b(t_crw *ch, unsigned int wr)
{
	ch->exec_code[ch->ind_wr++] = (unsigned char)(wr);
}

/*
** запись 2 байтов
*/

void	writing_2b(t_crw *ch, unsigned int wr)
{
	unsigned char	buf;
	int				sh;

	sh = 8;
	while (sh >= 0)
	{
		buf = (unsigned char)((wr >> sh));
		ch->exec_code[ch->ind_wr] = buf;
		sh -= 8;
		ch->ind_wr++;
	}
}

/*
** запись 4 байтов
*/

void	writing_4b(t_crw *ch, unsigned int wr)
{
	unsigned char	buf;
	int				sh;

	sh = 24;
	while (sh >= 0)
	{
		buf = (unsigned char)((wr >> sh));
		ch->exec_code[ch->ind_wr] = buf;
		sh -= 8;
		ch->ind_wr++;
	}
}

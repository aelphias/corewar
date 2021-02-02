/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_writer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 14:45:34 by gjigglyp          #+#    #+#             */
/*   Updated: 2021/01/29 18:08:30 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** запись имени
*/

void				nwrite(t_crw *crw)
{
	int				i;

	i = 0;
	bytewrite(crw->fd, COREWAR_EXEC_MAGIC, 4);
	if (crw->name != NULL)
	{
		while (crw->name[i])
		{
			bytewrite(crw->fd, crw->name[i], 1);
			i++;
		}
	}
	while (i < 132)
	{
		bytewrite(crw->fd, 0, 1);
		i++;
	}
	bytewrite(crw->fd, crw->size_code, 4);
}

/*
** запись комментария
*/

void				comwrite(t_crw *crw)
{
	int				i;

	i = 0;
	if (crw->cmnt != NULL)
	{
		while (crw->cmnt[i])
		{
			bytewrite(crw->fd, crw->cmnt[i], 1);
			i++;
		}
	}
	while (++i < 2053)
		bytewrite(crw->fd, 0, 1);
}

/*
** запись комманд
*/

void				cmndwrite(t_crw *crw)
{
	t_lbl			*label;
	t_cmnd			*cmnd;
	int				i;

	cmnd = crw->cmnd;
	while (cmnd)
	{
		label = crw->lbl;
		count_lbl(label, cmnd);
		bytewrite(crw->fd, cmnd->cm_code, 1);
		if (sc(cmnd) != 0 && sc(cmnd) != 128)
			bytewrite(crw->fd, sc(cmnd), 1);
		i = 0;
		while (i <= 2)
		{
			if (cmnd->argtype[i] == 0)
				break ;
			bytewrite(crw->fd, cmnd->argument[i],
													cmnd->argsize[i]);
			i++;
		}
		cmnd = cmnd->next;
	}
}

/*
** запись байтов
*/

void				bytewrite(int fd, int c, int cb)
{
	int				j;
	unsigned char	m[cb];

	j = cb;
	while (cb)
	{
		cb--;
		m[cb] = (unsigned char)c;
		c >>= 8;
	}
	while (cb < j)
	{
		write(fd, &m[cb], 1);
		cb++;
	}
}

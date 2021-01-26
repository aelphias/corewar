/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_writer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 14:45:34 by gjigglyp          #+#    #+#             */
/*   Updated: 2021/01/26 19:13:32 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void				nwrite(t_crw *parser)
{
	int				i;

	i = 0;
	bytes_write(parser->fd, COREWAR_EXEC_MAGIC, 4);
	if (parser->name != NULL)
	{
		while (parser->name[i])
		{
			bytes_write(parser->fd, parser->name[i], 1);
			i++;
		}
	}
	while (i < 132)
	{
		bytes_write(parser->fd, 0, 1);
		i++;
	}
	bytes_write(parser->fd, parser->size_code, 4);
}

void				comwrite(t_crw *parser)
{
	int				i;

	i = 0;
	if (parser->cmnt != NULL)
	{
		while (parser->cmnt[i])
		{
			bytes_write(parser->fd, parser->cmnt[i], 1);
			i++;
		}
	}
	while (++i < 2053)
		bytes_write(parser->fd, 0, 1);
}

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
		bytes_write(crw->fd, cmnd->cm_code, 1);
		if (sc(cmnd) != 0 && sc(cmnd) != 128)
			bytes_write(crw->fd, sc(cmnd), 1);
		i = 0;
		while (i <= 2)
		{
			if (cmnd->argument_type[i] == 0)
				break ;
			bytes_write(crw->fd, cmnd->argument[i],
													cmnd->argument_size[i]);
			i++;
		}
		cmnd = cmnd->next;
	}
}

void				bytes_write(int fd, int c, int cb)
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

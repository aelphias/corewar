/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 14:26:14 by gjigglyp          #+#    #+#             */
/*   Updated: 2021/02/01 20:26:33 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** чтение файла
*/

void			asm_fileread(int fd, t_crw *crw)
{
	char		buf[10000];

	if ((crw->sf = read(fd, buf, 10000)) < 0)
		call_simple_error(ER_F_RD);
	if (!(crw->af = malloc(sizeof(char) * crw->sf)))
		call_simple_error(ERR_F_C);
	else
		ft_memcpy(crw->af, buf, crw->sf);
}

/*
** чтение строки
*/

void			strread(t_crw *crw)
{
	int			p[2];

	spaceskip(crw);
	p[0] = crw->arp;
	p[1] = 0;
	while (crw->af[p[0]] != '\n' &&
		crw->af[p[0]] != COMMENT_CHAR &&
		crw->af[p[0]] != ALT_COMMENT)
	{
		crw->string[p[1]] = crw->af[p[0]];
		p[0]++;
		p[1]++;
	}
	crw->string[p[1]] = '\0';
}

/*
** запись содержимого
*/

void			ncc_write(t_crw *crw)
{
	nwrite(crw);
	comwrite(crw);
	cmndwrite(crw);
}

/*
** запись файлового дескриптора
*/

void			write_fd(char *av, t_crw *crw)
{
	char		*fn;
	int			alen;

	alen = ft_strlen(av);
	fn = ft_strsub(av, 0, alen - 2);
	fn = ft_strjoin_for_asm(fn, ".cor", 0);
	fn[ft_strlen(fn) - 1] = '\0';
	crw->fd = open(fn, O_WRONLY | O_CREAT | O_TRUNC, 0600);
	ncc_write(crw);
	ft_printf("Writing output program to %s\n", fn);
	free(fn);
	close(crw->fd);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 14:26:14 by gjigglyp          #+#    #+#             */
/*   Updated: 2021/01/26 18:20:31 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			asm_fileread(int fd, t_crw *crw)
{
	char		buf[10000];

	if ((crw->sf = read(fd, buf, 10000)) < 0)
		call_simple_error("ERROR: Unable to read file");
	if (!(crw->af = malloc(sizeof(char) * crw->sf)))
		call_simple_error(ERR_F_C);
	ft_memcpy(crw->af, buf, crw->sf);
}

void			strread(t_crw *crw)
{
	int			p;
	int			i;

	spaceskip(crw);
	p = crw->arp;
	i = 0;
	while (crw->af[p] != '\n' &&
		crw->af[p] != COMMENT_CHAR &&
		crw->af[p] != ALT_COMMENT)
	{
		crw->string[i] = crw->af[p];
		p++;
		i++;
	}
	crw->string[i] = '\0';
}

void			ncc_write(t_crw *crw)
{
	nwrite(crw);
	comwrite(crw);
	cmndwrite(crw);
}

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

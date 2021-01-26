/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assembler_mode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 11:44:53 by gjigglyp          #+#    #+#             */
/*   Updated: 2021/01/26 17:05:24 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		print_usage(void)
{
	ft_printf("Usage: ./asm [champion.s]\n \
				champion.s   — assemble->bytecode\n");
}

void		call_simple_error(char *error)
{
	ft_printf("ERROR: %s\n", error);
	exit(1);
}

t_crw		*init_crw(int fd)
{
	t_crw	*crw;

	if (!(crw = (t_crw *)malloc(sizeof(t_crw))))
		call_simple_error("ERROR: no memory allocated\n");
	crw->fd = fd;
	crw->af = NULL;
	crw->name = NULL;
	crw->if_name_exist = 0;
	crw->cmnt = NULL;
	crw->if_cmnt_exist = 0;
	crw->sf = 0;
	crw->size_code = 0;
	crw->arp = 0;
	crw->cmnd = NULL;
	crw->last_cmnd = NULL;
	crw->lbl = NULL;
	ft_bzero(crw->string, 1000);
	return (crw);
}

int				assembler_mode(char *nof)
{
	int			alen;
	int			fd;
	t_crw		*crw;

	alen = 0;
	if ((fd = open(nof, O_RDONLY)) == -1)
		print_usage();
	if (fd < 3 || read(fd, NULL, 0) < 0)
		print_usage();
	alen = ft_strlen(nof);
	if (nof[alen - 2] != '.' || nof[alen - 1] != 's')
		print_usage();
	crw = init_crw(fd);
	asm_fileread(crw->fd, crw);
	if (!(crw->af[crw->sf - 1] == '\n'))
		call_simple_error("ERROR: finish of file is not '\\n'\n");
	split_n_check(crw);
	write_fd(nof, crw);
	exit(0);
}

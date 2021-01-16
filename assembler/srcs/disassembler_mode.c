/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disassembler_mode.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 11:45:53 by gjigglyp          #+#    #+#             */
/*   Updated: 2021/01/16 17:07:15 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "asm.h"

/*
** включение режима дизасемблера
** nof - название файла
*/

int			disassembler_mode(char *nof)
{
	int		wr_fd;
	int		rd_fd;

	rd_fd = open(nof, O_RDONLY);
	nof = dasm_change_ex(nof, ".cor", ".s");
	wr_fd = open(nof, O_CREAT | O_WRONLY | O_TRUNC, 0777);
	disasm_header(wr_fd, rd_fd);
	disasm_chcmd(wr_fd, rd_fd);
	ft_printf("Writing output program to %s\n", nof);
	free(nof);
	return (0);
}

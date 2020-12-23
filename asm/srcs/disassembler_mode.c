/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disassembler_mode.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 16:41:21 by gjigglyp          #+#    #+#             */
/*   Updated: 2020/12/22 15:08:04 by gjigglyp         ###   ########.fr       */
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
	disasm_cmd(wr_fd, rd_fd);
	ft_printf("Writing output program to %s\n", nof);
	free(nof);
	return (0);
}

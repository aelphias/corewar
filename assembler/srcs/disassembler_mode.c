/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disassembler_mode.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 11:45:53 by gjigglyp          #+#    #+#             */
/*   Updated: 2021/01/15 14:55:09 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "asm.h"

/*
** включение режима дизасемблера
** nof - название файла
** ПОРЯДОК ДЕЙСТВИЙ:
** 1) Открываем файл (для чтения)
** 2) меняем расширение
** 3) Открываем файл для записи
** 4) Дизассемблируем хедер
** 5) То же самое проделываем с командами
** 6) Очищаем память
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

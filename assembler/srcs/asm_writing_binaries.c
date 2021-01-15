/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_writing_binaries.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 11:44:20 by gjigglyp          #+#    #+#             */
/*   Updated: 2021/01/15 14:03:26 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	write_bin_head(t_crw *ch)
{
	int i;

	i = 0;
	writing_4b(ch, (unsigned int)COREWAR_EXEC_MAGIC);
	while (ch->name[i])
	{
		ch->exec_code[ch->ind_wr++] = ch->name[i++];
	}
	ch->ind_wr = PROG_NAME_LENGTH + 8;
	writing_4b(ch, (unsigned int)ch->code_size);
	i = 0;
	while (i < COMMENT_LENGTH && ch->comment[i])
	{
		ch->exec_code[ch->ind_wr++] = ch->comment[i++];
	}
	ch->ind_wr = PROG_NAME_LENGTH + COMMENT_LENGTH + 16;
}

/*
** Обработка аргументов, запись 1, 2 или 4 байт
*/

void	proargz(t_crw *ch, int i)
{
	if (ch->lbls[i].arg_1 == 1)
		writing_1b(ch, ch->lbls[i].r1);
	else if (ch->lbls[i].arg_1 == 2)
		writing_2b(ch, ch->lbls[i].r1);
	else if (ch->lbls[i].arg_1 == 4)
		writing_4b(ch, ch->lbls[i].r1);
	if (ch->lbls[i].arg_2 == 1)
		writing_1b(ch, ch->lbls[i].r2);
	else if (ch->lbls[i].arg_2 == 2)
		writing_2b(ch, ch->lbls[i].r2);
	else if (ch->lbls[i].arg_2 == 4)
	{
		writing_4b(ch, ch->lbls[i].r2);
	}
	if (ch->lbls[i].arg_3 == 1)
		writing_1b(ch, ch->lbls[i].r3);
	else if (ch->lbls[i].arg_3 == 2)
		writing_2b(ch, ch->lbls[i].r3);
	else if (ch->lbls[i].arg_3 == 4)
		writing_4b(ch, ch->lbls[i].r3);
}

/*
** записываем выполняемый код
*/

void	excode_write(t_crw *ch)
{
	int i;

	i = 0;
	while (i < ch->l_size)
	{
		ch->exec_code[ch->ind_wr++] = ch->lbls[i].cmd_c;
		if (ch->lbls[i].cmd_t == 1)
			ch->exec_code[ch->ind_wr++] = count_cta(ch, i);
		proargz(ch, i);
		i++;
	}
}

/*
** 1) Подсчёт размера кода
** 2) Находим размер выполняемого когда
** 3) Если не удалось выделить память под выполняемый код -> 
*/

void	bincodeconvert(t_crw *ch, int fd)
{
	int i;
	int exec_size;

	i = 0;
	ch->code_size = cs_count(ch);
	exec_size = 16 + PROG_NAME_LENGTH + COMMENT_LENGTH + ch->code_size;
	if (!(ch->exec_code = malloc(sizeof(char) * (exec_size))))
		free_and_call(*ch, MEM_ALL);
	zero_exec(ch, exec_size);
	ch->ind_wr = 0;
	write_bin_head(ch);
	excode_write(ch);
	write(fd, ch->exec_code, exec_size);
	i = 0;
}

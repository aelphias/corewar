/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_writing_binaries.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 11:44:20 by gjigglyp          #+#    #+#             */
/*   Updated: 2021/01/14 14:44:28 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	write_bin_head(t_crw *ch)
{
	int i;

	i = 0;
	writing_four_bytes(ch, (unsigned int)COREWAR_EXEC_MAGIC);
	while (ch->name[i])
	{
		ch->exec_code[ch->ind_wr++] = ch->name[i++];
	}
	ch->ind_wr = PROG_NAME_LENGTH + 8;
	writing_four_bytes(ch, (unsigned int)ch->code_size);
	i = 0;
	while (i < COMMENT_LENGTH && ch->comment[i])
	{
		ch->exec_code[ch->ind_wr++] = ch->comment[i++];
	}
	ch->ind_wr = PROG_NAME_LENGTH + COMMENT_LENGTH + 16;
}

void	process_args(t_crw *ch, int i)
{
	if (ch->lbls[i].arg_1 == 1)
		writing_one_byte(ch, ch->lbls[i].r1);
	else if (ch->lbls[i].arg_1 == 2)
		writing_two_bytes(ch, ch->lbls[i].r1);
	else if (ch->lbls[i].arg_1 == 4)
		writing_four_bytes(ch, ch->lbls[i].r1);
	if (ch->lbls[i].arg_2 == 1)
		writing_one_byte(ch, ch->lbls[i].r2);
	else if (ch->lbls[i].arg_2 == 2)
		writing_two_bytes(ch, ch->lbls[i].r2);
	else if (ch->lbls[i].arg_2 == 4)
	{
		writing_four_bytes(ch, ch->lbls[i].r2);
	}
	if (ch->lbls[i].arg_3 == 1)
		writing_one_byte(ch, ch->lbls[i].r3);
	else if (ch->lbls[i].arg_3 == 2)
		writing_two_bytes(ch, ch->lbls[i].r3);
	else if (ch->lbls[i].arg_3 == 4)
		writing_four_bytes(ch, ch->lbls[i].r3);
}

void	excode_write(t_crw *ch)
{
	int i;

	i = 0;
	while (i < ch->l_size)
	{
		ch->exec_code[ch->ind_wr++] = ch->lbls[i].cmd_c;
		if (ch->lbls[i].cmd_t == 1)
			ch->exec_code[ch->ind_wr++] = count_code_type_arg(ch, i);
		process_args(ch, i);
		i++;
	}
}

void	to_bin_code(t_crw *ch, int fd)
{
	int i;
	int exec_size;

	i = 0;
	ch->code_size = count_code_size(ch);
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

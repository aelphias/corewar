/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_writing_binaries.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 17:35:11 by gjigglyp          #+#    #+#             */
/*   Updated: 2020/12/19 17:35:13 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	write_bin_head(t_crw *champ)
{
	int i;

	i = 0;
	writing_four_bytes(champ, (unsigned int)COREWAR_EXEC_MAGIC);
	while (champ->name[i])
	{
		champ->exec_code[champ->ind_wr++] = champ->name[i++];
	}
	champ->ind_wr = PROG_NAME_LENGTH + 8;
	writing_four_bytes(champ, (unsigned int)champ->code_size);
	i = 0;
	while (i < COMMENT_LENGTH && champ->comment[i])
	{
		champ->exec_code[champ->ind_wr++] = champ->comment[i++];
	}
	champ->ind_wr = PROG_NAME_LENGTH + COMMENT_LENGTH + 16;
}

void	process_args(t_crw *champ, int i)
{
	if (champ->labels[i].arg_1 == 1)
		writing_one_byte(champ, champ->labels[i].r1);
	else if (champ->labels[i].arg_1 == 2)
		writing_two_bytes(champ, champ->labels[i].r1);
	else if (champ->labels[i].arg_1 == 4)
		writing_four_bytes(champ, champ->labels[i].r1);
	if (champ->labels[i].arg_2 == 1)
		writing_one_byte(champ, champ->labels[i].r2);
	else if (champ->labels[i].arg_2 == 2)
		writing_two_bytes(champ, champ->labels[i].r2);
	else if (champ->labels[i].arg_2 == 4)
	{
		writing_four_bytes(champ, champ->labels[i].r2);
	}
	if (champ->labels[i].arg_3 == 1)
		writing_one_byte(champ, champ->labels[i].r3);
	else if (champ->labels[i].arg_3 == 2)
		writing_two_bytes(champ, champ->labels[i].r3);
	else if (champ->labels[i].arg_3 == 4)
		writing_four_bytes(champ, champ->labels[i].r3);
}

void	write_exec_code(t_crw *champ)
{
	int i;

	i = 0;
	while (i < champ->l_size)
	{
		champ->exec_code[champ->ind_wr++] = champ->labels[i].cmd_c;
		if (champ->labels[i].cmd_t == 1)
			champ->exec_code[champ->ind_wr++] = count_code_type_arg(champ, i);
		process_args(champ, i);
		i++;
	}
}

void	to_bin_code(t_crw *champ, int fd)
{
	int i;
	int exec_size;

	i = 0;
	champ->code_size = count_code_size(champ);
	exec_size = 16 + PROG_NAME_LENGTH + COMMENT_LENGTH + champ->code_size;
	if (!(champ->exec_code = malloc(sizeof(char) * (exec_size))))
		free_all(*champ, "Error: memory didn't allocated\n");
	zero_exec(champ, exec_size);
	champ->ind_wr = 0;
	write_bin_head(champ);
	write_exec_code(champ);
	write(fd, champ->exec_code, exec_size);
	i = 0;
}

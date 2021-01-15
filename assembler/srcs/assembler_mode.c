/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assembler_mode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 11:44:53 by gjigglyp          #+#    #+#             */
/*   Updated: 2021/01/15 13:46:46 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		print_usage(void)
{
	ft_printf("Usage: ./asm (chion.s|champion.cor)\n\
				\tchampion.s\t\t— assemble->bytecode\n\
				\tchampion.cor\t— assemble<-bytecode\n");
	
		exit(0);
}

/*
** 1) Выводим usage если нет названия файла
** 2) инициализация структуры
** 3) проверка файла на валидность
** 4) проверка типа аргументов
** 5) Если размер метки 0 -> выходим из проекта
*/

void		main_val(t_crw *ch, char *nof)
{
	if (!nof)
		print_usage();
	init_crw(ch);
	is_file_valid_or_not(nof, ch);
	check_type_arg(ch);
	if (ch->l_size == 0)
		exit(-1);
}

/*
** 1) Валидация (функция и ее описание выше)
** 2) Меняем расширение файла с .s на .cor (в дизассемблере наоборот)
** 3) Очищаем память, если файл не валиден или его не существует
** 4) ИНАЧЕ - переводим в бинарный код и очищаем выделенную память
*/

int			assembler_mode(char *nof)
{
	t_crw	crw;
	int		fd;

	main_val(&crw, nof);
	nof = change_ex(nof, ".s", ".cor");
	if (!(fd = open(nof, O_CREAT | O_WRONLY | O_TRUNC, 0777)))
		free_and_call(crw, ER_IN_F);
	bincodeconvert(&crw, fd);
	ft_printf("Writing output program to %s\n", nof);
	free(nof);
	free(crw.exec_code);
	free_all(crw);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 17:01:39 by gjigglyp          #+#    #+#             */
/*   Updated: 2020/12/19 18:18:31 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** получение данных в ассемблере
*/

t_crw				*get_asm_data(t_crw *asm_data)
{
	static t_crw	*sd;

	if (!sd)
		sd = asm_data;
	return (sd);
}

/*
** проверяем, является ли подаваемый аргумент файлом
** ex - расширение файла
** fn - название файла
*/

int				is_filename(const char *fn, const char *ex)
{
	if (ex && fn && ft_strlen(fn) >= ft_strlen(ex))
		return (!ft_strcmp(ft_strchr(fn, '\0') - ft_strlen(ex), ex));
	else
		return (0);
}

/*
** здесь выводится тип ошибки в случае её выявления
*/

int				call_error(char const *const err)
{
	ft_putstr_fd("ERROR: ", 2);
	ft_putendl_fd(err, 2);
	exit(-1);
}

/*
** main function
*/

int				main(int ac, char *av[])
{
	if (ac != 2)
		call_error(ERR_USE);
	else if (ac == 2 && is_filename(*(av + 1), ".s"))
	{
		ft_printf("Translating assembly to bytecode...\n");
		assembler_mode(*(av + 1));
	}
	else if (ac == 2 && is_filename(*(av + 1), ".cor"))
	{
		ft_printf("Translating bytecode to assembly...\n");
		disassembler_mode(*(av + 1));
	}
	else
		call_error(ERR_UNF);
	return (0);
}

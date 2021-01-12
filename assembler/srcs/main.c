/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 11:43:24 by gjigglyp          #+#    #+#             */
/*   Updated: 2021/01/05 15:05:25 by gjigglyp         ###   ########.fr       */
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

int					is_filename(const char *fn, const char *ex)
{
	if (ex && fn && ft_strlen(fn) >= ft_strlen(ex))
		return (!ft_strcmp(ft_strchr(fn, '\0') - ft_strlen(ex), ex));
	else
		return (0);
}

/*
** main function
*/

int					main(int ac, char *av[])
{
	if (ac != 2)
		ft_printf("ERROR: %s\n", ERR_USE);
	else if (ac == 2 && is_filename(*(av + 1), ".s"))
		assembler_mode(*(av + 1));
	else if (ac == 2 && is_filename(*(av + 1), ".cor"))
		disassembler_mode(*(av + 1));
	else
		ft_printf("ERROR: %s\n", ERR_UNF);
	return (0);
}

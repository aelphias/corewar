/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 11:43:24 by gjigglyp          #+#    #+#             */
/*   Updated: 2021/01/29 18:27:40 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** проверяем, является ли подаваемый аргумент файлом
** ex - расширение файла
** fn - название файла
*/

int					is_fn(const char *fn, const char *ex)
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
	{
		print_usage();
		return (0);
	}
	else if (ac == 2 && is_fn(*(av + 1), ".s"))
		assembler_mode(*(av + 1));
	else
		ft_printf("ERROR: %s\n", ERR_UNF);
	return (0);
}

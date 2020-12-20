/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disassembler_mode.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 16:41:21 by gjigglyp          #+#    #+#             */
/*   Updated: 2020/12/19 16:43:50 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "asm.h"

/*
** подсчет длины числа
*/

static int	ft_numlen(int n, int minus)
{
	int		numlen;

	numlen = 1;
	while ((n /= 10))
		numlen++;
	return (numlen + minus);
}

char		*ft_itoa_1(int n)
{
	char	*str;
	int		numlen;
	int		minus;
	int		digit;

	minus = (n < 0) ? 1 : 0;
	numlen = ft_numlen(n, minus);
	if ((str = ft_strnew((size_t)numlen)))
	{
		str[numlen--] = '\0';
		while (numlen >= minus)
		{
			digit = n % 10;
			str[numlen--] = (char)((digit < 0 ? -digit : digit) + '0');
			n /= 10;
		}
		if (minus)
			str[0] = '-';
	}
	return (str);
}

/*
** включение режима дизасемблера
*/

int			disassembler_mode(char *name_of_the_file)
{
	int		wr_fd;
	int		rd_fd;

	rd_fd = open(name_of_the_file, O_RDONLY);
	name_of_the_file = dasm_change_ex(name_of_the_file, ".cor", ".s");
	wr_fd = open(name_of_the_file, O_CREAT | O_WRONLY | O_TRUNC, 0777);
	disasm_header(wr_fd, rd_fd);
	disasm_cmd(wr_fd, rd_fd);
	write(1, "Writing output program to ", 26);
	write(1, name_of_the_file, ft_strlen(name_of_the_file));
	write(1, "\n", 1);
	free(name_of_the_file);
	return (0);
}

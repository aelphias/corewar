/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 11:43:09 by gjigglyp          #+#    #+#             */
/*   Updated: 2021/01/15 14:16:04 by gjigglyp         ###   ########.fr       */
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

char		*ft_dasm_itoa(int n)
{
	char	*str;
	int		nl;
	int		minus_sign_marker;
	int		dig;

	minus_sign_marker = (n < 0) ? 1 : 0;
	nl= ft_numlen(n, minus_sign_marker);
	if ((str = ft_strnew((size_t)nl)))
	{
		str[nl--] = '\0';
		while (nl >= minus_sign_marker)
		{
			dig = n % 10;
			str[nl--] = (char)((dig < 0 ? -dig : dig) + '0');
			n /= 10;
		}
		if (minus_sign_marker)
			str[0] = '-';
	}
	return (str);
}

/*
** вызов ошибки
*/

int			call_simple_error(char const *err)
{
	ft_putstr_fd("ERROR: ", 2);
	ft_putendl_fd(err, 2);
	exit(-1);
}

/*
** очистка памяти и выведение типа ошибки в терминал
*/

void		free_and_call(t_crw ch, char *err)
{
	ft_printf("ERROR: %s\n", err);
	free_all(ch);
}

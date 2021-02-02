/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_types.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 15:26:07 by gjigglyp          #+#    #+#             */
/*   Updated: 2021/01/29 18:18:55 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** проверяем на допустимые символы
*/

int			is_oac(char *admit, char *arg)
{
	int		i;
	int		len;

	i = 0;
	len = (int)ft_strlen(arg);
	while (i < len)
	{
		if (!ft_strchr(admit, arg[i]))
			return (0);
		i++;
	}
	return (1);
}

/*
** проверка типа
*/

int			check_type(char *arg)
{
	int		res;

	res = 0;
	if (is_oac(LAB_CHARS, arg) == 0)
		return (0);
	else if (arg[0] == 'r' && arg[1] != ':')
		res = 1;
	else if (arg[0] == 'r' && arg[1] == ':')
		res = -1;
	else if (arg[0] == '%' && arg[1] != ':')
		res = 2;
	else if (arg[0] == '%' && arg[1] == ':')
		res = -2;
	else if (ft_isdigit(arg[0]) || arg[0] == '-')
		res = 3;
	else if (arg[0] == ':')
		res = -3;
	if ((res == 1 && is_oac(ALLOWED_DIR_CHARS, &arg[1]) == 0)
		|| (res == 2 && is_oac(ALLOWED_DIR_CHARS, &arg[1]) == 0)
		|| (res == 3 && is_oac(ALLOWED_DIR_CHARS, arg) == 0))
		return (0);
	return (res);
}

void		fill_cmnd_arr(t_cmnd *cmnd, int an, int at)
{
	if (at < 0)
		at = -at;
	if (at == 1 || at == -1)
	{
		cmnd->argsize[an] = 1;
		cmnd->argtype[an] = REG_CODE;
	}
	else if (at == 3 || at == -3)
	{
		cmnd->argsize[an] = 2;
		cmnd->argtype[an] = IND_CODE;
	}
	else if (at == 2 || at == -2)
	{
		cmnd->argsize[an] = g_op[cmnd->cm_code - 1].t_dir_size;
		cmnd->argtype[an] = DIR_CODE;
	}
}

void		setargnum(t_cmnd *cmnd, char *arg, int an, int at)
{
	int		c;
	int		of;

	c = 0;
	while (arg[c])
		c++;
	if (at == 1 || at == 2)
		of = 1;
	else
		of = 0;
	if (at > 0 && (ft_strlen(&arg[of]) < 1 || (arg[of] == '-' &&
		(ft_strlen(&arg[of]) < 2 || ft_strlen(&arg[of]) > 11)) || \
		ft_strlen(&arg[of]) > 10))
		call_simple_error(ARG_INV);
	if (arg[1] >= '0' && arg[1] <= '9')
	{
		if (arg[0] == 'r' && c > 3)
			call_simple_error(ARG_INV);
	}
	cmnd->argument[an] = ft_atoi(&arg[of]) * (at > 0);
	fill_cmnd_arr(cmnd, an, at);
}

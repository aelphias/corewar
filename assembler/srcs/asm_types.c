/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_types.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 15:26:07 by gjigglyp          #+#    #+#             */
/*   Updated: 2021/01/26 16:50:57 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			is_oac(char *allowed, char *arg)
{
	int		i;
	int		len;

	i = 0;
	len = (int)ft_strlen(arg);
	while (i < len)
	{
		if (!ft_strchr(allowed, arg[i]))
			return (0);
		i++;
	}
	return (1);
}

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

void		fill_cmnd_arr(t_cmnd *cmnd, int args_num, int arg_type)
{
	if (arg_type < 0)
		arg_type = -arg_type;
	if (arg_type == 1 || arg_type == -1)
	{
		cmnd->argument_size[args_num] = 1;
		cmnd->argument_type[args_num] = REG_CODE;
	}
	else if (arg_type == 3 || arg_type == -3)
	{
		cmnd->argument_size[args_num] = 2;
		cmnd->argument_type[args_num] = IND_CODE;
	}
	else if (arg_type == 2 || arg_type == -2)
	{
		cmnd->argument_size[args_num] =
								g_op[cmnd->cm_code - 1].t_dir_size;
		cmnd->argument_type[args_num] = DIR_CODE;
	}
}

void		set_argument_value(t_cmnd *cmnd, char *arg,
								int args_num, int arg_type)
{
	int		k;
	int		offset;

	k = 0;
	while (arg[k])
		k++;
	if (arg_type == 1 || arg_type == 2)
		offset = 1;
	else
		offset = 0;
	if (arg_type > 0 && (ft_strlen(&arg[offset]) < 1 ||
		(arg[offset] == '-' && (ft_strlen(&arg[offset]) < 2
		|| ft_strlen(&arg[offset]) > 11)) || ft_strlen(&arg[offset]) > 10))
		call_simple_error("ERROR: argument '%s' is invalid\n");
	if (arg[1] >= '0' && arg[1] <= '9')
	{
		if (arg[0] == 'r' && k > 3)
			call_simple_error("ERROR: argument '%s' is invalid\n");
	}
	cmnd->argument[args_num] = ft_atoi(&arg[offset]) * (arg_type > 0);
	fill_cmnd_arr(cmnd, args_num, arg_type);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_action.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denis <denis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 21:50:05 by denis             #+#    #+#             */
/*   Updated: 2020/10/05 08:33:01 by denis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	split_args(char **res, char ***tmp, int argc, int line_nr)
{
	int			i[3];

	i[0] = 0;
	i[2] = 0;
	while (tmp[i[0]] != NULL && i[0] < argc)
	{
		i[1] = 0;
		while (tmp[i[0]][i[1]] && i[2] <= MAX_ARGS)
		{
			if (ft_strlen(tmp[i[0]][i[1]]) > 0)
			{
				res[i[2]] = ft_strdup(tmp[i[0]][i[1]]);
				i[2]++;
			}
			i[1]++;
		}
		free_str_arr(NULL, &tmp[i[0]], 0);
		i[0]++;
	}
	if (i[2] > 3)
		exit(!!ft_printf_fd(2, "ERROR: excess args (>MAX_ARGS) at line %d\n",
				line_nr));
	res[i[2]] = 0;
}

static char	**get_clean(int argc, char **argv, int line_nr)
{
	char		**res;
	char		***tmp;
	int			i;

	if (MAX_ARGS < 1)
		call_error(MARG_NV);
	res = (char**)ft_memalloc(sizeof(char*) * (MAX_ARGS + 1));
	tmp = (char***)ft_memalloc(sizeof(char**) * (argc + 1));
	i = 0;
	while (i < argc)
	{
		tmp[i] = ft_strsplit(argv[i], ',');
		i++;
	}
	split_args(res, tmp, argc, line_nr);
	free(tmp);
	return (res);
}

int			get_argz(t_op *op, char **argv, int argc, t_crw *crwdata)
{
	char	**clean_args;
	int		i;
	int		args_q;
	int		allowed_types;

	clean_args = get_clean(argc, argv, crwdata->line_q);
	i = 0;
	while (clean_args[i] != NULL)
		i++;
	args_q = ARGS_QTY[op->inst_id];
	if (i != args_q)
		exit(!!ft_printf_fd(2, "ERROR: wrong arguments amount(line %d)\n",
							crwdata->line_q));
	allowed_types = ARGS_TYPES[op->inst_id];
	if (set_argz(op, args_q, allowed_types, clean_args) < 0)
		call_error(ARG_III);
	op->octet *= OCTAL[op->inst_id];
	free_str_arr(NULL, &clean_args, 0);
	return (0);
}

void	set_arg_value(t_op *op, char *arg, int arg_nr, int arg_type)
{
	int		offset;
	t_crw	*crwdata;

	crwdata = get_data(NULL);
	if (arg_type == 1 || arg_type == 2)
		offset = 1;
	else
		offset = 0;
	if (arg_type > 0 && (ft_strlen(&arg[offset]) < 1 ||
		(arg[offset] == '-' && (ft_strlen(&arg[offset]) < 2
		|| ft_strlen(&arg[offset]) > 11)) || ft_strlen(&arg[offset]) > 10))
		exit(!!ft_printf_fd(2, "ERROR: argument '%s' is invalid (line %d)\n",
				arg, crwdata->line_q));
	op->argu[arg_nr] = ft_atoi(&arg[offset]) * (arg_type > 0);
	if (arg_type < 0)
		arg_type = -arg_type;
	op->octet = op->octet | (arg_type << (6 - 2 * arg_nr));
	if (arg_type == 1 || arg_type == -1)
		op->arg_size[arg_nr] = 1;
	else if (arg_type == 3 || arg_type == -3)
		op->arg_size[arg_nr] = 2;
	else if (arg_type == 2 || arg_type == -2)
		op->arg_size[arg_nr] = T_DIR_SIZE[op->inst_id];
}

int		check_type(char *arg)
{
	int		res;

	res = 0;
	if (only_admitted_chars(ALLOWED_ARG_CHARS, arg) == 0)
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
	if ((res == 1 && only_admitted_chars(ALLOWED_DIR_CHARS, &arg[1]) == 0)
		|| (res == 2 && only_admitted_chars(ALLOWED_DIR_CHARS, &arg[1]) == 0)
		|| (res == 3 && only_admitted_chars(ALLOWED_DIR_CHARS, arg) == 0))
		return (0);
	return (res);
}

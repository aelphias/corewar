/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_getsetarg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 15:17:16 by gjigglyp          #+#    #+#             */
/*   Updated: 2021/01/26 16:53:53 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			split_args(char **res, char ***tmp, int nb_arg)
{
	int			i[3];

	i[0] = 0;
	i[2] = 0;
	while (tmp[i[0]] != NULL && i[0] < nb_arg)
	{
		i[1] = 0;
		while (tmp[i[0]][i[1]] && i[2] <= 3)
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
		call_simple_error("ERROR: invalid argument(s) at line\n");
	res[i[2]] = 0;
}

int				set_argument(char *arg, int anb, int at, t_crw *crw)
{
	int			arg_type;
	int			aux;
	char		*tmp;
	t_lbl		*label;
	t_cmnd		*cmnd;

	cmnd = crw->last_cmnd;
	arg_type = check_type(arg);
	aux = (arg_type > 2) + (-1) * (arg_type < -2);
	if (arg_type == 0 || ((arg_type + aux) & at) == 0
		|| (arg_type == -1 && is_oac(LABEL_CHARS, &arg[2]) == 0)
		|| (arg_type == -2 && is_oac(LABEL_CHARS, &arg[2]) == 0)
		|| (arg_type == -3 && is_oac(LABEL_CHARS, &arg[1]) == 0))
		return (-1);
	if (arg_type < 0)
	{
		tmp = ft_strjoin(&arg[1 + (arg_type > -3)], ":\0");
		label = labadd(&crw->lbl, tmp);
		cmnd->arg_is_lbl[anb] = label->id;
		free_str_arr(&tmp, NULL, 1);
	}
	set_argument_value(cmnd, arg, anb, arg_type);
	return (0);
}

int				get_args(t_cmnd *cmnd, char **args, int nb_arg,
							t_crw *crw)
{
	char		**clean_args;
	int			i;
	int			an;
	int			sa;

	commcheck(args, nb_arg);
	minch(args, nb_arg);
	clean_args = get_clean(args, nb_arg);
	i = 0;
	while (clean_args[i] != NULL)
		i++;
	an = g_op[cmnd->cm_code - 1].args_num;
	if (i != an)
		call_simple_error("ERROR: wrong arguments amount\n");
	sa = set_args(cmnd, clean_args, an, crw);
	if (sa < 0)
		call_simple_error("ERROR: invalid argument(s) at line\n");
	free_str_arr(NULL, &clean_args, 0);
	return (0);
}

int				set_args(t_cmnd *cmnd, char **clean_args, int an, t_crw *crw)
{
	int			i;
	int			at;
	int			sa;

	at = g_op[cmnd->cm_code - 1].args_types[0] * 100 +
		g_op[cmnd->cm_code - 1].args_types[1] * 10 +
		g_op[cmnd->cm_code - 1].args_types[2];
	i = 0;
	sa = 1;
	while (i + an < 3)
	{
		at /= 10;
		i++;
	}
	while (an > 0)
	{
		an--;
		sa = set_argument(clean_args[an], an, (at % 10), crw);
		if (sa < 0)
			return (-1);
		at /= 10;
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_getsetarg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 15:17:16 by gjigglyp          #+#    #+#             */
/*   Updated: 2021/02/02 18:49:06 by aelphias         ###   ########.fr       */
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
		call_simple_error(ARG_INV);
	res[i[2]] = 0;
}

int				setarg(char *arg, int anb, int at, t_crw *crw)
{
	t_lbl		*label;
	t_cmnd		*cmnd;
	int			ax[2];
	char		*tmp;

	cmnd = crw->last_cmnd;
	ax[0] = check_type(arg);
	ax[1] = (ax[0] > 2) + (-1) * (ax[0] < -2);
	if (ax[0] == 0 || ((ax[0] + ax[1]) & at) == 0
		|| (ax[0] == -1 && is_oac(LABEL_CHARS, &arg[2]) == 0)
		|| (ax[0] == -2 && is_oac(LABEL_CHARS, &arg[2]) == 0)
		|| (ax[0] == -3 && is_oac(LABEL_CHARS, &arg[1]) == 0))
		return (-1);
	if (ax[0] < 0)
	{
		tmp = ft_strjoin(&arg[1 + (ax[0] > -3)], ":\0");
		label = labadd(&crw->lbl, tmp);
		cmnd->arg_is_lbl[anb] = label->id;
		free_str_arr(&tmp, NULL, 1);
	}
	setargnum(cmnd, arg, anb, ax[0]);
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
		call_simple_error(ARG_III);
	sa = set_args(cmnd, clean_args, an, crw);
	if (sa < 0)
		call_simple_error(ARG_INV);
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
		sa = setarg(clean_args[an], an, (at % 10), crw);
		if (sa < 0)
			return (-1);
		at /= 10;
	}
	return (1);
}

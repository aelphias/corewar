/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 15:11:39 by gjigglyp          #+#    #+#             */
/*   Updated: 2021/02/01 20:17:16 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_cmnd			*init_cm_lst(t_cmnd *cmnd, int id_cm, t_crw *crw)
{
	t_cmnd		*cmnds;
	int			i;

	i = 0;
	cmnds = crw->cmnd;
	while (cmnds->next != NULL)
	{
		i += cmnds->size;
		cmnds = cmnds->next;
	}
	cmnd->cm_code = g_op[id_cm - 1].code;
	ft_bzero(cmnd->argument, 3);
	ft_bzero(cmnd->arg_is_lbl, 3);
	ft_bzero(cmnd->argsize, 3);
	cmnd->size = 0;
	cmnd->pos = crw->size_code;
	crw->last_cmnd = cmnd;
	return (cmnd);
}

char			**get_clean(char **args, int nb_arg)
{
	char		**res;
	char		***tmp;
	int			i;

	res = (char**)ft_memalloc(sizeof(char*) * 4);
	tmp = (char***)ft_memalloc(sizeof(char**) * (nb_arg + 1));
	i = 0;
	while (i < nb_arg)
	{
		tmp[i] = ft_strsplit(args[i], ',');
		i++;
	}
	split_args(res, tmp, nb_arg);
	free(tmp);
	return (res);
}

void			commcheck(char **args, int an)
{
	int			i;
	int			j;
	int			c;

	c = 0;
	i = 0;
	while (i < an)
	{
		j = 0;
		while (args[i][j])
		{
			if (args[i][j] == ',')
				c += 1;
			j++;
		}
		i++;
	}
	if (an == 3 && c != 2)
		call_simple_error(ER_I_AR);
	if (an == 2 && c != 1)
		call_simple_error(ER_I_AR);
	if (an == 1 && c != 0)
		call_simple_error(ER_I_AR);
}

/*
** проверка на знак минус
*/

void			minch(char **args, int an)
{
	int			i;
	int			j;

	i = 0;
	while (i < an)
	{
		j = 1;
		if (args[i][0] == '%')
			j = 2;
		while (args[i][j])
		{
			if (args[i][j] == '-')
				call_simple_error(ER_I_AR);
			j++;
		}
		i++;
	}
}

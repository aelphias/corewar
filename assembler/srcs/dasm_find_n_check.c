/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dasm_find_n_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 18:17:23 by gjigglyp          #+#    #+#             */
/*   Updated: 2021/01/15 14:08:23 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*dasm_change_ex(char *fn, char *old, char *new)
{
	char	*bn;
	int		len;

	len = ft_strlen(fn);
	if (len < 5 || ft_strcmp(&fn[len - 4], ".cor") != 0)
	{
		ft_printf(ERR_UNF);
		exit(-1);
	}
	bn = ft_strsub(fn, 0, ft_strlen(fn) - ft_strlen(old));
	if (!bn)
	{
		exit(-1);
	}
	if (!(fn = ft_strjoin(bn, new)))
	{
		exit(-1);
	}
	ft_strdel(&bn);
	return (fn);
}

char	*find_cmd(t_dasm *dis)
{
	int i;

	i = 0;
	while (i < 16)
	{
		if (g_op[i].code == dis->c)
			break ;
		i++;
	}
	dis->arg_type = (int)g_op[i].args_types_code;
	dis->cmd_n = g_op[i].name;
	dis->dir_size = g_op[i].t_dir_size;
	return (g_op[i].name);
}

void	check_arg_type(t_dasm *dis, int rd_fd)
{
	int i;

	i = 0;
	if (dis->arg_type == 1)
	{
		read(rd_fd, &dis->c, 1);
		dis->a[0] = dis->c >> 6;
		dis->a[1] = dis->c >> 4 & 3;
		dis->a[2] = dis->c >> 2 & 3;
	}
	else
	{
		while (i < 16)
		{
			if (g_op[i].code == dis->c)
				break ;
			i++;
		}
		dis->a[0] = g_op[i].args_types[0];
	}
}

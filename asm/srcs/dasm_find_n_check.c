/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dasm_find_n_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 14:58:52 by gjigglyp          #+#    #+#             */
/*   Updated: 2020/12/13 14:58:52 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*change_extension(char *filename, char *old, char *new)
{
	char	*basename;
	int		len;

	len = ft_strlen(filename);
	if (len < 5 || ft_strcmp(&filename[len - 4], ".cor") != 0)
	{
		write(1, "Wrong extansion\n", 16);
		exit(-1);
	}
	basename = ft_strsub(filename, 0, ft_strlen(filename) - ft_strlen(old));
	if (!basename)
	{
		exit(-1);
	}
	if (!(filename = ft_strjoin(basename, new)))
	{
		exit(-1);
	}
	ft_strdel(&basename);
	return (filename);
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
	dis->cmd_name = g_op[i].name;
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
		dis->arg1 = dis->c >> 6;
		dis->arg2 = dis->c >> 4 & 3;
		dis->arg3 = dis->c >> 2 & 3;
	}
	else
	{
		while (i < 16)
		{
			if (g_op[i].code == dis->c)
				break ;
			i++;
		}
		dis->arg1 = g_op[i].args_types[0];
	}
}
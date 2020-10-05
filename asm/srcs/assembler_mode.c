/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assembler_mode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denis <denis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 11:32:10 by denis             #+#    #+#             */
/*   Updated: 2020/09/29 12:59:13 by denis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char	*set_output_name(char *s)
{
	char	*name;
	char	**tmp;

	if (ft_strlen(s) < 1)
		exit(!!ft_printf_fd(2, "ERROR: output file name not defined\n"));
	tmp = ft_strsplit(s, '.');
	if (ft_strlen(tmp[0]) > 0)
		name = ft_strjoin(tmp[0], ".cor");
	else
		name = ft_strdup(".cor");
	if (ft_strlen(name) < 1)
		exit(!!ft_printf_fd(2, "ERROR: output file name couldn't be set\n"));
	free_str_arr(NULL, &tmp, 0);
	return (name);
}

void        assembler_mode(char *name_of_the_file)
{
    t_crw   *crwdata;
    char    *nameoffile;

    crwdata = (t_crw*)ft_memalloc(sizeof(t_crw));
    get_asm_data(crwdata);
    crwdata->fd_r = open(name_of_the_file, O_RDONLY);
    if (crwdata->fd_r < 4 || read(crwdata->fd_r, crwdata->name, 0) < 0)
        call_error(ER_F_RD);
    convloop(crwdata);
    checking_the_data(crwdata);
    nameoffile = set_output_name(name_of_the_file);
    crwdata->fd_w = open(nameoffile, O_WRONLY | O_TRUNC | O_CREAT, 0644);
    if (crwdata->fd_w < 3)
	   call_error(ERR_F_C);
	data_writing(crwdata);
	ft_printf("Writing output program to %s\n", nameoffile);
    close(crwdata->fd_w);
    close(crwdata->fd_r);
}
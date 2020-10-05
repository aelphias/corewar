/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denis <denis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 20:52:18 by denis             #+#    #+#             */
/*   Updated: 2020/09/29 12:01:00 by denis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_crw       *get_asm_data(t_crw *asm_data)
{
    static t_crw *sd;

	if (!sd)
		sd = asm_data;
	return (sd);
}

int			is_filename(const char *filename, const char *ext)
{
	if (filename && ext && ft_strlen(filename) >= ft_strlen(ext))
		return (!ft_strcmp(ft_strchr(filename, '\0') - ft_strlen(ext), ext));
	else
		return (0);
}

int         call_error(char const *const err)
{
	ft_putstr_fd("ERROR: ", 2);
	ft_putendl_fd(err, 2);
	exit(-1);
}

int         main(int ac, char *av[])
{
    if (ac < 2)
        call_error(ERR_USE);
	else if (ac == 2 && is_filename(*(av + 1), ".s"))
		assembler_mode(*(av + 1));
	//else if (ac == 2 && is_filename(*(av + 1), ".cor"))
	//	disassembler_mode(*(av + 1));
    return (0);
}
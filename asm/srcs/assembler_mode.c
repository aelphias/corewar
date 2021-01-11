/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assembler_mode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 11:44:53 by gjigglyp          #+#    #+#             */
/*   Updated: 2021/01/05 13:30:42 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		print_usage(void)
{
	ft_printf("Usage: ./asm (champion.s|champion.cor)\n\
				\tchampion.s   — assemble->bytecode\n\
				\tchampion.cor — assemble<-bytecode\n");
}

void		main_val(int argc, t_crw *champ, char **argv)
{
	if (argc == 1)
	{
		print_usage();
		exit(0);
	}
	init_crw(champ);
	if (argc != 2)
		exit(0);
	else
	{
		is_file_valid_or_not(argv[1], champ);
		check_type_arg(champ);
	}
	if (champ->l_size == 0)
		exit(-1);
}

int			assembler_mode(char *nof)
{
	t_crw	crw;
	int		fd;
	int		ac;
	char	**av;

	ac = 0;
	av = NULL;
	main_val(ac, &crw, av);
	nof = change_ex(nof, ".s", ".cor");
	if (!(fd = open(nof, O_CREAT | O_WRONLY | O_TRUNC, 0777)))
		free_and_call(crw, ER_IN_F);
	to_bin_code(&crw, fd);
	ft_printf("Writing output program to %s\n", nof);
	free(nof);
	free(crw.exec_code);
	free_all(crw);
	return (0);
}

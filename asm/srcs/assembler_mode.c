/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assembler_mode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 14:58:45 by gjigglyp          #+#    #+#             */
/*   Updated: 2020/12/13 14:58:45 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "asm.h"

void	print_usage(void)
{
	write(1, "Usage: ./asm (champion.s|champion.cor)\n", 40);
	write(1, "    champion.s   — from assemble to bytecode\n", 47);
	write(1, "    champion.cor — from bytecode to assemble\n", 47);
}

void	main_val(int argc, t_crw *champ, char **argv)
{
	if (argc == 1)
	{
		print_usage();
		exit(0);
	}
	init_array(champ);
	if (argc != 2)
		exit(0);
	else
	{
		is_file_valid_or_not(argv[1], champ);
		type_argument_check(champ);
	}
	if (champ->l_size == 0)
		exit(-1);
}

int		assembler_mode(char *name_of_the_file)
{
	t_crw	crw;
	int		fd;

	main_validation(argc, &crw, argv);
	name_of_the_file = change_extension(name_of_the_file, ".s", ".cor");
	if (!(fd = open(name_of_the_file, O_CREAT | O_WRONLY | O_TRUNC, 0777)))
		free_all(crw, "Error: invalid file\n");
	to_bin_code(&crw, fd);
	write(1, "Writing output program to ", 26);
	write(1, name_of_the_file, ft_strlen(name_of_the_file));
	write(1, "\n", 1);
	free(name_of_the_file);
	free(crw.exec_code);
	free_all(crw, NULL);
	return (0);
}

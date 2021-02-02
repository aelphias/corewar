/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarron <sdarron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 20:51:41 by aelphias          #+#    #+#             */
/*   Updated: 2021/01/30 12:51:13 by sdarron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

int		is_num(char *str)
{
	while (*str)
	{
		if (!(ft_isdigit(*str)))
			return (0);
		str++;
	}
	return (1);
}

void	check_flags(int argc, char **argv, t_vm *vm)
{
	int	i;
	int	flag;

	flag = 0;
	i = 0;
	while (i <= argc)
	{
		if ((ft_strcmp(argv[i], "-dump")) == 0)
		{
			if (argc <= 2)
				print_error(ERR_USE);
			if (argc == i)
				print_error(ERR_USE);
			if (flag == 1)
				error_one_dump();
			if (!(is_num(argv[i + 1])))
				print_error(ERR_USE);
			vm->dump = ft_atoi(argv[i + 1]);
			flag = 1;
			if (vm->dump < 0)
				error_pos_number();
		}
		i++;
	}
}

void	check_n_flags(int argc, char **argv, t_plr *plr)
{
	int	num[4];
	int	plrs;
	int	nflag;

	plrs = plr_count(plr);
	ft_bzero(num, 0);
	nflag = right_n_flag(argc, argv);
	if (nflag)
	{
		checkdotcor_and_chech_n(argc, argv, num, plr);
		plr = sort_list_plr(plr);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 20:51:41 by aelphias          #+#    #+#             */
/*   Updated: 2021/01/09 16:25:09 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int	is_num(char *str)
{
	while (*str)
	{
		if (!(ft_isdigit(*str)))
			return (0);
		str++;
	}
	return (1);
}

void check_flags(int argc, char **argv, t_vm *vm)
{
	int i;
	int flag;

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
			{
				//free
				write(2, "USE ONE VALUE FOR DUMP\n", 23);
				exit(1);
			}
			if (!(is_num(argv[i + 1])))
			{
				print_error(ERR_USE);
				exit(1);
			}
			vm->dump = ft_atoi(argv[i + 1]);
			flag = 1;
			if (vm->dump < 0)
			{
				//free
				write(2, "USE POSITIVE NUMBER FOR DUMP\n", 29);
				exit(1);
			}
		}
		i++;
	}
}

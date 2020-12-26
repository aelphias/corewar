/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharlet <kcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 20:51:41 by aelphias          #+#    #+#             */
/*   Updated: 2020/12/24 19:29:36 by kcharlet         ###   ########.fr       */
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

void check_flags(int argc, char **argv, t_flg *flg, t_plr *plr)
{
	int i;

	i = 1;
	while (i <= argc)
	{
		if ((argv[i]) && !(ft_strcmp(argv[i], "-dump")))
		{	
			//argv[i + 1] ? 0 : print_error(ERR_USE);
			if (!(argv[i + 1])) 
				print_error(ERR_USE);
			if (!(is_num(argv[i + 1])))
				print_error(ERR_USE);
			flg->dump = ft_atoi(argv[i + 1]);
			i +=2;
		}
		if ((argv[i]) && !(ft_strcmp(argv[i], "-n")))
		{
			if (!(argv[i + 1]))
				print_error(ERR_USE);
			if (!(argv[i + 2]))
				print_error(ERR_USE);
			if (is_num(argv[i + 1]) && ft_strstr(argv[i + 2], ".cor"))
			{
				flg->n = ft_atoi(argv[i + 1]);
				read_from_file(plr, argv[1], 2); // пока без цикла, просто для одного игрока

				i +=2;
			}
			//else
			//	print_error(ERR_USE); 
		}
		if ((argv[i]) && ft_strstr(argv[i], ".cor"))
		{
			
			i +=2;
		}
		i++;
	}
}

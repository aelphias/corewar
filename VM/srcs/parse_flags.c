/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 20:51:41 by aelphias          #+#    #+#             */
/*   Updated: 2020/12/25 14:58:11 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void read_p(char *fname, t_plr **plr)
{
	int fd;
	
	fd = fopen(fname, O_RDONLY);
	
	fclose(fd);
}

void	try_to_read(char *fname, t_plr **plr)
{
	int fd;
	
	fd = fopen(fname, O_RDONLY);
	
	fclose(fd);
}

void check_flags(int argc, char **argv, t_flg *flg, t_plr **plr)
{
	int i;

	i = 1;
	while (i <= argc)
	{
		if (ft_strstr(argv[i], ".cor"))
		{
			try_to_read(argv[i], plr);
			puts("cool!");
		}
		
		i++;
	}
		/* 
	while (i <= argc)
	{
		if (!(ft_strcmp(argv[i], "-dump")))
		{	
			argv[i + 1] ? 0 : print_error(ERR_USE);
			if (!(argv[i + 1])) 
				print_error(ERR_USE);
			if (is_num(argv[i + 1]))
				print_error(ERR_USE);
			flg->dump = ft_atoi(argv[i + 1]);
			printf("flg->dump = %d\n", flg->dump); 
			i +=2;
		}
		else if (!(ft_strcmp(argv[i], "-n")))
		{
			if (!(argv[i + 1])) 
				print_error(ERR_USE);
			if (!(is_num(argv[i + 1])) && ft_strstr(argv[i + 2], ".cor"))
			{
				flg->n = ft_atoi(argv[i + 1]);
				plr->name = ft_strdup(argv[i + 2]);
				i +=3;
			}
		}
		else if (ft_strstr(argv[i], ".cor"))
		{
			plr->name = ft_strdup(argv[i + 2]);
			i +=2;
		}
		i++;
	} */
}

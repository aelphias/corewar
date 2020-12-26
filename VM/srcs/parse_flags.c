/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharlet <kcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 20:51:41 by aelphias          #+#    #+#             */
/*   Updated: 2020/12/26 14:03:30 by kcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"



void read_p(int fd, t_plr *plr)
{
	
}

int	check_magic(int fd)
{
	int i;
	int result;
	unsigned char buf[2];
	uint8_t		  magic[4];
	
	//result = read();
}

void	try_to_read(char *fname, t_plr *plr)
{
	int fd;
	
	fd = fopen(fname, O_RDONLY);
	if (fd = fopen(fname, O_RDONLY))
		print_error(ERR_FILE_OPEN);
	//check_magic(fd);
	fclose(fd);
}

void check_flags(int argc, char **argv, t_flg *flg, t_plr *plr)
{
	int i;

	i = 1;
	while (i <= argc)
	{
		if (ft_strstr(argv[i], ".cor"))
		{
			try_to_read(argv[i], plr);
			puts("has .cor\n");
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

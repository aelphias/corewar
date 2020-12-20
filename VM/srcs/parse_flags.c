/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 20:51:41 by aelphias          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2020/12/20 20:54:23 by aelphias         ###   ########.fr       */
=======
/*   Updated: 2020/12/19 21:36:56 by aelphias         ###   ########.fr       */
>>>>>>> 9c1ee0882eb7d560c543d5fda39774a9f00546f0
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
	printf("{is_num OK}\n");
	return (1);
}
/* 
int	is_name_cor(char *str)
{
	if (ft_strstr(str, ".cor"))
	{
		
	}
	
} */

void check_flags(int argc, char **argv, t_flg *flg, t_plr *plr)
{
	int i;

	i = 1;
<<<<<<< HEAD
	while (i <= argc)
	{
		if (!(ft_strcmp(argv[i], "-dump")))
		{	
			argv[i + 1] ? 0 : print_error(ERR_USE);
			if (is_num(argv[i + 1]))
				print_error(ERR_USE);
			flg->dump = ft_atoi(argv[i + 1]);
			printf("flg->dump = %d\n", flg->dump); 
			i +=2;
		}
		if (!(ft_strcmp(argv[i], "-n")))
		{
			if (!(is_num(argv[i + 1])))
				print_error(ERR_USE);
			if (ft_strstr(argv[i + 2], ".cor"))
			{
				flg->n = ft_atoi(argv[i + 1]);
				plr->name = ft_strdup(argv[i + 2]);
				i +=2;
			}
		}
		if (ft_strstr(argv[i], ".cor"))
		{
			plr->name = ft_strdup(argv[i + 2]);
			i +=2;
=======
	/*
	-dump n
	-n n
	*/
	while (i <= argc)
	{
		if (!(ft_strcmp(argv[i], "-dump")))
		{
			if (is_num(argv[i + 1]))
			{
				flg->dump = ft_atoi(argv[i + 1]);
				printf("flg->dump = %d\n", flg->dump); 
			}
		}
		if (!(ft_strcmp(argv[i], "-n")))
		{
			if (is_num(argv[i + 1]))
			{
				flg->n = ft_atoi(argv[i + 1]);
				printf("flg->n = %d\n", flg->n);
				
			}
>>>>>>> 9c1ee0882eb7d560c543d5fda39774a9f00546f0
		}
		i++;
	}
}
<<<<<<< HEAD
=======
/*
				if (ft_isdigit(argv[i + 1][0]))
*/
>>>>>>> 9c1ee0882eb7d560c543d5fda39774a9f00546f0

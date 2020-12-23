/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 20:51:41 by aelphias          #+#    #+#             */
/*   Updated: 2020/12/19 21:36:56 by aelphias         ###   ########.fr       */
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


void check_flags(int argc, char **argv, t_flg *flg)
{
	int i;

	i = 1;
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
		}
		i++;
	}
}
/*
				if (ft_isdigit(argv[i + 1][0]))
*/

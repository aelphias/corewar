/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 20:51:41 by aelphias          #+#    #+#             */
/*   Updated: 2020/12/19 16:02:22 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"


int	is_num(char *str)
{
	printf("{is_num}\n");
	while (str)
	{
	printf("str in is_num= %s\n", str);
		if (!(ft_isdigit(*str)))
			return (0);
		str++;
	}

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
		printf("argc %d\n ", argc);
	if (argc > 1)
	{
		while (i < argc)
		{
			if (!(ft_strcmp(argv[i], "-dump")))
			{
				printf("num_str= %s\n", argv[i + 1]);
				printf("num_int= %d\n", ft_atoi(argv[i + 1]));
				if (is_num(argv[i + 1]))
				{
					flg->dump = ft_atoi(argv[i + 1]);
					printf("flg->dump = %d\n", flg->dump); 
					
				}
			}
			i++;
		}
	}
}
/*
				if (ft_isdigit(argv[i + 1][0]))
*/
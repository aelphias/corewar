/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 21:11:43 by aelphias          #+#    #+#             */
/*   Updated: 2020/12/26 19:33:39 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void init_arena(char *map)
{
	unsigned int i;
	
	i = 0;
	while (++i < MEM_SIZE)
		map[i] = 0;
}

int	main(int argc, char **argv)
{
	unsigned char	map[MEM_SIZE];
	t_flg			*flg;
	t_plr			*plr; //  will void *p; work the same way?
	t_vm			*vm;
	
	( argc < 2 || argc > 5 ) ? print_error(ERR_USE) : 0;
	if (!(flg = (t_flg *)ft_memalloc(sizeof(t_flg))))
		print_error(ERR_MALLOC);
	ft_parse(argc - 1, argv, flg);
	init_arena(map);
	//test(flg, plr);
	return (0);
}

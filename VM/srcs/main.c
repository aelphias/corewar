/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharlet <kcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 21:11:43 by aelphias          #+#    #+#             */
/*   Updated: 2020/12/26 16:09:51 by kcharlet         ###   ########.fr       */
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
	ft_parse(argc - 1, argv, flg, &plr);
	init_arena(map);
	//test(flg, &plr);
	return (0);
}

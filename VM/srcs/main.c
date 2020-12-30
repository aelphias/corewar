/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 21:11:43 by aelphias          #+#    #+#             */
/*   Updated: 2020/12/27 20:35:48 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int	main(int argc, char **argv)
{
	unsigned char	arena[MEM_SIZE];
	t_flg			*flg;
	t_plr			*plr; //  will void *p; work the same way?
	t_vm			*vm;
	
	(argc < 2 || argc > 15) ? print_error(ERR_USE) : 0;
	if (!(flg = (t_flg *)ft_memalloc(sizeof(t_flg))))
		print_error(ERR_MALLOC);
	if (!(vm = (t_vm *)ft_memalloc(sizeof(t_vm))))
		print_error(ERR_MALLOC);
	check_flags(argc - 1, argv, flg);
	plr = ft_parse(argc - 1, argv, flg);
	ft_bzero(arena, MEM_SIZE);
	//ft_printf("Players count: %d\n", plr_count(plr));
	vm = make_pc(&vm, plr);
	//test(flg, plr);
	return (0);
}


/*
* TODO
* 0. Чистить структуры при ошибке
*/

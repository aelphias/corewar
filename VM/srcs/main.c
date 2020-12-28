/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharlet <kcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 21:11:43 by aelphias          #+#    #+#             */
/*   Updated: 2020/12/28 17:03:10 by kcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int	main(int argc, char **argv)
{
	unsigned char	arena[MEM_SIZE];
	t_flg			*flg;
	t_plr			*plr; //  will void *p; work the same way?
	t_vm			*vm;
	
	if ( argc < 2 || argc > MAX_PLAYERS )
		print_error(ERR_USE);
	if (!(flg = (t_flg *)ft_memalloc(sizeof(t_flg))))
		print_error(ERR_MALLOC);
	if (!(vm = (t_vm *)ft_memalloc(sizeof(t_vm))))
		print_error(ERR_MALLOC);
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

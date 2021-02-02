/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 21:11:43 by aelphias          #+#    #+#             */
/*   Updated: 2021/02/02 20:14:08 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

int		main(int argc, char **argv)
{
	uint8_t			arena[MEM_SIZE];
	t_vm			*vm;
	t_plr			*plr;
	t_car			*car;

	plr = NULL;
	car = NULL;
	if (argc < 2 || argc > 15)
		print_error(ERR_USE);
	ft_bzero(arena, MEM_SIZE);
	if (!(vm = (t_vm *)ft_memalloc(sizeof(t_vm))))
		print_error(ERR_MALLOC);
	init_vm(vm);
	check_flags(argc - 1, argv, vm);
	if (!(plr = ft_parse(argc - 1, argv, 0, 1)))
		print_error(ERR_PARSE);
	init_plr(vm, plr);
	check_n_flags(argc, argv, plr);
	if (!(car = make_car(plr, vm)))
		print_error(ERR_MAKE_CAR);
	introduce_plrs(plr);
	fill_arena(plr, arena);
	game(&car, arena, vm);
	free_all(plr, vm, car);
	return (0);
}

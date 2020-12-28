/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharlet <kcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 21:11:43 by aelphias          #+#    #+#             */
/*   Updated: 2020/12/28 19:08:31 by kcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/* void init_vm(t_vm *vm)
{
	
}

void ft_free_vm(t_vm *vm)
{
	
}

void ft_free_plr(t_plr *plr)
{
	
} */



int	main(int argc, char **argv)
{
	unsigned char	arena[MEM_SIZE];
	t_vm			*vm; // сваливаем сюда все по игре, кроме переменных каретки, которые поместим t_car 
	t_plr			*plr; // записываем все по игроку
	t_car			*car; // записываем все по каретке
	t_op			*op; // записываем все по операциям
	
	plr = NULL;
	car = NULL;
	op = NULL;

/*
*	1. пишем usages при неправильном вводе в консоли
*/
	if ( argc < 2 || argc > MAX_PLAYERS + 1 )
		print_error(ERR_USE);

/*
*	2. выделяем память под основную игровую структуру и инициализируем ее
*/

	if (!(vm = (t_vm *)ft_memalloc(sizeof(t_vm))))
		print_error(ERR_MALLOC);
	//init_vm(vm);

/*
*	3. Парсим строку стандартного ввода и файлы .cor, plr односвязный список игроков
*/

	if(!(plr = ft_parse(argc - 1, argv, vm)))
	{
		//ft_free_vm(vm);
		print_error(ERR_PARSE);
	}
	
/*
*	4. Инициализируем арену и создаем каретки
*/
	
	ft_bzero(arena, MEM_SIZE);
	//ft_printf("Players count: %d\n", plr_count(plr));
	if (!(car = make_car(plr, vm)))
	{
		//ft_free_vm(vm);
		//ft_fre_plr(plr);
		print_error(ERR_MAKE_CAR);
	}
	//test(vm, plr);
	return (0);
}


/*
* TODO
* 0. Чистить структуры при ошибке
*/

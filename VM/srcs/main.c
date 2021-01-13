/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarron <sdarron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 21:11:43 by aelphias          #+#    #+#             */
/*   Updated: 2021/01/13 13:40:59 by sdarron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
void ft_free_vm(t_vm *vm)
{
	
}
void ft_free_plr(t_plr *plr)
{
	
} */

int		main(int argc, char **argv)
{
	uint8_t			arena[MEM_SIZE];
	t_vm			*vm; // сваливаем сюда все по игре, кроме переменных каретки, которые поместим t_car 
	t_plr			*plr; // записываем все по игроку
	t_car			*car; // записываем все по каретке
	//t_op			op[17]; // записываем все по операциям. КАК правильно передать этот массив?
	
	plr = NULL;
	car = NULL;
/*
*	1. пишем usages при неправильном вводе в консоли
*/
	if (argc < 2 || argc > 15)
		print_error(ERR_USE);
	ft_bzero(arena, MEM_SIZE);
/*
*	2. выделяем память под основную игровую структуру и инициализируем ее
*/
	if (!(vm = (t_vm *)ft_memalloc(sizeof(t_vm))))
		print_error(ERR_MALLOC);
	//if (!(op[17] = (t_op *)ft_memalloc(sizeof(t_op[17]))))
	//	print_error(ERR_MALLOC);
	//init_op(op);
	init_vm(vm);
	//ft_printf("op[1].1 =%s\n",op[1].name);
/*
*	3. Парсим строку стандартного ввода и файлы .cor, plr односвязный список игроков
*/
	check_flags(argc - 1, argv, vm);
	if(!(plr = ft_parse(argc - 1, argv, 0, 1))) // указатель на начало списка (plr3->plr2->plr1) ?
	{
		//ft_free_vm(vm);
		print_error(ERR_PARSE);
	}
	check_n_flags(argc, argv, plr);
	print_list(plr);
/*
*	4. Инициализируем арену и создаем каретки
*/
	if (!(car = make_car(plr, vm)))
	{
		//ft_free_vm(vm);
		//ft_fre_plr(plr);
		print_error(ERR_MAKE_CAR);
	}
	print_list_car(car);
/*
*	5. Запись кода на арену и представление игроков перед началом игры 
*/
	introduce_plrs(plr);
	fill_arena(plr, vm, arena);
	//game(&car, arena, vm);

/*
*	6. test
*/
	
	//test(vm, plr);
	//print_list(plr);
	//print_list_car(car);
	return (0);
}

/*
* TODO
* 0. free() структуры при ошибке
* 1. развернуть список игроков/
*/

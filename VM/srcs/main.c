/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 21:11:43 by aelphias          #+#    #+#             */
/*   Updated: 2020/12/30 20:51:21 by aelphias         ###   ########.fr       */
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

void	introduce_plrs(t_plr *plr, t_vm *vm)
{
	unsigned int i;

	i = 1;
	ft_printf("Introducting contestants...\n");
	while (plr)
	{
		ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n", \
			i++, plr->codesize, plr->name, plr->cmnt);
		plr = plr->next;
	}
}

int		main(int argc, char **argv)
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
	ft_bzero(arena, MEM_SIZE);
/*
*	2. выделяем память под основную игровую структуру и инициализируем ее
*/
	if (!(vm = (t_vm *)ft_memalloc(sizeof(t_vm))))
		print_error(ERR_MALLOC);
	//init_vm(vm);
/*
*	3. Парсим строку стандартного ввода и файлы .cor, plr односвязный список игроков
*/
	check_flags(argc - 1, argv, vm);
	if(!(plr = ft_parse(argc - 1, argv, vm)))
	{
		//ft_free_vm(vm);
		print_error(ERR_PARSE);
	}
/*
*	4. Инициализируем арену и создаем каретки
*/
	if (!(car = make_car(plr, vm)))
	{
		//ft_free_vm(vm);
		//ft_fre_plr(plr);
		print_error(ERR_MAKE_CAR);
	}
/*
*	5. Запись кода на арену и представление игроков перед началом игры 
*/
	introduce_plrs(plr, vm);
	fill_arena(plr, vm, arena);
	//game(plr, car, arena, vm, op);
	
	//test(vm, plr);
	return (0);
}

/*
* TODO
* 0. free() структуры при ошибке
* 1. развернуть список игроков/
*/

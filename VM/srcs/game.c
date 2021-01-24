/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 17:56:48 by kcharlet          #+#    #+#             */
/*   Updated: 2021/01/24 19:14:01 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	check(t_vm *vm, t_car **head_car)
{
	vm->check_count++;
	vm->last_check_cycle = vm->cycles;
	bury_car(vm, head_car);
	if ((vm->lived >= NBR_LIVE) || (vm->check_count == MAX_CHECKS))
	{
		//ft_printf("have you ever tried? ----if ((vm->lived >= NBR_LIVE) || (vm->check_count == MAX_CHECKS))--\n");
		//ft_printf("{check() ))--\n");
		vm->cycles_to_die = vm->cycles_to_die - CYCLE_DELTA;
		vm->check_count = 0;
	}
	vm->lived = 0;
}
 
void	 exec(t_car *car, uint8_t *arena, t_op *op, t_vm *vm)
{
	car->dir_size_status = op->dir_size_status;  // (Размер T_DIR) бывает  4 и 2 byte
	car->is_type_code = op->is_type_code;
	get_args_type(car, arena, op);
	car->pos = update_pos(++car->pos); // после считывания кода операции или типово аргументов переступили на первый байт аргументов
	if (car->op_code == 1)
		op_live(car, arena, vm);
	else
		choose_1(car, arena);
}

bool	valid_op(t_car *car)
{
	if (car->op_code >= 1 && car->op_code <= 16)
		return (true);
	return (false);
}

void	cycle(t_car **head_car, uint8_t *arena, t_vm *vm)
{
	t_op	*op;
	t_car	*car;
	car = NULL;
	car = (*head_car);
	while (car)
	{
		if (car->wait == 0)
		{
			car->op_code = get_byte(arena, car); //считываем с карты
			if (valid_op(car))
			{
				op = &g_op[MINUS_ONE(car->op_code)];
				car->wait = op->cycles_wait;
			}
		}
		if (car->wait > 0)
			car->wait--;
		if (car->wait == 0)
		{
			if (valid_op(car))
			{
				op = &g_op[MINUS_ONE(car->op_code)];
				exec(car, arena, op, vm);
			}
			else
			{
				car->pos = update_pos(++car->pos);
				car->pc = car->pos;
			}
		}
		if (!(car->next) && (car->wait != 0))
			break ;
		car = car->next;
	}
}

void	game(t_car **head_car, uint8_t *arena, t_vm *vm)
{
	while (vm->car_count)
	{
		vm->cycles++;
		cycle(head_car, arena, vm);
		if (vm->cycles_to_die <= 0 
		|| ((vm->cycles - vm->last_check_cycle) == vm->cycles_to_die))// условие для проверки
			check(vm, head_car);
		if (vm->cycles == vm->dump)
		{
			dump(arena); //CHECK THIS
			return ;
		}
	}
	ft_printf("vm->cycles = %d\n", vm->cycles);
	ft_printf("vm->cycles_to_die = %d\n", vm->cycles_to_die);
	ft_printf("Player %d, won !\n", vm->winner_id);
}
/*
** Если код операции ошибочен, переместить каретку на следующий байт.
*/

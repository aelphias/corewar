/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 17:56:48 by kcharlet          #+#    #+#             */
/*   Updated: 2021/01/18 16:13:07 by aelphias         ###   ########.fr       */
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
		ft_printf("have you ever tried? ----if ((vm->lived >= NBR_LIVE) || (vm->check_count == MAX_CHECKS))--\n");
		ft_printf("{check() ))--\n");
		vm->cycles_to_die = vm->cycles_to_die - CYCLE_DELTA;
		vm->check_count = 0;
	}
	vm->lived = 0;
}
 
void	exec(t_car *car, uint8_t *arena, t_op *op, t_vm *vm)
{
	car->dir_size_status = op->dir_size_status;  // (Размер T_DIR) бывает  4 и 2 byte
	car->is_type_code = op->is_type_code;
	get_args_type(car, arena, op);
	car->pos++; // после считывания кода операции или типово аргументов переступили на первый байт аргументов
	op->func(car, arena, vm);   // и здесь мы страртуем операции
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
				exec(car, arena, op, vm);
			else
				car->pos++;
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
		|| ((vm->cycles - vm->last_check_cycle) == CYCLE_TO_DIE))// условие для проверки
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
** Если же код операции ошибочен, необходимо просто переместить каретку на следующий байт.
*/
//printf("-----.>dump----not_in_IF%d\n", vm->dump);
			//printf("----{inside game()}--Check() was called\n");

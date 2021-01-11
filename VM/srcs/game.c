/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 17:56:48 by kcharlet          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/01/11 19:12:22 by aelphias         ###   ########.fr       */
=======
/*   Updated: 2021/01/11 18:48:33 by gjigglyp         ###   ########.fr       */
>>>>>>> a1708f8594a6b6ad7290c44bf29659a1370a66c1
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	check(t_vm *vm, t_car **head_car)
{
	vm->check_count++;
	bury_car(vm, head_car);
	if (vm->lived >= NBR_LIVE || vm->check_count == MAX_CHECKS)
	{
		vm->cycles_to_die -= CYCLE_DELTA;
		vm->check_count = 0;
	}
	vm->lived = 0;
}
<<<<<<< HEAD
 
=======

>>>>>>> a1708f8594a6b6ad7290c44bf29659a1370a66c1
void	exec(t_car *car, uint8_t *arena, t_op *op)
{

/* 	if (car)
	{
		if (car->wait)
		car->wait--;
<<<<<<< HEAD
	else */
		op->func(car, arena);
	//}
=======
	else 
	{
		car->dir_size_status = op->dir_size_status;
		car->args_types_code = op->args_types_code;
		op->func(car, arena);
	}
	}
	
	
		//func[car->op_code](car, arena);
		//op[car->op_code].func(car, arena);
>>>>>>> a1708f8594a6b6ad7290c44bf29659a1370a66c1
}
/* 
Чтобы запустить цикл нужно:
init_car
 */

bool	valid_op(t_car *car)
{
	if (car->op_code >= 1 && car->op_code <= 16)
		return (true);
	return (false);
}

void	cycle(t_car **head_car, uint8_t *arena)
{
	t_car	*car;
	t_op *op;
	
	car = (*head_car);
	while (car)
	{
		if (car->wait == 0)
		{
			car->op_code = get_byte(arena, car->position); //считываем с карты
			if (valid_op(car))
			{
				op = &g_op[MINUS_ONE(car->op_code)];
				car->wait = op->cycles_wait;
			}
			else
			{
				car->position++;
				if (!(car->next))
					break;
				car = car->next;
			}
		}
		if (car->wait != 0)
			car->wait--;
		if (car->wait == 0)
		{
			exec(car, arena, op);
			car->wait = 0;
			car->op_code = 0;
		}
		if (!(car->next) && (car->wait != 0))
			break;
		car = car->next;
	}
}

void	game(t_car **head_car, uint8_t *arena, t_vm *vm)
{
	while (vm->car_count)
	{
		vm->cycles++;
		cycle(head_car, arena); 
		if (!(vm->cycles_to_die) || (vm->cycles % vm->cycles_to_die) == 0) // условие для проверки
			check(vm, head_car); 
			//printf("----{inside game()}--Check() was called\n");
	}
	ft_printf("vm->cycles = %d\n", vm->cycles);
	// check_winner() ft_printf("Contestant 1, %s has won !\n", (*vm)->winner);
}

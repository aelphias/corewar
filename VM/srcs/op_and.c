/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_and.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarron <sdarron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 21:29:17 by aelphias          #+#    #+#             */
/*   Updated: 2021/01/17 15:34:28 by sdarron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_and(t_car *car, uint8_t *arena, t_vm *vm)
{
	// int type_arg;
	// int a1;
	// int a2;

	// car->pos = update_pos(car->pos);
	// type_arg = arena[update_pos(car->pos + 1)];
	// a1 = car->reg[update_pos(arena[car->pos + 2])];
	// a2 = car->reg[update_pos(arena[car->pos + 3])];
	// car->reg[update_pos(arena[car->pos + 4])] = a1 & a2;
	// if (car->reg[update_pos(arena[car->pos + 4])] == 0)
	// 	car->carry = 1;
	// else
	// 	car->carry = 0;

	int arg1;
	int arg2;
	int arg3;
	int val;

	arg1 = get_arg(vm, car, 1, arena);
	arg2 = get_arg(vm, car, 2, arena);
	arg3 = get_arg(vm, car, 3, arena);
	val = car->reg[arg1] & car->reg[arg2];
	car->reg[arg3] = val;
	if (val == 0)
		car->carry = 1;
	else
		car->carry = 0;
	car->pos += 3;
}

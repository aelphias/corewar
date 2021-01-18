/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 21:33:27 by aelphias          #+#    #+#             */
/*   Updated: 2021/01/18 15:05:48 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		op_ldi(t_car *car, uint8_t *arena, t_vm *vm)
{
	int arg1;
	int arg2;
	int arg3;
	int new_adr;
	int val;

	arg1 = get_arg(vm, car, 1, arena);
	arg2 = get_arg(vm, car, 2, arena);
	arg3 = get_arg(vm, car, 3, arena);
	new_adr = (arg1 + arg2) % IDX_MOD;
	val = read_int(arena, new_adr, 4);
	car->reg[arg3] = val;
	if (car->arg_type[0] == T_REG)
		car->pos++;
	if (car->arg_type[0] == T_DIR)
	{
		if (car->dir_size_status == 4)
			car->pos += 4;
		if (car->dir_size_status == 2)
			car->pos += 2;
	}
	if (car->arg_type[0] == T_IND)
		car->pos += 4;
	if (car->arg_type[1] == T_REG)
		car->pos++;
	if (car->arg_type[1] == T_DIR)
	{
		if (car->dir_size_status == 4)
			car->pos += 4;
		if (car->dir_size_status == 2)
			car->pos += 2;
	}
	car->pos++;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 21:34:04 by aelphias          #+#    #+#             */
/*   Updated: 2021/01/18 15:04:53 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_sti(t_car *car, uint8_t *arena, t_vm *vm)
{
	int arg1;
	int arg2;
	int arg3;
	int val1;
	int new_adr;

	arg1 = get_arg(vm, car, 1, arena);
	arg2 = get_arg(vm, car, 2, arena);
	arg3 = get_arg(vm, car, 3, arena);
	val1 = car->reg[arg1];
	new_adr = car->pos + (arg2 + arg3) % IDX_MOD;
	put_value_in_arena(arena, new_adr, val1, 4);
	car->pos++;
	if (car->arg_type[1] == T_REG)
		car->pos++;
	if (car->arg_type[1] == T_DIR)
	{
		if (car->dir_size_status == 4)
			car->pos += 4;
		if (car->dir_size_status == 2)
			car->pos += 2;
	}
	if (car->arg_type[1] == T_IND)
		car->pos += 4;
	if (car->arg_type[2] == T_REG)
		car->pos++;
	if (car->arg_type[2] == T_DIR)
	{
		if (car->dir_size_status == 4)
			car->pos += 4;
		if (car->dir_size_status == 2)
			car->pos += 2;
	}
}

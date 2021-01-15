/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarron <sdarron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 22:14:14 by aelphias          #+#    #+#             */
/*   Updated: 2021/01/15 12:47:56 by sdarron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void					op_st(t_car *car, uint8_t *arena, t_vm *vm)
{
	int vel_in_reg1;
	int addr_in_arg2;
	int new_adr;
	int shift;

	new_adr = 0;
	addr_in_arg2 = 0;
	vel_in_reg1 = 0;
	shift = move(car);
	car->reg[update_pos(arena[car->pos + 3])] = vel_in_reg1;
	if (car->arg_type[1] == 1)
	{
		vel_in_reg1 = car->reg[update_pos(arena[car->pos + 2])];
	}
	if (car->arg_type[1] == 3)
	{
		addr_in_arg2 = update_pos(arena[car->pos + 3]);
		new_adr = car->pos + (addr_in_arg2 % IDX_MOD);
		car->reg[new_adr] = vel_in_reg1;
	}
	car->pos += shift;
}

/* 
void					op_st(t_car *car, uint8_t *arena, t_vm *vm)
{
	int p;
	int val1;
	int val2;
	t_vm	*vm1;

	if (arena && car)
	{
		val2 = car->pos + sizeof(t_op) + sizeof(t_arg_type);
		if (car->arg[1] = REG_CODE)
		{
			//val1 = car->reg[byteread((arena, val2 + 
			
			//_arg(car->)))];
		}
		else
		{
			//p = car->pc + ( % IDX_MOD);
		}
		//car->reg[] = val1;
	}
}*/
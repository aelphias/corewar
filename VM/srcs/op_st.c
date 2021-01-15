/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarron <sdarron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 22:14:14 by aelphias          #+#    #+#             */
/*   Updated: 2021/01/15 16:51:31 by sdarron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void					op_st(t_car *car, uint8_t *arena, t_vm *vm)
{
	int val_in_reg1;
	int addr_in_arg2;
	int new_adr;
	int arg1;
	int arg2;
	int shift;

	shift = 0;
	new_adr = 0;
	addr_in_arg2 = 0;
	val_in_reg1 = 0;
	arg1 = get_arg(vm, car, 1, arena);
	ft_printf("arg1 - %d\n", arg1);
	val_in_reg1 = car->reg[arg1];
	ft_printf("val_in_reg1 - %d\n", val_in_reg1);
	if (car->arg_type[1] == 1)
	{
		car->pos++;
		arg2 = get_arg(vm, car, 2, arena);
		ft_printf("arg2 - %d\n", arg2);
		car->reg[arg2] = val_in_reg1;
		ft_printf("vcar->reg[arg2] - %d\n", car->reg[arg2]);
	}
	if (car->arg_type[1] == 3)
	{
		car->pos += 2;
		arg2 = get_arg(vm, car, 2, arena);
		new_adr = car->pos + (arg2 % IDX_MOD);
		// func(arena[new_adr] = val_in_reg1) 
		// побитовая запись на карту
	}
	car->pos++;
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
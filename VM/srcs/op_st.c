/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarron <sdarron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 22:14:14 by aelphias          #+#    #+#             */
/*   Updated: 2021/01/16 16:48:07 by sdarron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		op_st(t_car *car, uint8_t *arena, t_vm *vm)
{
	int		val_in_reg1;
	int		new_adr;
	int		arg1;
	int		arg2;

	new_adr = 0;
	val_in_reg1 = 0;
	arg1 = 0;
	arg1 = get_arg(vm, car, 1, arena);
	val_in_reg1 = car->reg[arg1];
	if (car->arg_type[1] == 1)
	{
		car->pos++;
		arg2 = get_arg(vm, car, 2, arena);
		car->reg[arg2] = val_in_reg1;
	}
	else
	{
		car->pos += 2;
		arg2 = get_arg(vm, car, 2, arena);
		new_adr = car->pos + (arg2 % IDX_MOD);
		put_value_in_arena(arena, new_adr, val_in_reg1, DIR_SIZE);
	}
	car->pos++;
}

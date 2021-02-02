/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 21:34:04 by aelphias          #+#    #+#             */
/*   Updated: 2021/01/31 14:24:01 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	next_op(t_car *car)
{
	car->pc += move(car);
	car->pos = car->pc;
}

void	op_sti(t_car *car, uint8_t *arena)
{
	int value;
	int arg2;
	int arg3;
	int new_adr;

	value = car->reg[(get_arg(car, 1, arena)) - 1];
	walk(car, 1);
	arg2 = get_arg(car, 2, arena);
	if (car->arg_type[1] == T_REG)
	{
		arg2 = car->reg[arg2 - 1];
		walk(car, 1);
	}
	if (car->arg_type[1] == T_DIR || car->arg_type[1] == T_IND)
		walk(car, 2);
	arg3 = get_arg(car, 3, arena);
	if (car->arg_type[2] == T_REG)
	{
		arg3 = car->reg[arg3 - 1];
		walk(car, 1);
	}
	car->arg_type[2] == T_DIR ? walk(car, 2) : 0;
	new_adr = update_pos(car->pc + (arg2 + arg3) % IDX_MOD);
	put_value_in_arena(arena, new_adr, value, 4);
	car->pc = car->pos;
}

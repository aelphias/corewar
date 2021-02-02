/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lldi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 21:36:12 by aelphias          #+#    #+#             */
/*   Updated: 2021/01/30 19:21:13 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	op_lldi(t_car *car, uint8_t *arena)
{
	int arg1;
	int arg2;
	int arg3;
	int new_adr;

	arg1 = get_arg(car, 1, arena);
	if (car->arg_type[0] == T_REG)
	{
		arg1 = car->reg[arg1 - 1];
		car->pos = update_pos(car->pos + 1);
	}
	if (car->arg_type[0] == T_DIR || car->arg_type[0] == T_IND)
		car->pos = update_pos(car->pos + 2);
	arg2 = get_arg(car, 2, arena);
	if (car->arg_type[1] == T_REG)
	{
		arg2 = car->reg[arg2 - 1];
		car->pos = update_pos(car->pos + 1);
	}
	car->arg_type[1] == T_DIR ? walk(car, 2) : 0;
	arg3 = get_arg(car, 3, arena);
	car->pos = update_pos(car->pos + 1);
	new_adr = arg1 + arg2;
	car->reg[arg3 - 1] = read_int(arena, new_adr, 4);
	car->pc = car->pos;
}

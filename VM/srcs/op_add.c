/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharlet <kcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 19:03:32 by gjigglyp          #+#    #+#             */
/*   Updated: 2021/01/25 20:51:07 by kcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** Opcode 4. Take three registries, add the first two, \
** and place the result in thethird, right before modifying the carry.
*/

void	op_add(t_car *car, uint8_t *arena)
{
	int arg1;
	int arg2;
	int arg3;
	int val;
	
	arg1 = get_arg(car, 1, arena);
	car->pos = update_pos(car->pos + 1);
	arg2 = get_arg(car, 2, arena);
	car->pos = update_pos(car->pos + 1);
	arg3 = get_arg(car, 3, arena);
	car->pos = update_pos(car->pos + 1);
	val = car->reg[arg1 - 1] + car->reg[arg2 - 1];
	car->reg[arg3 - 1] = val;
	if (val == 0)
		car->carry = 1;
	else
		car->carry = 0;
	car->pc = car->pos;
}

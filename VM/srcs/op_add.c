/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 19:03:32 by gjigglyp          #+#    #+#             */
/*   Updated: 2021/01/28 19:50:37 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

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

	val = 0;
	arg1 = get_arg(car, 1, arena);
	walk(car, 1);
	arg2 = get_arg(car, 2, arena);
	walk(car, 1);
	arg3 = get_arg(car, 3, arena);
	walk(car, 1);
	if (arg1 && arg2 && arg3)
	{
		val = car->reg[arg1 - 1] + car->reg[arg2 - 1];
		car->reg[arg3 - 1] = val;
		check_carry_status(val, car);
	}
	car->pc = car->pos;
}

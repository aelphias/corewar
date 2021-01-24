/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 19:03:32 by gjigglyp          #+#    #+#             */
/*   Updated: 2021/01/21 21:58:45 by aelphias         ###   ########.fr       */
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
	arg2 = get_arg(car, 2, arena);
	arg3 = get_arg(car, 3, arena);
	val = car->reg[arg1] + car->reg[arg2];
	car->reg[arg3] = val;
	if (val == 0)
		car->carry = 1;
	else
		car->carry = 0;
	car->pos += 3;
	car->pc = car->pos;
}

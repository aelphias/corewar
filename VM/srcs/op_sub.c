/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 21:28:19 by aelphias          #+#    #+#             */
/*   Updated: 2021/01/28 20:14:19 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	op_sub(t_car *car, uint8_t *arena)
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
		val = car->reg[arg1 - 1] - car->reg[arg2 - 1];
		car->reg[arg3 - 1] = val;
		check_carry_status(val, car);
	}
	car->pc = car->pos;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 21:28:19 by aelphias          #+#    #+#             */
/*   Updated: 2021/01/25 21:01:56 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_sub(t_car *car, uint8_t *arena)
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
	val = car->reg[arg1 - 1] - car->reg[arg2 - 1];//  TO_DO обращение к reg через MINUS_ONE
	car->reg[arg3 - 1] = val;
	if (val)
		car->carry = 1;
	else
		car->carry = 0;
	car->pc = car->pos;
}

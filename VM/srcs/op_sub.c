/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 21:28:19 by aelphias          #+#    #+#             */
/*   Updated: 2021/01/23 10:08:46 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_sub(t_car *car, uint8_t *arena)
{
	// int type_arg;
	// int a1;
	// int a2;

	// car->pos = update_pos(car->pos);
	// type_arg = arena[update_pos(car->pos + 1)];
	// a1 = car->reg[update_pos(arena[car->pos + 2])];
	// a2 = car->reg[update_pos(arena[car->pos + 3])];
	// car->reg[update_pos(arena[car->pos + 4])] = a1 - a2;
	// ft_printf("\n ### I'm op_sub! ### \n");
	// ft_printf("\n type_arg %d\n", type_arg);
	// ft_printf("\n type_arg %d\n", a2);
	// ft_printf("\n car->reg[arena[car->pos + 4]] %d\n",\
	// 	car->reg[arena[car->pos + 4]]);
	// ft_printf(" +=5 =%d\n", arena[car->pos]);
	// car->pos += 5;
	
	int arg1;
	int arg2;
	int arg3;
	int val;
	
	arg1 = get_arg(car, 1, arena);
	arg2 = get_arg(car, 2, arena);
	arg3 = get_arg(car, 3, arena);
	val = car->reg[arg1] - car->reg[arg2];//  TO_DO обращение к reg через MINUS_ONE
	car->reg[arg3] = val;
	if (val)
		car->carry = 1;
	else
		car->carry = 0;
	car->pos += 3;
}

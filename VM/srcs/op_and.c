/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_and.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 21:29:17 by aelphias          #+#    #+#             */
/*   Updated: 2021/01/24 15:58:29 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_and(t_car *car, uint8_t *arena)
{
	int arg1;
	int arg2;
	int arg3;
	int val;

	arg1 = get_arg(car, 1, arena);
	arg2 = get_arg(car, 2, arena);
	arg3 = get_arg(car, 3, arena);
	val = car->reg[arg1] & car->reg[arg2];
	car->reg[arg3] = val;
	if (val == 0)
		car->carry = 1;
	else
		car->carry = 0;
	if (car->arg_type[0] == T_REG)
		car->pos++;
	if (car->arg_type[0] == T_DIR)
	{
		if (car->dir_size_status == 4)
			car->pos += 4;
		if (car->dir_size_status == 2)
			car->pos += 2;
	}
	if (car->arg_type[0] == T_IND)
		car->pos += 4;
	if (car->arg_type[1] == T_REG)
		car->pos++;
	if (car->arg_type[1] == T_DIR)
	{
		if (car->dir_size_status == 4)
			car->pos += 4;
		if (car->dir_size_status == 2)
			car->pos += 2;
	}
	if (car->arg_type[1] == T_IND)
		car->pos += 4;
	car->pos++;
	car->pc = car->pos;
}

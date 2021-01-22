/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 21:26:06 by aelphias          #+#    #+#             */
/*   Updated: 2021/01/22 21:53:22 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int		check_carry_status(int val, t_car *car)
{
	if (val == 0)
		car->carry = 1;
	else
		car->carry = 0;
}

void			op_ld(t_car *car, uint8_t *arena)
{
	int		val;
	int		num_reg;

	val = 0;
	num_reg = 0;
	if (car->arg_type[0] == DIR_CODE)
	{
		val = get_arg(car, 1, arena);
		car->pos = update_pos(car->pos + 4);
		num_reg = get_arg(car, 2, arena);
		car->reg[MINUS_ONE(num_reg)] = val;
		check_carry_status(car->reg[MINUS_ONE(num_reg)], car);
		car->pos = update_pos(car->pos + 1);
	}
	else if (car->arg_type[0] == IND_CODE)
	{
		val = get_arg(car, 1, arena);
		car->pos = update_pos(car->pos + 2);
		num_reg = get_arg(car, 2, arena);
 		car->reg[MINUS_ONE(num_reg)] = val;
		check_carry_status(car->reg[MINUS_ONE(num_reg)], car);
		car->pos = update_pos(car->pos + 1);
	}
	else
		car->pos = update_pos(car->pos++);
}

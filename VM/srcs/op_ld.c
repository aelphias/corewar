/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 21:26:06 by aelphias          #+#    #+#             */
/*   Updated: 2021/01/24 19:41:34 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			check_carry_status(int val, t_car *car)
{
	if (val == 0)
		car->carry = 1;
	else
		car->carry = 0;
}

void			op_ld(t_car *car, uint8_t *arena)
{
	t_op_ld		ld;

	ft_bzero(&ld, sizeof(t_op_ld));
	if (car->arg_type[0] == DIR_CODE)
	{
		ld.val = get_arg(car, 1, arena);
		car->pos = update_pos(car->pos + 4);
		ld.num_reg = get_arg(car, 2, arena);
		car->reg[MINUS_ONE(ld.num_reg)] = ld.val;
		check_carry_status(car->reg[MINUS_ONE(ld.num_reg)], car);
		car->pos = update_pos(car->pos + 1);
	}
	else if (car->arg_type[0] == IND_CODE)
	{
		ld.val = get_arg(car, 1, arena);
		ld.num_reg = get_arg(car, 2, arena);
		check_carry_status(car->reg[MINUS_ONE(ld.num_reg)], car);
		car->reg[MINUS_ONE(ld.num_reg)] = ld.val;
		car->pos = update_pos(car->pos + 3);
	}
	else
		car->pos = update_pos(car->pos + 1);
	car->pc = car->pos;
}
 
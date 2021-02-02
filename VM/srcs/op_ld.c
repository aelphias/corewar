/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 21:26:06 by aelphias          #+#    #+#             */
/*   Updated: 2021/01/31 18:29:09 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void			op_ld(t_car *car, uint8_t *arena)
{
	t_op_ld		ld;

	ft_bzero(&ld, sizeof(t_op_ld));
	if (car->arg_type[0] == T_DIR)
	{
		ld.val = get_arg(car, 1, arena);
		car->pos = update_pos(car->pos + 4);
		ld.num_reg = get_arg(car, 2, arena);
		car->reg[MINUS_ONE(ld.num_reg)] = ld.val;
		check_carry_status(car->reg[MINUS_ONE(ld.num_reg)], car);
		walk(car, 1);
	}
	else if (car->arg_type[0] == T_IND)
	{
		ld.val = get_arg(car, 1, arena);
		walk(car, 2);
		ld.num_reg = get_arg(car, 2, arena);
		car->reg[MINUS_ONE(ld.num_reg)] = ld.val;
		check_carry_status(ld.val, car);
		walk(car, 1);
	}
	else
		car->pos = update_pos(car->pos + 1);
	car->pc = car->pos;
}

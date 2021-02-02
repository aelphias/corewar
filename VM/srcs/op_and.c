/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_and.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 21:29:17 by aelphias          #+#    #+#             */
/*   Updated: 2021/01/30 19:21:13 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	op_and(t_car *car, uint8_t *arena)
{
	t_op_and and;

	ft_bzero(&and, sizeof(t_op_and));
	and.arg1 = get_arg(car, 1, arena);
	if (car->arg_type[0] == T_REG)
	{
		and.arg1 = car->reg[and.arg1 - 1];
		walk(car, 1);
	}
	car->arg_type[0] == T_DIR ? walk(car, 4) : 0;
	car->arg_type[0] == T_IND ? walk(car, 2) : 0;
	and.arg2 = get_arg(car, 2, arena);
	op_and_1(&and, car, arena);
	check_carry_status(and.val, car);
}

void	op_and_1(t_op_and *and, t_car *car, uint8_t *arena)
{
	if (car->arg_type[1] == T_REG)
	{
		and->arg2 = car->reg[and->arg2 - 1];
		walk(car, 1);
	}
	car->arg_type[1] == T_DIR ? walk(car, 4) : 0;
	car->arg_type[1] == T_IND ? walk(car, 2) : 0;
	and->arg3 = get_arg(car, 3, arena);
	walk(car, 1);
	and->val = and->arg1 & and->arg2;
	car->reg[and->arg3 - 1] = and->val;
	car->pc = car->pos;
}

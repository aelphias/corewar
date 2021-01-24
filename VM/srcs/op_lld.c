/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 21:35:37 by aelphias          #+#    #+#             */
/*   Updated: 2021/01/21 21:58:45 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_lld(t_car *car, uint8_t *arena)
{
	int		arg1;
	int		arg2;
	int		addr;

	arg2 = get_arg(car, 2, arena);
	if (car->arg_type[0] == T_DIR)
		arg1 = get_arg(car, 1, arena);
	if (car->arg_type[0] == T_IND)
	{
		addr = read_int(arena, car->pos, IND_SIZE);
		arg1 = read_int(arena, car->pos + addr, DIR_SIZE);
	}
	car->reg[arg2] = arg1;
	if (car->reg[arg2] == 0)
		car->carry = 1;
	else
		car->carry = 0;
	if (car->arg_type[0] == T_DIR)
	{
		if (car->dir_size_status == 4)
			car->pos += 5;
		if (car->dir_size_status == 2)
			car->pos += 3;
	}
	if (car->arg_type[0] == T_IND)
		car->pos += 5;
	car->pc = car->pos;
}

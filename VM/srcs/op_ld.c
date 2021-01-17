/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarron <sdarron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 21:26:06 by aelphias          #+#    #+#             */
/*   Updated: 2021/01/16 20:36:53 by sdarron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_ld(t_car *car, uint8_t *arena, t_vm *vm)
{
	// int type_arg;
	// int a1;
	// int a2;

	// car->pos = update_pos(car->pos);
	// type_arg = arena[update_pos(car->pos + 1)];
	// a1 = car->reg[update_pos(arena[car->pos + 2])];
	// a2 = car->reg[update_pos(arena[car->pos + 3])];
	// if (a1 == T_DIR)
	// 	car->reg[update_pos(arena[car->pos + 4])] = a2;
	// else if ((a1 = T_IND))
	// 	car->reg[update_pos(arena[car->pos + 4])] = a1 % IDX_MOD;
	// printf("\n ### I'm op_ld! ### \n");
	// printf("\n type_arg %d\n", type_arg);
	// printf("\n type_arg %d\n", a2);
	// printf("\n car->reg[arena[car->pos + 4]] %d\n", car->reg[arena[car->pos + 4]]);
	// printf(" +=5 =%d\n", arena[car->pos]);
	// car->pos += 5;

	int		arg1;
	int		arg2;

	arg2 = get_arg(vm, car, 2, arena);
	arg1 = get_arg(vm, car, 1, arena);
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
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 21:35:37 by aelphias          #+#    #+#             */
/*   Updated: 2021/01/12 20:51:35 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_lld(t_car *car, uint8_t *arena, t_vm *vm)
{
	int type_arg;
	int arg1;
	int arg2;

	car->position = update_pos(car->position);
	type_arg = arena[update_pos(car->position + 1)];
	arg1 = car->reg[update_pos(arena[car->position + 2])];
	arg2 = car->reg[update_pos(arena[car->position + 3])];
	if (arg1 == T_DIR)
		car->reg[update_pos(arena[car->position + 4])] = arg2;
	else if ((arg1 = T_IND))
		car->reg[update_pos(arena[car->position + 4])] = car->position + arg1;
	printf("\n ### I'm op_lld! ### \n");
	printf("\n type_arg %d\n", type_arg);
	printf("\n type_arg %d\n", arg2);
	printf("\n car->reg[arena[car->position + 4]] %d\n", car->reg[arena[car->position + 4]]);
	printf(" +=5 =%d\n", arena[car->position]);
	car->position += 5;
}

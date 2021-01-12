/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_or.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 21:30:20 by aelphias          #+#    #+#             */
/*   Updated: 2021/01/11 21:31:42 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_or(t_car *car, uint8_t *arena, t_vm *vm)
{
	int type_arg;
	int arg1;
	int arg2;

	car->position = update_pos(car->position);
	type_arg = arena[update_pos(car->position + 1)];
	arg1 = car->reg[update_pos(arena[car->position + 2])];
	arg2 = car->reg[update_pos(arena[car->position + 3])];
	car->reg[update_pos(arena[car->position + 4])] = arg1 | arg2;
	if (car->reg[update_pos(arena[car->position + 4])] == 0)
		car->carry = 1;
	else
		car->carry = 0;
}

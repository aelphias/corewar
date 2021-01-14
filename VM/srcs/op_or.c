/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_or.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 21:30:20 by aelphias          #+#    #+#             */
/*   Updated: 2021/01/14 14:53:21 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_or(t_car *car, uint8_t *arena, t_vm *vm)
{
	int type_arg;
	int a1;
	int a2;

	car->pos = update_pos(car->pos);
	type_arg = arena[update_pos(car->pos + 1)];
	a1 = car->reg[update_pos(arena[car->pos + 2])];
	a2 = car->reg[update_pos(arena[car->pos + 3])];
	car->reg[update_pos(arena[car->pos + 4])] = a1 | a2;
	if (car->reg[update_pos(arena[car->pos + 4])] == 0)
		car->carry = 1;
	else
		car->carry = 0;
}

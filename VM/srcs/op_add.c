/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 19:03:32 by gjigglyp          #+#    #+#             */
/*   Updated: 2021/01/14 18:25:38 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** Opcode 4. Take three registries, add the first two, \
** and place the result in thethird, right before modifying the carry.
*/

void	op_add(t_car *car, uint8_t *arena, t_vm *vm)
{
	int type_arg;
	int a1;
	int a2;

	vm->dump = vm->dump;
	car->pos = update_pos(car->pos);   //?
	type_arg = arena[update_pos(car->pos + 1)];
	a1 = car->reg[update_pos(arena[car->pos + 2])];
	a2 = car->reg[update_pos(arena[car->pos + 3])];
	car->reg[update_pos(arena[car->pos + 4])] = a1 + a2;
	ft_printf("\n ### I'm op_add! ### \n");
	ft_printf("\n type_arg %d\n", type_arg);
	ft_printf("\n type_arg %d\n", a2);
	ft_printf("\n car->reg[arena[car->pos + 4]] %d\n", \
		car->reg[arena[update_pos(car->pos + 4)]]);
	ft_printf(" +=5 =%d\n", arena[update_pos(car->pos)]);
	car->pos += 5;
}

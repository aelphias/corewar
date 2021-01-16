/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 19:03:32 by gjigglyp          #+#    #+#             */
/*   Updated: 2021/01/16 15:47:42 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** Opcode 4. Take three registries, add the first two, \
** and place the result in thethird, right before modifying the carry.
*/

void	op_add(t_car *car, uint8_t *arena, t_vm *vm)
{
	int arg1;
	int arg2;
		
	/* //arg1
	arg1 = get_arg(vm, car, 1);
	arg1 = car->reg[update_pos(arena[car->pos + 2])];
	arg2 = car->reg[update_pos(arena[car->pos + 3])];
	car->reg[update_pos(arena[car->pos + 4])] = arg1 + arg2;
	ft_printf("\n ### I'm op_add! ### \n");
	ft_printf("\n type_arg %d\n", type_arg);
	ft_printf("\n type_arg %d\n", a2);
	ft_printf("\n car->reg[arena[car->pos + 4]] %d\n", \
		car->reg[arena[update_pos(car->pos + 4)]]);
	ft_printf(" +=5 =%d\n", arena[update_pos(car->pos)]);
	car->pos += 5; */
}

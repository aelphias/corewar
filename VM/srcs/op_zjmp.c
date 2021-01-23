/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 21:32:30 by aelphias          #+#    #+#             */
/*   Updated: 2021/01/21 21:58:45 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_zjmp(t_car *car, uint8_t *arena)
{
	// int type_arg;
	// int a1;
	// int silence_gcc;

	// car->pos = update_pos(car->pos);
	// type_arg = arena[update_pos(car->pos + 1)];
	// a1 = car->dir_size_status;
	// silence_gcc = car->reg[update_pos(arena[car->pos + 2])];
	int arg;

	arg = get_arg(car, 1, arena);
	if (car->carry == 1)
		car->pos = car->pos + (arg % IDX_MOD);
}

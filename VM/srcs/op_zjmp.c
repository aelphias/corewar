/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 21:32:30 by aelphias          #+#    #+#             */
/*   Updated: 2021/01/14 14:53:15 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_zjmp(t_car *car, uint8_t *arena, t_vm *vm)
{
	int type_arg;
	int a1;
	int silence_gcc;
	
	car->pos = update_pos(car->pos);
	type_arg = arena[update_pos(car->pos + 1)];
	a1 = car->dir_size_status;
	silence_gcc = car->reg[update_pos(arena[car->pos + 2])];
}

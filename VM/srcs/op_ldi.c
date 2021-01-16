/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarron <sdarron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 21:33:27 by aelphias          #+#    #+#             */
/*   Updated: 2021/01/16 17:24:22 by sdarron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		op_ldi(t_car *car, uint8_t *arena, t_vm *vm)
{
	int arg1;
	int arg2;
	int arg3;
	int new_adr;
	int val;

	arg1 = get_arg(vm, car, 1, arena);
	arg2 = get_arg(vm, car, 2, arena);
	arg3 = get_arg(vm, car, 3, arena);

	new_adr = (arg1 + arg2) % IDX_MOD;
	val = read_int(arena, new_adr, 4);
	car->reg[arg3] = val;
	
}

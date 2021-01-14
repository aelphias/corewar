/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 12:14:08 by aelphias          #+#    #+#             */
/*   Updated: 2021/01/14 10:32:09 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	~	bitwise NOT (one's complement) (unary), flips every bit.
**	^	bitwise XOR (exclusive OR)
*/

int		read_int(const uint8_t *arena, int addr, int size)
{
	int		result;
	bool		sign;
	int			i;

	result = 0;
	sign = (bool)(arena[update_pos(addr)] & 128);
	i = 0;
	while (size)
	{
		if (sign)
			result += ((arena[update_pos(addr + size - 1)] ^ 255) << (i++ * 8));
		else
			result += arena[update_pos(addr + size - 1)] << (i++ * 8);
		size--;
	}
	if (sign)
		result = ~(result);
	return (result);
}

int		get_arg(t_vm *vm, t_car *car, int arg_number, uint8_t *arena)
{
	t_op	*op;
	int		value;
	int		addr;

	op = &g_op[MINUS_ONE(car->op_code)];
	value = 0;
	if (car->arg_type[MINUS_ONE(arg_number)] & T_REG)
		value = car->reg[MINUS_ONE(get_byte(arena, car))];
	/* else if (car->arg_type[MINUS_ONE(arg_number)] & T_DIR)
		value = read_int(arena, car->pos + car->move, op->dir_size_status);
	else if (car->arg_type[MINUS_ONE(arg_number)] & T_IND)
	{
		addr = read_int(arena,car->pos + car->move, IND_SIZE);
		value = read_int(arena, car->pos + (mod ? (addr % IDX_MOD) : addr),
							DIR_SIZE);
	}
	car->move += step_size(car->arg_type[MINUS_ONE(arg_number)], op); */
	return (value);
}
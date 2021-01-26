/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 12:14:08 by aelphias          #+#    #+#             */
/*   Updated: 2021/01/25 12:47:44 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	~	bitwise NOT (one's complement) (unary), flips every bit.
**	^	bitwise XOR (exclusive OR)
*/

int		read_int(const uint8_t *arena, int pos, int size)
{
	int		result;
	bool		sign;
	int			i;

	result = 0;
	
	sign = (bool)(arena[update_pos(pos)] & 128);
	i = 0;
	while (size)
	{
		if (sign)
			result += ((arena[update_pos(pos + size - 1)] ^ 255) << (i++ * 8));
		else
			result += arena[update_pos(pos + size - 1)] << (i++ * 8);
		size--;
	}
	if (sign)
		result = ~(result);
	return (result);
}

int		 get_arg(t_car *car, int arg_number, uint8_t *arena)
{
	t_op		*op;
	long int	value;
	int			addr;

	addr = 0;
	value = 0;
	op = &g_op[MINUS_ONE(car->op_code)];
	if (car->arg_type[MINUS_ONE(arg_number)] == REG_CODE)
		value = get_byte(arena, car);
	else if (car->arg_type[MINUS_ONE(arg_number)] == DIR_CODE)
		value = read_int(arena, car->pos, car->dir_size_status); //car->dir_size_status changed from op->dir_size_status - 25.01.2021
	else if (car->arg_type[MINUS_ONE(arg_number)] == IND_CODE)
	{
		addr = read_int(arena, car->pos, IND_SIZE);
		addr = update_pos(car->pc + (addr % IDX_MOD));
		value = read_int(arena, addr, car->dir_size_status); //to check car->dir_size_status
	}
	return (value);
}

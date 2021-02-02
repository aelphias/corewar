/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 12:14:08 by aelphias          #+#    #+#             */
/*   Updated: 2021/01/31 19:27:45 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

/*
**	~	bitwise NOT (one's complement) (unary), flips every bit.
**	^	bitwise XOR (exclusive OR)
*/

int				read_int(const uint8_t *arena, int pos, int size)
{
	int			result;
	t_bool		sign;
	int			i;

	result = 0;
	sign = (t_bool)(arena[update_pos(pos)] & 128);
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

int				get_arg(t_car *car, int arg_number, uint8_t *arena)
{
	int32_t			value;
	int				addr;

	addr = 0;
	value = 0;
	if (car->arg_type[MINUS_ONE(arg_number)] == T_REG)
		value = get_byte(arena, car);
	else if (car->arg_type[MINUS_ONE(arg_number)] == T_DIR)
		value = read_int(arena, car->pos, car->dir_size_status);
	else if (car->arg_type[MINUS_ONE(arg_number)] == T_IND)
	{
		addr = read_int(arena, car->pos, IND_SIZE);
		addr = update_pos(car->pc + (addr % IDX_MOD));
		value = read_int(arena, addr, DIR_SIZE);
	}
	return (value);
}

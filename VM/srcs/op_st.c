/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 22:14:14 by aelphias          #+#    #+#             */
/*   Updated: 2021/01/30 20:46:45 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

/*
**	st: take a registry and a registry or an indirect and store the value of the
**	registry toward a second argument. Its opcode is 0x03. For example,st r1,
**	42store thevalue of r1 at the address (PC + (42 % IDX_MOD))
*/

void		op_st(t_car *car, uint8_t *arena)
{
	int		value;
	int		new_adr;
	int		destination;

	new_adr = 0;
	value = 0;
	destination = 0;
	value = car->reg[MINUS_ONE(get_arg(car, 1, arena))];
	car->pos = update_pos(car->pos + 1);
	if (car->arg_type[1] == T_REG)
	{
		destination = get_arg(car, 2, arena);
		car->reg[MINUS_ONE(destination)] = value;
		car->pos = update_pos(car->pos + 1);
	}
	else if (car->arg_type[1] == T_IND)
	{
		destination = read_int(arena, update_pos(car->pos), IND_SIZE);
		new_adr = update_pos(car->pc + (destination % IDX_MOD));
		put_value_in_arena(arena, new_adr, value, DIR_SIZE);
		car->pos = update_pos(car->pos + 2);
	}
	car->pc = car->pos;
}

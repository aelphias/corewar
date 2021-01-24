/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 22:14:14 by aelphias          #+#    #+#             */
/*   Updated: 2021/01/24 11:30:12 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		op_st(t_car *car, uint8_t *arena)
{
	int		val_in_reg1;
	int		new_adr;
	int		arg1;
	int		arg2;
	
	new_adr = 0;
	val_in_reg1 = 0;
	arg1 = 0;
	arg2 = 0;
	arg1 = get_arg(car, 1, arena);
	val_in_reg1 = car->reg[MINUS_ONE(arg1)];
	if (car->arg_type[1] == REG_CODE)
	{
		car->pos = update_pos(car->pos + 1);
		arg2 = get_arg(car, 2, arena);
		car->reg[MINUS_ONE(arg2)] = val_in_reg1;
	}
	else if(car->arg_type[1] == IND_CODE)
	{
		car->pos = update_pos(car->pos + 2);
		arg2 = get_arg(car, 2, arena);
		new_adr = update_pos(car->pos + (arg2 % IDX_MOD)); //check +1 here
		put_value_in_arena(arena, new_adr, val_in_reg1, DIR_SIZE);
	}
	car->pos = update_pos(car->pos + 1);
	car->pc = car->pos;
}


/*
		Testing
		

	use with following code in .s file:
	st r2, 1
	<------------------
car->reg[MINUS_ONE(2)]= 3;
	arena[11] = 4;
	dump(arena);
	arena[11] = 4;
	car->reg[MINUS_ONE(2)] = 42;
	printf(" LOADED car->reg[MINUS_ONE(2)]=%d\n",car->reg[MINUS_ONE(2)]);


 */
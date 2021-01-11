/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 18:19:27 by kcharlet          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/01/11 20:21:31 by aelphias         ###   ########.fr       */
=======
/*   Updated: 2021/01/11 19:16:57 by gjigglyp         ###   ########.fr       */
>>>>>>> 235c732c07924deab7bd693eceb792d81ff2e855
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	get_dir(t_car *car, unsigned char *arena, t_op *op)
{
	bool silence_make;
	if (arena && car)
	{
		silence_make = car->carry;
		op->cycles_wait =	op->cycles_wait;
		
	}
}


/* 
* 1  0000 0001
# 2  0000 0010
# 3  0000 0011
*/

/* 
# define REG_CODE				1
# define DIR_CODE				2
# define IND_CODE				3 */


/* 	int			bit_mask;
	if (stand == 1)
		bit_mask = 192;
	else
		(stand == 2) ? (bit_mask = 48)
			: (bit_mask = 12);
	if ((size & bit_mask) == (bit_mask - (bit_mask / 3)))
		return (3);
	if ((size & bit_mask) == bit_mask)
		return (2);
	if ((size & bit_mask) == (bit_mask / 3))
		return (1);
	return (0);
	
 */

void	set_args_types(unit, t_car *car, int ind)
{

}


void	get_args(t_car *car, unsigned char *arena, t_op *op)
{
	uint8_t index;
	
	if (car->args_types_code)
	{
		car->position++;
		index = get_byte(arena, car->position);
		if (op->args_amount >= 1)
			set_arg_type((int8_t)((index & 192) >> 6), 1, car);
		if (op->args_amount >= 2)
			set_arg_type((int8_t)((index & 48) >> 4), 2, car);
		if (op->args_amount >= 3)
			set_arg_type((int8_t)((index & 12) >> 2), 3, car);
		//get_args_types(get_byte(arena, car->position));
		
		printf("---->get_args is here, darling!\n");
	}
	 else
		get_dir(arena, car); 
}

////////////////////////////////////////

static void	set_arg_type(int8_t arg_type, int8_t index, t_cursor *cursor)
{
	cursor->args_types[INDEX(index)] = g_arg_code[INDEX(arg_type)];
}

void		parse_types_code(t_vm *vm, t_cursor *cursor, t_op *op)
{
	int8_t args_types_code;

	if (op->args_types_code)
	{
		args_types_code = get_byte(vm, cursor->pc, 1);
		if (op->args_num >= 1)
			set_arg_type((int8_t)((args_types_code & 0xC0) >> 6), 1, cursor);
		if (op->args_num >= 2)
			set_arg_type((int8_t)((args_types_code & 0x30) >> 4), 2, cursor);
		if (op->args_num >= 3)
			set_arg_type((int8_t)((args_types_code & 0xC) >> 2), 3, cursor);
	}
	else
		cursor->args_types[0] = op->args_types[0];
}

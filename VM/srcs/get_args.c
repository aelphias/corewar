/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 18:19:27 by kcharlet          #+#    #+#             */
/*   Updated: 2021/01/11 23:05:54 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"




/* 
* 1  0000 0001
# 2  0000 0010
# 3  0000 0011
*/

/* 
# define REG_CODE				1
# define DIR_CODE				2
# define IND_CODE				3 */

/* 
	int			bit_mask;
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


/* int		chk_arg_type(t_op op, t_carrage *carrage, unsigned char *arena)
{
	int		i;
	int		arg_type;

	i = -1;
	if (op.is_arg_code)
	{
		arg_type = read_byte(arena, carrage->pc + sizeof(t_op_type));
		carrage->op_args[0] = op.n_arg >= 1 ? (arg_type & 0b11000000) >> 6 : 0;
		carrage->op_args[1] = op.n_arg >= 2 ? (arg_type & 0b00110000) >> 4 : 0;
		carrage->op_args[2] = op.n_arg >= 3 ? (arg_type & 0b00001100) >> 2 : 0;
		while (++i < op.n_arg)
			if (!(op.args[i] & carrage->op_args[i]))
				return (0);
	}
	else
		while (++i < op.n_arg)
		{
			if (op.args[i] == T_REG)
				carrage->op_args[i] = REG_CODE;
			else if (op.args[i] == T_DIR)
				carrage->op_args[i] = DIR_CODE;
			else
				carrage->op_args[i] = IND_CODE;
		}
	return chk_regs(op, carrage, arena);
} */

/* int		chk_regs(t_op op, t_carrage *carrage, unsigned char *arena)
{
	int				offset;
	unsigned char	reg;
	int				i;

	offset = sizeof(t_op_type) + op.is_arg_code ? sizeof(t_arg_type) : 0;
	i = 0;
	while (i < op.n_arg)
	{
		if (carrage->op_args[i] == REG_CODE &&
			((reg = read_byte(arena, carrage->pc + ++offset)) < 1 || reg > REG_NUMBER))
				return (0);
		offset += get_arg_size(op.is_half_size_dir, carrage->op_args[i++]);
	}
	return (offset);
} */

void	get_args(t_car *car, unsigned char *arena, t_op *op)
{
	int		i;
	int		arg_type;
	printf("________-get_args\n");
	i = 0;
	if (car->args_types_code)
	{
		arg_type = get_byte(arena, car->position);
		car->arg_type[0] = op->args_amount >= 1 ? (arg_type & 0b11000000) >> 6 : 0;
		car->arg_type[1] = op->args_amount >= 2 ? (arg_type & 0b00110000) >> 4 : 0;
		car->arg_type[2] = op->args_amount >= 3 ? (arg_type & 0b00001100) >> 2 : 0;
		while (i < op->args_amount)
		{
			if (!(op->args_types[i] & car->arg_type[i]))
			i++;
		}
			//return (0);
	}
	else
		while (++i < (op->args_amount))
		{
			if (op->args_types[i] == T_REG)
				car->arg_type[i] = REG_CODE;
			else if (op->args_types[i] == T_DIR)
				car->arg_type[i] = T_DIR;
			else
				car->arg_type[i] = IND_CODE;
		}

		i = 0;

		while (i < 3)
	{
		printf("arr[i]%d \n", car->arg_type[i]);
		i++;
	}
		printf("<-->\n");
}
	





















/* void	write_arg_type(uint8_t arg_type, uint8_t ind, t_car *car)
{
	int i = 0;
	if (ind == 1)
		car->arg_type[MINUS_ONE(ind)] = REG_CODE;
	if (ind == 2)
		car->arg_type[MINUS_ONE(ind)] = DIR_CODE;
	if (ind == 3)
		car->arg_type[MINUS_ONE(ind)] = IND_CODE;
	while (i < 3)
	{
		printf("arr[i]%d \n", car->arg_type[i]);
		i++;
	}
		printf("<-->\n");
}


void	get_args(t_car *car, unsigned char *arena, t_op *op)
{
	uint8_t index;
	
	if (car->args_types_code)
	{
		car->position++;
		index = get_byte(arena, car->position);
		if (op->args_amount >= 1)
			write_arg_type((int8_t)((index & 192) >> 6), 1, car); 
		else if (op->args_amount >= 2)
			write_arg_type((int8_t)((index & 48) >> 4), 2, car);
		else if (op->args_amount >= 3)
			write_arg_type((int8_t)((index & 12) >> 2), 3, car);
		printf("---->get_args is here, darling!\n");
	}
	 else
		car->arg_type[0] = op->args_types[0];
}
 */
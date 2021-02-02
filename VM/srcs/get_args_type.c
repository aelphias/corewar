/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 18:19:27 by kcharlet          #+#    #+#             */
/*   Updated: 2021/01/31 19:12:01 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

int					get_arg_size(int is_half_sized_dir, int type)
{
	if (type == T_REG)
		return (1);
	else if (type == T_IND)
		return (IND_SIZE);
	else if (type == T_DIR)
		return (is_half_sized_dir == 2) ? 2 : DIR_SIZE;
	else
		return (0);
}

void				write_arg_type(int arg_type, t_car *car, int ind)
{
	car->arg_type[MINUS_ONE(ind)] = arg_type;
}

uint8_t				read_byte_for_check_reg(uint8_t *arena, int pos)
{
	while (pos < 0)
		pos += MEM_SIZE;
	return (arena[pos %= MEM_SIZE]);
}

int					check_reg(t_op *op, t_car *car, uint8_t *arena)
{
	int				offset;
	uint8_t			reg;
	unsigned int	i;

	if (car->is_type_code)
		offset = car->pos + 1;
	else
		offset = car->pos;
	i = 0;
	while (i < op->args_amount)
	{
		if (car->arg_type[i] == T_REG)
		{
			reg = read_byte_for_check_reg(arena, offset);
			if (reg < 1 || reg > REG_NUMBER)
				return (0);
		}
		offset += get_arg_size(op->dir_size_status, car->arg_type[i++]);
	}
	return (1);
}

int					get_args_type(t_car *car, uint8_t *arena, t_op *op)
{
	unsigned int		i;
	int					arg_type;
	int					res;

	i = -1;
	res = 1;
	arg_type = 0;
	if (car->is_type_code)
	{
		walk(car, 1);
		arg_type = get_byte(arena, car);
		if (op->args_amount >= 1)
			write_arg_type(((arg_type & 0b11000000) >> 6 << 2) / 3, car, 1);
		if (op->args_amount >= 2)
			write_arg_type(((arg_type & 0b00110000) >> 4 << 2) / 3, car, 2);
		if (op->args_amount >= 3)
			write_arg_type(((arg_type & 0b00001100) >> 2 << 2) / 3, car, 3);
		while (++i < (op->args_amount - 1))
			if (!(op->args_types[i] & car->arg_type[i]))
				return (0);
		res = check_reg(op, car, arena);
	}
	else
		car->arg_type[0] = T_DIR;
	return (res);
}

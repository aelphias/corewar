/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 18:19:27 by kcharlet          #+#    #+#             */
/*   Updated: 2021/01/24 19:04:33 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

 void	write_arg_type(int arg_type, t_car *car, int ind)
{
	//op->code = op->code; // TODO: what should be here?
	if (arg_type == 1 || arg_type == 2 || arg_type == 3)
		car->arg_type[MINUS_ONE(ind)] = arg_type;
	else
		car->arg_type[MINUS_ONE(ind)] = 0;
}

void	get_args_type(t_car *car, unsigned char *arena, t_op *op)
{
	int		i;
	int		arg_type;

	i = 0;
	arg_type = 0;
	if (car->is_type_code)
	{
		car->pos = update_pos(++car->pos);
		arg_type = get_byte(arena, car);
		if (op->args_amount >= 1)
			write_arg_type((arg_type & 0b11000000) >> 6, car, 1);
		if (op->args_amount >= 2)
			write_arg_type((arg_type & 0b00110000) >> 4, car, 2);
		if (op->args_amount >= 3)
			write_arg_type((arg_type & 0b00001100) >> 2, car, 3);
	}
	else
	{
		car->arg_type[0] = DIR_CODE;
		//car->arg_type[0] = op->args_types[0] == DIR_CODE;
	}
}

/* 
** нужна проветка на подавемые аргументы
*/

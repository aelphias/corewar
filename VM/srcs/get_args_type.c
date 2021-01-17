/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 18:19:27 by kcharlet          #+#    #+#             */
/*   Updated: 2021/01/17 00:03:06 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

 void	write_arg_type(int arg_type, t_car *car, t_op *op, int ind)
{
	op->code = op->code; // TODO: what should be here?
	car->arg_type[MINUS_ONE(ind)] = arg_type;
}

void	get_args_type(t_car *car, unsigned char *arena, t_op *op)
{
	int		i;
	int		arg_type;

	i = 0;
	if (car->is_type_code)
	{
		car->pos++;
		arg_type = get_byte(arena, car);
		
		if (op->args_amount >= 1)
			write_arg_type((arg_type & 192) >> 6, car, op, 1);
		if (op->args_amount >= 2)
			write_arg_type((arg_type & 48) >> 4, car, op, 2);
		if (op->args_amount >= 3)
			write_arg_type((arg_type & 12) >> 2, car, op, 3);
	}
	else
		car->arg_type[0] = T_DIR;
}

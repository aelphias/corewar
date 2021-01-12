/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 18:19:27 by kcharlet          #+#    #+#             */
/*   Updated: 2021/01/12 17:50:26 by gjigglyp         ###   ########.fr       */
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


 void	write_arg_type(int arg_type, int ind, t_car *car, t_op *op)
{
	int i = 0;
	if (ind == 1)
		car->arg_type[MINUS_ONE(ind)] = op->args_types[MINUS_ONE(ind)];
	if (ind == 2)
		car->arg_type[MINUS_ONE(ind)] = op->args_types[MINUS_ONE(ind)];
	if (ind == 3)
		car->arg_type[MINUS_ONE(ind)] = op->args_types[MINUS_ONE(ind)];
	while (i < 3)
	{
		printf("arr[i]%d \n", car->arg_type[i]);
		i++;
	}
		printf("<-->\n");
}

void	get_args(t_car *car, unsigned char *arena, t_op *op)
{
	int		i;
	int		arg_type;

	i = 0;
	if (car->is_type_code)
	{
		car->position++;
		arg_type = get_byte(arena, car->position);

		printf("arg_type_code------------>%d\n", arg_type);
		if (op->args_amount >= 1)
			write_arg_type((int)((arg_type & 192) >> 6), 1, car,op);
		if (op->args_amount >= 2)
			write_arg_type((int)((arg_type & 48) >> 4), 2, car, op);
		if (op->args_amount >= 3)
			write_arg_type((int)((arg_type & 12) >> 2), 3, car, op);
	}
	else
		car->arg_type[0] = op->args_types[0];
}

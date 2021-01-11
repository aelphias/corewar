/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 18:19:27 by kcharlet          #+#    #+#             */
/*   Updated: 2021/01/11 20:42:13 by aelphias         ###   ########.fr       */
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

void	write_args_types(uint8_t arg_type, uint8_t ind, t_car *car)
{
	int i = 0;
	if (ind == 1)
		car->arg_type[ind] = REG_CODE;
	if (ind == 2)
		car->arg_type[ind] = DIR_CODE;
	if (ind == 3)
		car->arg_type[ind] = IND_CODE;
	while (i < 3)
		printf("arr[i]%d ", car->arg_type[i++]);
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
		if (op->args_amount >= 2)
			write_arg_type((int8_t)((index & 48) >> 4), 2, car);
		if (op->args_amount >= 3)
			write_arg_type((int8_t)((index & 12) >> 2), 3, car);
		printf("---->get_args is here, darling!\n");
	}
	 else
		car->arg_type[0] = op->args_types[0];
}
